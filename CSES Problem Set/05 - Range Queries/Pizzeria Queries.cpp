#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> p;

struct StVal {
	ll v = 1 << 30; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal& v1, const StVal& v2) { v = min(v1, v2); }
	operator ll() const { return v; }
};

struct SegTree {
	int n; bool b;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n, bool _b) : n(n), b(_b), leaves(n) { init(1, 0, n - 1); }

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(b ? lo + p[lo] : n - 1 - lo + p[lo]); leaves[lo] = si;
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
		int si = leaves[i]; st[si] = StVal(b ? i + x : n - 1 - i + x);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q; p.resize(n);
	for (auto& x : p) { cin >> x; }
	SegTree st1(n, true), st2(n, false);

	while (q--) {
		int t, k; cin >> t >> k; k--;
		if (t == 1) { 
			int x; cin >> x;
			st1.update(k, x);
			st2.update(k, x);
			continue;
		}
		int a = st1.query(k, n - 1) - k;
		int b = st2.query(0, k) - (n - 1 - k);
		cout << min(a, b) << '\n';
	}
	cin.ignore(2); return 0;
}