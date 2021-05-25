#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct StVal {
	int v = -1; StVal() {}
	StVal(const int _v) : v(_v) {}
	StVal(const StVal& v1, const StVal& v2) { v = v1 + v2; }
	operator int() const { return v; }
};

struct StUpdate {
	int v = -2; StUpdate() {}
	StUpdate(const int v) : v(v) {}
	StUpdate(const StUpdate& u1, const StUpdate& u2) { 
		if (u2 == -2 && u1 == -2) { v = -2; }
		else if (u2 == -2) { v = u1; }
		else { v = u2; }
	}
	operator int() const { return v; }
	void apply(StVal& v, const int lo, const int hi) {
		if (this->v == -2) { return; }
		v.v = this->v * (hi - lo + 1);
	}
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<StUpdate> lazy;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) {
		init(1, 0, n - 1); lazy.resize(st.size());
	}

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
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

	StVal query(const int l, const int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int l, const int r, const StUpdate u) { if (l <= r) update(l, r, u, 1, 0, n - 1); }
	void update(const int l, const int r, const StUpdate& u, const int si, const int lo, const int hi) {
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
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

//resize before using
//initialize start to -1's
vector<node> tree, treeK;
vector<int> start, finish;

void preorder(int u, int& t) {
	start[u] = t; t++;
	for (auto& x : tree[u].edges) {
		if (start[x.v] == -1) { preorder(x.v, t); }
	}
	finish[u] = t - 1;
}

void add_edge(int u, int v, vector<node> &t) {
	edge e1(u, v), e2(v, u);
	t[u].edges.push_back(e1);
	t[v].edges.push_back(e2);
}

void maxClique(SegTree &st, int ans, int &res, int cur, int p = -1) {
	int prev = st.query(start[cur], start[cur]);
	if (prev != -1) { ans--; st.update(start[prev], finish[prev], -1); }
	st.update(start[cur], finish[cur], cur); res = max(res, ++ans);

	for (edge& e : treeK[cur].edges) if(e.v != p)
		maxClique(st, ans, res, e.v, cur);

	int cur2 = st.query(start[cur], start[cur]);
	if (cur2 != -1) { st.update(start[cur], finish[cur], -1); ans--; }
	if (prev != -1) { st.update(start[prev], finish[prev], prev); ans++; }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; tree.clear(); treeK.clear();
		tree.resize(n); treeK.resize(n); start.clear();
		finish.clear(); start.resize(n, -1); finish.resize(n);

		for (int i = 1; i < n; i++) {
			int p; cin >> p; add_edge(i, --p, treeK);
		}
		for (int i = 1; i < n; i++) {
			int p; cin >> p; add_edge(i, --p, tree);
		}

		int T = 0; preorder(0, T); SegTree st(n);
		int res = 0; maxClique(st, 0, res, 0);
		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}