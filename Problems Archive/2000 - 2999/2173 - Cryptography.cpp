#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int mod = 0;

vector<int> A00, A01, A10, A11;

struct StVal {
	int a00 = 0, a01 = 0, a10 = 0, a11 = 0; StVal() {}
	StVal(int _a00, int _a01, int _a10, int _a11) :
		a00(_a00), a01(_a01), a10(_a10), a11(_a11) {}
	StVal(const StVal& v1, const StVal& v2) { 
		a00 = (v1.a00 * v2.a00 + v1.a01 * v2.a10) % mod;
		a01 = (v1.a00 * v2.a01 + v1.a01 * v2.a11) % mod;
		a10 = (v1.a10 * v2.a00 + v1.a11 * v2.a10) % mod;
		a11 = (v1.a10 * v2.a01 + v1.a11 * v2.a11) % mod;
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
			st[si] = StVal(A00[lo], A01[lo], A10[lo], A11[lo]); leaves[lo] = si;
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

	int n, m; cin >> mod >> n >> m; A00.resize(n);
	A01.resize(n); A10.resize(n); A11.resize(n);
	for (int i = 0; i < n; i++)
		cin >> A00[i] >> A01[i] >> A10[i] >> A11[i];

	SegTree st(n); while (m--) {
		int l, r; cin >> l >> r;
		StVal res = st.query(--l, --r);
		cout << res.a00 << ' ' << res.a01 << '\n';
		cout << res.a10 << ' ' << res.a11 << "\n\n";
	}
}