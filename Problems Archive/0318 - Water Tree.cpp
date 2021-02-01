#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct StVal { // define
	int m = 0; StVal() {}
	StVal(const StVal &v1, const StVal &v2) { m = max(v1, v2); }
	operator int() const { return m; } // optional
};

struct StUpdate { // define
	int v = 0; bool b = false;
	StUpdate() {}
	StUpdate(int _v, bool _b) :v(_v), b(_b) {}
	StUpdate(const StUpdate &u1, const StUpdate &u2) { 
		v = (u2.b) ? u2 : u1;
		b = (u2.b) ? u2.b : u1.b;
	}
	operator int() const { return v; } // optional
	void apply(StVal &s, const int lo, const int hi) { 
		if (!b) { return; }
		if (hi == lo) { s.m = this->v; }
		else { s.m = max(this->v, s.m); }
	}
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<StUpdate> lazy;
	vector<int> leaves;

	SegTree(const int n, int val) : n(n) {
		leaves.resize(n);
		init(1, 0, n - 1, val);
		lazy.resize(st.size());
	}

	void init(const int si, const int lo, const int hi, int val) { // init st[] and leaves[]
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
			leaves[lo] = si; st[si].m = val;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid, val);
			init(si << 1 | 1, mid + 1, hi, val);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]); // optional if T(T(), T()) = T()
		}
	}

	void updateLazy(const int si, const int lo, const int hi) {
		lazy[si].apply(st[si], lo, hi);
		if (lo != hi) {
			lazy[si << 1] = StUpdate(lazy[si << 1], lazy[si]);
			lazy[si << 1 | 1] = StUpdate(lazy[si << 1 | 1], lazy[si]);
		}
		lazy[si] = StUpdate();
	}

	StVal query(const int l, const int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}


	void update(const int l, const int r, const StUpdate u) { if (l <= r) update(l, r, u, 1, 0, n - 1); }
	void update(const int l, const int r, const StUpdate &u, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) {
			lazy[si] = StUpdate(lazy[si], u);
			updateLazy(si, lo, hi);
		}
		else {
			updateLazy(si, lo, hi);
			if (hi < l || r < lo) return;
			const int mid = (lo + hi) >> 1;
			update(l, r, u, si << 1, lo, mid);
			update(l, r, u, si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}
};

struct edge {
	int u, v;
	edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node {
	int id; vector<edge> edges;
};

vector<node> tree;
vector<int> start, finish;

void preorder(int u, int &t) {
	start[u] = t; t++;
	for (auto &x : tree[u].edges) {
		if (start[x.v] == -1) { preorder(x.v, t); }
	}
	finish[u] = t - 1;
}

void add_edge(int u, int v) {
	edge e1(u, v), e2(v, u);
	tree[u].edges.push_back(e1);
	tree[v].edges.push_back(e2);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n; tree.resize(n);
	start.resize(n, -1); finish.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b; 
		a--; b--; add_edge(a, b);
	}
	int t = 0; preorder(0, t); tree.clear();
	SegTree st_fill(n, -1), st_empty(n, 0);
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int c, v; cin >> c >> v; v--;
		if (c == 1) {
			StUpdate stu(i + 1, true);
			st_fill.update(start[v], finish[v], stu);
		}
		else if (c == 2) {
			StUpdate stu(i, true);
			st_empty.update(start[v], start[v], stu);
		}
		else {
			int f = st_fill.query(start[v], start[v]);
			int e = st_empty.query(start[v], finish[v]);
			cout << (e < f) << endl;
		}
	}
	cin.ignore(2); return 0;
}
