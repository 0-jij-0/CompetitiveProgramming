#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<ll> fact(100001);

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll modInv(ll x) { return power(x, mod - 2); }

ll choose(int n, int k) {
	ll denum = (fact[k] * fact[n - k]) % mod;
	return (fact[n] * modInv(denum)) % mod;
}

vector<int> a;

struct StVal {
	int v = 0, idx = 0; StVal() {}
	StVal(const int _v, int _i) : v(_v), idx(_i) {}
	StVal(const StVal& v1, const StVal& v2) { 
		if (v1 < v2) { v = v1; idx = v1.idx; }
		else { v = v2; idx = v2.idx; }
	}
	operator int() const { return v; }
};

struct StUpdate {
	int v = 0; StUpdate() {}
	StUpdate(const int v) : v(v) {}
	StUpdate(const StUpdate& u1, const StUpdate& u2) { v = u1 + u2; }
	operator int() const { return v; }
	void apply(StVal& v, const int lo, const int hi) { v.v -= this->v; }
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
			st[si] = StVal(a[lo], lo); leaves[lo] = si;
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

ll count(int L, int R, SegTree& st) {
	if (L > R) { return 1; }
	StVal V = st.query(L, R);
	if (V.v != 1) { return 0; }
	int idx = st.query(L, R).idx;
	ll weight = choose(R - L, idx - L);
	st.update(idx + 1, R, 1);
	ll val = (count(L, idx - 1, st) * count(idx + 1, R, st)) % mod;
	return (val * weight) % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fact[0] = 1; for (int i = 1; i < 100001; i++)
		fact[i] = (i * fact[i - 1]) % mod;

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; a.resize(n);
		for (auto& x : a) cin >> x; SegTree st(n);
		cout << "Case #" << t << ": " << count(0, n - 1, st) << '\n';
	}

	cin.ignore(2); return 0;
}