#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct StVal {
	ll sum = 0; StVal() {}
	StVal(const ll _v) : sum(_v) {}
	StVal(const StVal& v1, const StVal& v2) { sum = v1 + v2; }
	operator ll() const { return sum; }
};

struct StUpdate {
	bool f = 0; StUpdate() {}
	StUpdate(const bool b) : f(b) {}
	StUpdate(const StUpdate& u1, const StUpdate& u2) { f = u1 ^ u2; }
	operator bool() const { return f; }
	void apply(StVal& v, const int lo, const int hi) {
		if (f) { v = hi - lo + 1 - v; }
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

	void update(const int l, const int r) { if (l <= r) update(l, r, 1, 1, 0, n - 1); }
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

//resize before using
//initialize start to -1's
vector<vector<int>> tree;
vector<int> start, finish;

void preorder(int u, int& t) {
	start[u] = t; t++;
	for (int& e : tree[u]) {
		if (start[e] == -1) { preorder(e, t); }
	}
	finish[u] = t - 1;
}

void add_edge(int u, int v) {
	tree[u].emplace_back(v);
	tree[v].emplace_back(u);
}

vector<SegTree> st;
vector<int> v, subSize;

int dfs(int cur, int p = -1) {
	int res = 1;
	for (int i = 0; i < 17; i++) if (v[cur] & (1 << i))
		st[i].update(start[cur], finish[cur]);

	for (int& e : tree[cur]) if (e != p) res += dfs(e, cur);
	return subSize[cur] = res;
}

ll query(int u) {
	ll res = 0; for (int i = 0; i < 17; i++) {
		ll cont = st[i].query(start[u], finish[u]);
		bool b = ((v[u] & (1 << i)) != 0) ^ st[i].query(start[u], start[u]);
		if (b) { cont = subSize[u] - cont; }
		res += cont * (1ll << i);
	}
	return res;
}

void update(int u, int V) {
	int x = V ^ v[u]; v[u] = V;
	for (int i = 0; i < 17; i++) if (x & (1 << i))
		st[i].update(start[u], finish[u]);
}

int main() {
	freopen("train.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		start.clear(); finish.clear(); st.clear(); tree.clear();
		st.resize(17, SegTree(n)); subSize.resize(n);
		start.resize(n, -1); finish.resize(n); tree.resize(n);

		for (auto& x : v) { cin >> x; }
		for (int i = 1; i < n; i++) {
			int p; cin >> p; add_edge(i, --p);
		}

		int tt = 0; preorder(0, tt); dfs(0);
		int q; cin >> q; while (q--) {
			int t, u; cin >> t >> u; u--;
			if (t == 1) { cout << query(u) << '\n';	}
			else { int V; cin >> V; update(u, V); }
		}
	}

	cin.ignore(2); return 0;
}