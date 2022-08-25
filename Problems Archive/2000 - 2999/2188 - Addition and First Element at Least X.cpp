#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct StVal {
	int v = 0; StVal() {}
	StVal(const int _v) : v(_v) {}
	StVal(const StVal& v1, const StVal& v2) { v = max(v1, v2); }
	operator int() const { return v; }
};

struct StUpdate {
	int u = 0; StUpdate() {}
	StUpdate(const int v) : u(v) {}
	StUpdate(const StUpdate& oldU, const StUpdate& newU) { u = oldU + newU; }
	operator int() const { return u; }
	void apply(StVal& v, int lo, int hi) { v.v += u; }
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
			leaves[lo] = si;
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

	int query(int k, int l) { return query(l, 1, 0, n - 1, k); }
	int query(int l, int si, int lo, int hi, int k) {
		updateLazy(si, lo, hi);
		const int mid = (lo + hi) >> 1;
		if (l <= lo) {
			if (st[si] < k) { return -1; }
			if (lo == hi) { return lo; }
			updateLazy(si << 1, lo, mid);
			if (st[si << 1] >= k) { return query(l, si << 1, lo, mid, k); }
			return query(l, si << 1 | 1, mid + 1, hi, k);
		}

		if (l > mid) { return query(l, si << 1 | 1, mid + 1, hi, k); }
		int L = query(l, si << 1, lo, mid, k);
		int R = query(l, si << 1 | 1, mid + 1, hi, k);
		return L != -1 ? L : R;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	SegTree st(n); while (m--) {
		int t; cin >> t; if (--t) {
			int x, l; cin >> x >> l;
			cout << st.query(x, l) << '\n';
		}
		else {
			int l, r, v; cin >> l >> r >> v;
			st.update(l, --r, v);
		}
	}
}