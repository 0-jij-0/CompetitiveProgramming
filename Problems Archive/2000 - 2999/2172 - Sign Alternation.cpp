#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> A;

struct StVal {
	ll sum = 0; StVal() {}
	StVal(const ll _v) : sum(_v) {}
	StVal(const StVal& v1, const StVal& v2) { sum = v1 + v2; }
	operator ll() const { return sum; }
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n, bool b) : n(n), leaves(n) { init(1, 0, n - 1, b); }

	void init(const int si, const int lo, const int hi, bool b) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(A[lo << 1 | b]); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid, b);
			init(si << 1 | 1, mid + 1, hi, b);
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

	void update(const int i, const int x) {
		int si = leaves[i]; st[si] = StVal(x);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; A.resize(n);
	for (auto& x : A) cin >> x;

	SegTree even((n + 1) >> 1, 0), odd(n >> 1, 1);
	int m; cin >> m; while (m--) {
		int t; cin >> t; if (t) {
			int l, r; cin >> l >> r; --l; --r;
			ll E = even.query((l + 1) >> 1, r >> 1);
			ll O = odd.query(l >> 1, ((r + 1) >> 1) - 1);
			cout << (l & 1 ? O - E : E - O) << '\n';
		}
		else {
			int i, j; cin >> i >> j; --i;
			(i & 1 ? odd : even).update(i >> 1, j);
		}
	}
}