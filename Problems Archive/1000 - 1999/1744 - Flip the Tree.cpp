#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct StVal {
	int sum = 0; StVal() {}
	StVal(const int _v) : sum(_v) {}
	StVal(const StVal &v1, const StVal &v2) { sum = v1 + v2; }
	operator int() const { return sum; }
};

struct StUpdate {
	bool flip = 0; StUpdate() {}
	StUpdate(const bool v) : flip(v) {}
	StUpdate(const StUpdate &u1, const StUpdate &u2) { flip = u1 ^ u2; }
	operator bool() const { return flip; }
	void apply(StVal &v, const int lo, const int hi) {
		if (flip) v.sum = (hi - lo + 1) - v.sum;
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
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { int id; vector<edge> edges; };

//resize before using
//initialize start to -1's
vector<node> tree;
vector<int> idx, subtreeS, subtreeE, childrenS, childrenE;
vector<int> color;

void preorder(int u, int &t, int p = -1) {
	childrenS[u] = t; subtreeS[u] = t;
	for (auto &e : tree[u].edges) 
		if (e.v != p) { idx[e.v] = t++; }

	childrenE[u] = t - 1;
	for (auto &e : tree[u].edges)
		if (e.v != p) { preorder(e.v, t, u); }

	subtreeE[u] = t - 1;
}

void add_edge(int u, int v) {
	edge e1(u, v), e2(v, u);
	tree[u].edges.push_back(e1);
	tree[v].edges.push_back(e2);
}

int main() {
	freopen("flip.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, q; cin >> n >> q; idx.resize(n);
		subtreeS.resize(n); subtreeE.resize(n);
		childrenS.resize(n); childrenE.resize(n);

		tree.clear(); tree.resize(n); 
		color.clear(); color.resize(n, 0);
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			add_edge(--u, --v);
		}

		idx[0] = 0; int t = 1; preorder(0, t);

		SegTree st(n); while (q--) {
			int t, u; cin >> t >> u; u--;
			if (t == 1) {
				st.update(idx[u], idx[u], 1); color[u] ^= 1;
				st.update(childrenS[u], childrenE[u], 1);
			}
			else { cout << color[u] + st.query(subtreeS[u], subtreeE[u]) << '\n'; }
		}
	}
}