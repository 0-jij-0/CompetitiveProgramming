#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
using namespace std;
typedef long long ll;

vector<int> A;

struct StVal {
	ll inv = 0; array<ll, 40> freq; StVal() {}
	StVal(const int x) {
		for (int i = 0; i < 40; i++) freq[i] = i >= x;
	}
	StVal(const StVal& v1, const StVal& v2) { 
		inv = v1.inv + v2.inv;
		for (int i = 0; i < 40; i++) {
			freq[i] = v1.freq[i] + v2.freq[i];
			if (i) inv += (v1.freq[i] - v1.freq[i - 1]) * v2.freq[i - 1];
		}
	}
	operator ll() const { return inv; }
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) { init(1, 0, n - 1); }

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(A[lo]); leaves[lo] = si;
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

	void update(const int i, const int x) {
		int si = leaves[i]; st[si] = StVal(x);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; A.resize(n);
	for (auto& x : A) { cin >> x; --x; }

	SegTree st(n); while (m--) {
		int t; cin >> t; if (--t) {
			int x, y; cin >> x >> y;
			st.update(--x, --y);
		}
		else {
			int l, r; cin >> l >> r;
			cout << st.query(--l, --r) << '\n';
		}
	}
}