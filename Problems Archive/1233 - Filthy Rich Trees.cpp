#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef double ld;

struct StVal {
	ld v = 0.0; StVal() {}
	StVal(const int _v) : v(log10(_v)) {}
	StVal(const StVal &v1, const StVal &v2) { v = v1 + v2; }
	operator ld() const { return v; }
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) { init(1, 0, n - 1); }

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

	StVal query(const int l, const int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i, const int x) {
		int si = leaves[i]; st[si] = StVal(x);
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

	int n; cin >> n; tree.resize(n);
	start.resize(n, -1); finish.resize(n);

	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--; v--; add_edge(u, v);
	}
	int t = 0; preorder(0, t); SegTree st(n);
	int q; cin >> q; while (q--) {
		int x, y; cin >> t >> x >> y; x--; y--;
		if (t == 1) { st.update(start[x], y + 1); continue; }
		ld X = st.query(start[x], finish[x]);
		ld Y = st.query(start[y], finish[y]);
		if (X - Y >= 9.0) { cout << 1000000000 << '\n'; continue; }
		cout << fixed << setprecision(6) << pow(10.0, X - Y) << '\n';
	}

	cin.ignore(2); return 0;
}