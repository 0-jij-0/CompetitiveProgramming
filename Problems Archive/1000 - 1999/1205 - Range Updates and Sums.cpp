#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v;

struct StVal {
	ll v = 0; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal &v1, const StVal &v2) { v = v1 + v2; }
	operator ll() const { return v; }
};

struct StUpdate {
	int t = 0; ll v = 0; StUpdate() {}
	StUpdate(int _t, ll _v) : t(_t), v(_v) {}
	StUpdate(const StUpdate &u1, const StUpdate &u2) { 
		if (u2.t == 0) { t = u1.t; v = u1.v; }
		else if (u1.t == 0) { t = u2.t; v = u2.v; } 
		else if (u2.t == 2) { t = u2.t; v = u2.v; }
		else { t = u1.t; v = u1.v + u2.v; }
	}
	void apply(StVal &v, const int lo, const int hi) {
		if (t == 1) v.v += this->v * (hi - lo + 1);
		if (t == 2) v.v = this->v * (hi - lo + 1);
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
			st[si] = StVal(v[lo]); leaves[lo] = si;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q; v.resize(n);
	for (auto &x : v) { cin >> x; }
	SegTree st(n); while (q--) {
		int t; cin >> t;
		if (t == 3) {
			int l, r; cin >> l >> r;
			cout << st.query(--l, --r) << '\n';
		}
		else {
			int l, r, x; cin >> l >> r >> x;
			st.update(--l, --r, StUpdate(t, x));
		}
	}
	cin.ignore(2); return 0;
}