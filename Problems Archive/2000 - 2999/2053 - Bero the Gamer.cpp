#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

struct StVal {
	int v = 0, ones = 0, zeros = 0; StVal() {}
	StVal(ll _v) {
		while (_v >= 3) { v++; _v /= 3; }
		ones = v == 1;
		zeros = v == 0;
	}
	StVal(const StVal& v1, const StVal& v2) {
		v = v1.v ^ v2.v;
		ones = v1.ones + v2.ones;
		zeros = v1.zeros + v2.zeros;
	}
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

	StVal query(const int l, const int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i, ll x) {
		int si = leaves[i]; st[si] = StVal(x);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	freopen("bero.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		int n, q; cin >> n >> q; v.resize(n);
		for (auto& x : v) { cin >> x; }

		SegTree st(n); while (q--) {
			int t; cin >> t;
			if (t == 1) {
				int i; ll v; cin >> i >> v;
				st.update(--i, v);
			}
			if (t == 2) {
				int l, r; cin >> l >> r;
				StVal v = st.query(--l, --r);
				if ((v.ones + v.zeros) == r - l + 1) { cout << (v.ones & 1 ? "Besho" : "Bero") << '\n'; }
				else { cout << (v.v ? "Bero" : "Besho") << '\n'; }
			}
		}
	}
}