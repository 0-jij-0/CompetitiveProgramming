#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct edge {
	int u, v; ll c; edge() {}
	edge(int _u, int _v, ll _c) :
		u(_u), v(_v), c(_c) {}
};

vector<ll> a;
//resize before using
//initialize start to -1's
vector<vector<edge>> tree;
vector<int> start, finish, order;

struct StVal {
	ll v = 0; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal& v1, const StVal& v2) { v = max(v1, v2); }
	operator ll() const { return v; }
};

struct StUpdate {
	ll x = 0; StUpdate() {}
	StUpdate(const ll v) : x(v) {}
	StUpdate(const StUpdate& u1, const StUpdate& u2) { x = u1 + u2; }
	operator ll() const { return x; }
	void apply(StVal& v, const int lo, const int hi) { v.v += x; }
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
			st[si] = StVal(a[order[lo]]); leaves[lo] = si;
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

	void update(const int i) {
		int si = leaves[i];
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

void preorder(int u, int& t) {
	start[u] = t; t++; order.push_back(u);
	for (auto& x : tree[u]) {
		if (start[x.v] == -1) { preorder(x.v, t); }
	}
	finish[u] = t - 1;
}

void add_edge(int u, int v, ll c) {
	edge e1(u, v, c), e2(v, u, c);
	tree[u].push_back(e1);
	tree[v].push_back(e2);
}

void dfs1(int cur, SegTree& st, int p = -1) {
	for (auto& e : tree[cur]) if (e.v != p) {
		st.update(start[e.v], finish[e.v], e.c);
		dfs1(e.v, st, cur);
	}
}

void dfs2(int cur, SegTree& st, vector<ll> &res, int p = -1) {
	res[cur] = max(st.query(0, start[cur] - 1), st.query(start[cur] + 1, st.n - 1));
	for (auto& e : tree[cur]) if (e.v != p) {
		st.update(0, st.n - 1, e.c);
		st.update(start[e.v], finish[e.v], -2 * e.c);
		dfs2(e.v, st, res, cur);
		st.update(start[e.v], finish[e.v], 2 * e.c);
		st.update(0, st.n - 1, -e.c);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; tree.resize(n); a.resize(n);
	start.resize(n, -1); finish.resize(n);

	for (int i = 1; i < n; i++) {
		int u, v; ll c; cin >> u >> v >> c;
		u--; v--; add_edge(u, v, c);
	}

	for (auto& x : a) cin >> x;
	int t = 0; preorder(0, t); SegTree st(n);

	dfs1(0, st); vector<ll> res(n, 0); dfs2(0, st, res);
	for (auto& x : res) cout << x << '\n';

	cin.ignore(2); return 0;
}