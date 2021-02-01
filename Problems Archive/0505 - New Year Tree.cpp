#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> c;

struct StVal {
	ll v = 0; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal &v1, const StVal &v2) { v = v1.v | v2.v; }
	operator ll() const { return v; }
};

struct StUpdate {
	ll v = 0; bool b = false; StUpdate() {}
	StUpdate(const ll v) : v(v) {}
	StUpdate(ll _v, bool _b) : v(_v), b(_b) {}
	StUpdate(const StUpdate &u1, const StUpdate &u2) { 
		if (u2.b) { v = u2.v; b = true; }
		else { v = u1.v; b = u1.b; }
	}
	operator ll() const { return v; }
	void apply(StVal &v, const int lo, const int hi) { 
		if (b) { v.v = (1ll << this->v); }
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

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = c[lo];	leaves[lo] = si;
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
vector<int> start, finish, order;

void preorder(int u, int &t) {
	start[u] = t; t++; order.push_back(u);
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

vector<ll> reorder(int n) {
	vector<ll> res(n);
	for (int i = 0; i < n; i++) { res[i] = c[order[i]]; }
	return move(res);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; 
	c.resize(n); tree.resize(n);
	start.resize(n, -1); finish.resize(n);
	for (auto &x : c) { cin >> x; x = 1ll << x; }
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--; add_edge(u, v);
	}
	int t = 0; preorder(0, t);
	c = reorder(n); order.clear();
	SegTree st(n); c.clear();

	for (int i = 0; i < m; i++) {
		cin >> t; t--;
		if (t) {
			int v; cin >> v; v--;
			ll val = st.query(start[v], finish[v]).v;
			int res = 0;
			while (val) { 
				res++; val &= val - 1;
			}
			cout << res << endl;
		}
		else {
			int v, c; cin >> v >> c; v--;
			StUpdate u(c, true);
			st.update(start[v], finish[v], u);
		}
	}

	cin.ignore(2); return 0;
}