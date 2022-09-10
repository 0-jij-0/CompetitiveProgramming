#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> p;

struct StVal {
	ll v = 0; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal& v1, const StVal& v2) { v = v1 + v2; }
	operator ll() const { return v; }
};

struct StUpdate {
	ll f = 0, r = 0; StUpdate() {}
	StUpdate(ll _f, ll _r) : f(_f), r(_r) {}
	StUpdate(const StUpdate& u1, const StUpdate& u2, int off) {
		f = u1.f + u2.f + off * u2.r; r = u1.r + u2.r;
	}
	void apply(StVal& v, const int lo, const int hi) {
		int n = hi - lo + 1;
		v.v += (2 * f * n + r * n * (n - 1)) >> 1;
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
			const int mid = (lo + hi) >> 1;
			lazy[si << 1] = StUpdate(lazy[si << 1], lazy[si], 0);
			lazy[si << 1 | 1] = StUpdate(lazy[si << 1 | 1], lazy[si], mid + 1 - lo);
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

	void updateAllLazy() { updateAllLazy(1, 0, n - 1); }
	void updateAllLazy(int si, int lo, int hi) {
		updateLazy(si, lo, hi);
		if (lo != hi) {
			const int mid = (lo + hi) >> 1;
			updateAllLazy(si << 1, lo, mid);
			updateAllLazy(si << 1 | 1, mid + 1, hi);
		}
	}

	vector<ll> retreive() {
		updateAllLazy();
		vector<ll> res(n);
		for (int i = 0; i < n; ++i)
			res[i] = st[leaves[i]];
		return res;
	}
};

void update(SegTree& st, int L, int R, int f, int r, int n) {
	if (L <= R) { st.update(L, R, StUpdate(f, r)); return; }
	st.update(L, n - 1, StUpdate(f, r));
	st.update(0, R, StUpdate(f + (n - L) * r, r));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; p.resize(n);
	for (auto& x : p) cin >> x;

	auto dist = [&](const int& i, const int& j) { return (j - i + n) % n; };

	SegTree st(n);
	for (int i = 0; i < n; i++) {
		int op = (p[i] + n / 2) % n;
		int L = dist(i, p[i]), R = dist(i, op);
		update(st, L, R, 0, 1, n);

		int LL = (R + 1) % n, RR = (L - 1 + n) % n, D = dist(op + 1, p[i]);
		update(st, LL, RR, D, -1, n);
	}

	vector<ll> res = st.retreive();
	cout << *min_element(res.begin(), res.end()) << '\n';
}