#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<bool> levels;
vector<int> start, finish, order, a;

struct StVal { // define
	ll v = 0; // optional
	int x = 0;
	StVal() {}
	StVal(const ll _v) : v(_v) {} // optional
	StVal(const StVal &v1, const StVal &v2) { v = v1 + v2; }
	operator ll() const { return v; } // optional
};

struct StUpdate { // define
	ll v = 0; // optional
	StUpdate() {}
	StUpdate(const ll v) : v(v) {} // optional
	StUpdate(const StUpdate &u1, const StUpdate &u2) { v = u1 + u2; }
	operator ll() const { return v; } // optional
	void apply(StVal &v, const int lo, const int hi) { // omit last 2 arguments if non-lazy segment tree
		v.v += this->v * (hi - lo + 1);
	}
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<StUpdate> lazy;
	vector<int> leaves;

	SegTree(const int n) : n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
		lazy.resize(st.size());
	}

	void init(const int si, const int lo, const int hi) { // init st[] and leaves[]
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
			leaves[lo] = si; st[si] = a[lo];
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
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

	void updateAllLazy() { updateAllLazy(1, 0, n - 1); }
	void updateAllLazy(const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (lo != hi) {
			const int mid = (lo + hi) >> 1;
			updateAllLazy(si << 1, lo, mid);
			updateAllLazy(si << 1 | 1, mid + 1, hi);
		}
	}

	vector<StVal> retreive() {
		updateAllLazy();
		vector<StVal> res(n);
		for (int i = 0; i < n; ++i)
			res[i] = st[leaves[i]];
		return move(res);
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

void preorder(int u, int &t) {
	start[u] = t; t++; order.push_back(u);
	for (auto &x : tree[u].edges) {
		if (start[x.v] == -1) { 
			levels[x.v] = !levels[u];
			preorder(x.v, t);
		}
	}
	finish[u] = t - 1;
}

void add_edge(int u, int v) {
	edge e1(u, v), e2(v, u);
	tree[u].edges.push_back(e1);
	tree[v].edges.push_back(e2);
}

vector<int> reorder(int n) {
	vector<int> res(n);
	for (int i = 0; i < n; i++) { res[i] = a[order[i]]; }
	return move(res);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	start.resize(n, -1); finish.resize(n, -1);
	a.resize(n); tree.resize(n); levels.resize(n);
	for (auto &x : a) { cin >> x; }
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		a--; b--; add_edge(a, b);
	}
	int t = 0; levels[0] = 0;
	preorder(0, t); tree.clear();
	a = reorder(n); order.clear();
	SegTree st1(n), st2(n); a.clear();
	for (int i = 0; i < m; i++) {
		int t; cin >> t;
		if(t == 1){
			int x, val; cin >> x >> val; x--;
			((levels[x] % 2) ? st2 : st1).update(start[x], finish[x], val);
			((levels[x] % 2) ? st1 : st2).update(start[x], finish[x], -val);
		}
		else {
			int x; cin >> x; x--;
			cout << ((levels[x] % 2) ? st2 : st1).query(start[x], start[x]).v << endl;
		}
	}
	cin.ignore(2); return 0;
}