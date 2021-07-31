#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct StVal {
	int v = 0; StVal() {}
	StVal(const int _v) : v(_v) {}
	StVal(const StVal& v1, const StVal& v2) { v = min(v1, v2); }
	operator int() const { return v; }
};

struct StUpdate {
	int add = 0; StUpdate() {}
	StUpdate(const int v) : add(v) {}
	StUpdate(const StUpdate& u1, const StUpdate& u2) { add = u1 + u2; }
	operator int() const { return add; }
	void apply(StVal& v, const int lo, const int hi) { v.v += add; }
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

struct segment {
	int l = 0, r = 0, w = 0; segment() {}
	segment(int _l, int _r, int _w) : l(_l), r(_r), w(_w) {}
	bool operator < (const segment& rhs) const { return w < rhs.w; }
}; vector<segment> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; SegTree st((m << 1) + 10);
	for (int i = 0; i < n; i++) {
		int l, r, w; cin >> l >> r >> w;
		v.emplace_back(l, r, w);
	} sort(v.begin(), v.end());

	int i = 0, j = 0, res = 1 << 30; while (j != n) {
		if (st.query(2, m << 1) == 0) { 
			st.update(v[j].l << 1, v[j].r << 1, 1);
			j++; continue;
		}
		st.update(v[i].l << 1, v[i].r << 1, -1);
		res = min(res, v[j - 1].w - v[i].w); i++;
	}
	while (i != n) {
		if (st.query(2, m << 1) == 0) {	break; }
		st.update(v[i].l << 1, v[i].r << 1, -1);
		res = min(res, v[j - 1].w - v[i].w); i++;
	}

	cout << res << '\n';
	cin.ignore(2); return 0;
}