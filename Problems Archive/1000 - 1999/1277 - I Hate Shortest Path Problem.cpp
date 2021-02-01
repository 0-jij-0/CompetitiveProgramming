#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct StVal {
	ll v = 1 << 30; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal &v1, const StVal &v2) { v = min(v1, v2); }
	operator ll() const { return v; }
};

struct StUpdate {
	ll f = 0, r = 0; StUpdate() {}
	StUpdate(ll _f, ll _r) : f(_f), r(_r) {}
	StUpdate(const StUpdate &u1, const StUpdate &u2, int off) {
		if (u2.r != 0) { f = u2.f + off * u2.r; r = u2.r; }
		else { f = u1.f + u2.f; r = u1.r + u2.r; }
	}
	void apply(StVal &v, const int lo, const int hi) {
		(r == 0) ? v.v += f : v.v = f;
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
			st[si] = StVal(0); leaves[lo] = si;
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
			const int mid = (lo + hi) >> 1;
			lazy[si << 1] = StUpdate(lazy[si << 1], lazy[si], 0);
			lazy[si << 1 | 1] = StUpdate(lazy[si << 1 | 1], lazy[si], mid + 1 - lo);
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
	void update(const int l, const int r, const StUpdate u, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) {
			lazy[si] = StUpdate(lazy[si], u, lo - l);
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

	int h, w; cin >> h >> w; SegTree st(w);
	for (int i = 0; i < h; i++) {
		int l, r; cin >> l >> r; l--; r--;
		st.update(0, l - 1, StUpdate(1, 0));
		//for (int i = 0; i < w; i++) cout << st.query(i, i) << ' '; cout << '\n';
		st.update(r + 1, w - 1, StUpdate(1, 0));
		//for (int i = 0; i < w; i++) cout << st.query(i, i) << ' '; cout << '\n';
		ll x = (l == 0 ? 1000001 : st.query(l - 1, l - 1).v + 1);
		st.update(l, r, StUpdate(x, 1)); x = st.query(0, w - 1);
		//for (int i = 0; i < w; i++) cout << st.query(i, i) << ' '; cout << '\n';
		cout << (x < 1000000 ? x : -1) << '\n';
	}

	cin.ignore(2); return 0;
}