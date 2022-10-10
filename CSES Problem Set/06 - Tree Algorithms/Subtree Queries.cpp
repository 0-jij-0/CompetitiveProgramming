#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> a, v;

struct StVal {
	ll v = 0; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal &v1, const StVal &v2) { v = v1 + v2; }
	operator ll() const { return v; }
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) { init(1, 0, n - 1); }

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(v[lo]); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	StVal query(const int l, const int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i, int x) {
		int si = leaves[i]; st[si] = x;
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q; v.resize(n); a.resize(n);
	tree.resize(n); start.resize(n, -1); finish.resize(n);

	for (auto &x : a) { cin >> x; }
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--; v--; add_edge(u, v);
	}
	int t = 0; preorder(0, t);
	for (int i = 0; i < n; i++)	v[i] = a[order[i]];
	SegTree st(n); while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int s, x; cin >> s >> x;
			st.update(start[--s], x);
		}
		else {
			int s; cin >> s; s--;
			cout << st.query(start[s], finish[s]) << '\n';
		}
	}
}