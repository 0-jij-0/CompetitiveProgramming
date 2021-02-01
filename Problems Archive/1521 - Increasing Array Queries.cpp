#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct StVal {
	ll ma = 0, s = 0, o = 0; StVal() {}
	StVal(const ll v) : ma(v), s(v), o(0) {}
	StVal(const StVal& v1, const StVal& v2) { 
		ma = max(v1.ma, v2.ma);
		s = v1.s + v2.s; o = v1.o + v2.o;
	}
};

struct StUpdate {
	ll v = -1; StUpdate() {}
	StUpdate(const ll v) : v(v) {}
	StUpdate(const StUpdate& u1, const StUpdate& u2) { 
		v = (u2 == -1) ? u1 : u2;
	}
	operator ll() const { return v; }
	void apply(StVal& st, const int lo, const int hi) {
		if (v == -1) { return; }
		st.o += v * (hi - lo + 1) - st.s;
		st.ma = v; st.s = v * (hi - lo + 1);
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

	void update(const int i, int x) {
		int si = leaves[i]; st[si] = StVal(x);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}

	int findIdx(int k) { return findIdx(1, 0, n - 1, k); }
	int findIdx(const int si, const int lo, const int hi, int k) {
		if (st[si].ma < k) { return n; }
		if (lo == hi) { return lo; }
		const int mid = (lo + hi) >> 1;
		if (st[si << 1].ma >= k) { return findIdx(si << 1, lo, mid, k); }
		return findIdx(si << 1 | 1, mid + 1, hi, k);
	}
};

struct query {
	int l, r, idx; query() {}
	query(int _l, int _r, int _i) : l(_l), r(_r), idx(_i) {}
	bool operator < (const query& rhs) const { return l > rhs.l; }
};

vector<int> v; 
vector<query> Q;
vector<ll> res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q; 
	v.resize(n); Q.resize(q); res.resize(q);
	for (auto& x : v) { cin >> x; }

	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		Q[i] = query(--l, --r, i);
	}
	sort(Q.begin(), Q.end()); SegTree st(n);

	int i = n - 1, j = 0; while (j != q) {
		int idx = st.findIdx(v[i]) - 1; 
		st.update(i, v[i]); st.update(i + 1, idx, v[i]); i--;

		while (j != q && Q[j].l == i + 1) { 
			res[Q[j].idx] = st.query(Q[j].l, Q[j].r).o; j++;
		}
	}

	for (auto& x : res) cout << x << '\n';

	cin.ignore(2); return 0;
}