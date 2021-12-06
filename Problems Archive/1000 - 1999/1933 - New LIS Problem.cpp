#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct StVal {
	pair<ll, ll> v = { 0, 0 }; StVal() {}
	StVal(const pair<ll, ll> _v) : v(_v) {}
	StVal(const StVal& v1, const StVal& v2) { v = max(v1.v, v2.v); }
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) { init(1, 0, n - 1); }

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

	StVal query(const int l, const int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i, const pair<ll, ll> p) {
		int si = leaves[i];
		st[si].v = p;

		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

vector<int> A;

int main() {
	freopen("lis.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; A.resize(n);
		for (auto& x : A) { cin >> x; }
		int maxE = *max_element(A.begin(), A.end());

		SegTree st(maxE + 1); pair<ll, ll> res = { 0, 0 };
		for (int i = 0; i < n; i++) {
			auto p = st.query(0, A[i]);
			p.v.second += A[i]; p.v.first++;
			res = max(res, p.v); st.update(A[i], p.v);
		}
		cout << res.second << '\n';
	}

	cin.ignore(2); return 0;
}