#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;

struct StVal {
	int mi = 1 << 30, ma = -(1 << 30); StVal() {}
	StVal(const int _v) : mi(_v), ma(_v) {}
	StVal(const StVal& v1, const StVal& v2) { 
		mi = min(v1.mi, v2.mi);
		ma = max(v1.ma, v2.ma);
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
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; v.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			char c; cin >> c; v[i] = (c == '+') ? 1 : -1;
		}
		partial_sum(v.begin(), v.end(), v.begin());
		SegTree st(n + 1); while (m--) {
			int l, r; cin >> l >> r;
			StVal left = st.query(0, l - 1);
			StVal right = (r == n) ? StVal() : st.query(r + 1, n);
			if (r != n) { right.ma -= v[r]; right.mi -= v[r]; }
			int L = left.ma - left.mi + 1;
			int R = max(0, v[l - 1] + right.ma - left.ma) + max(0, left.mi - (v[l - 1] + right.mi));
			cout << L + R << '\n';
		}
	}

	cin.ignore(2); return 0;
}