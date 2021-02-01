#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll dp[1000001];

struct StVal {
	ll mi = 1 << 30, ma = 0; 
	ll miIdx = -1, maIdx = -1; StVal() {}
	StVal(const int i) : mi(dp[i]), ma(dp[i]), miIdx(i), maIdx(i) {}
	StVal(const StVal &v1, const StVal &v2) { 
		if (v1.mi <= v2.mi) { mi = v1.mi; miIdx = v1.miIdx; }
		else { mi = v2.mi; miIdx = v2.miIdx; }

		if (v1.ma > v2.ma) { ma = v1.ma; maIdx = v1.maIdx; }
		else { ma = v2.ma; maIdx = v2.maIdx; }
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
			st[si] = StVal(lo); leaves[lo] = si;
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
};

ll collatz(ll x) {
	if (x < 1000001 && dp[x] != -1) { return dp[x]; }
	ll res = (x % 2) ? collatz(3 * x + 1) : collatz(x / 2);
	if (x < 1000001) { dp[x] = 1 + res; }
	return 1 + res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("minmax.in", "r", stdin);
	fill(dp, dp + 1000001, -1); dp[1] = 0;
	for (int i = 2; i < 1000001; i++) dp[i] = collatz(i);
	SegTree st(1000001);

	int t; cin >> t; while (t--) {
		int l, r; cin >> l >> r;
		StVal s = st.query(l, r);
		cout << s.miIdx << ' ' << s.maIdx << '\n';
	}
	return 0;
}