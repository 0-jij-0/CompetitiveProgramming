#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

struct StVal {
	int min1[10], min2[10];
	StVal() {
		for (int i = 0; i < 10; i++)
			min1[i] = min2[i] = INT_MAX;
	}
	StVal(const int x) {
		int y = x;
		for (int i = 0; i < 10; i++, y /= 10) {
			min1[i] = min2[i] = INT_MAX;
			if (y % 10) { min1[i] = x; }
		}
	}
	StVal(const StVal &v1, const StVal &v2) {
		for (int i = 0; i < 10; i++) {
			int mi = (v1.min1[i] < v2.min1[i]) ? v1.min1[i] : v2.min1[i];
			int ma = (v1.min1[i] < v2.min1[i]) ? v2.min1[i] : v1.min1[i];
			ma = min(ma, v1.min2[i]); ma = min(ma, v2.min2[i]);
			min1[i] = mi; min2[i] = ma;
		}
	}
};

vector<int> v;

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n) : n(n) {
		leaves.resize(n); init(1, 0, n - 1);
	}

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(); leaves[lo] = si; st[si] = StVal(v[lo]);
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

	void update(const int i, int x) {
		int si = leaves[i]; st[si] = x;
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m; v.resize(n);
	for (auto &x : v) { cin >> x; }
	SegTree st(n);
	for (int i = 0; i < m; i++) {
		int t; cin >> t;
		if (t == 1) {
			int i, x; cin >> i >> x;
			i--; st.update(i, x);
		}
		else {
			int l, r; cin >> l >> r;
			StVal v = st.query(l - 1, r - 1);
			long long mi = 2ll * INT_MAX;
			for (int i = 0; i < 10; i++) 
				mi = min(mi, (long long)v.min1[i] + v.min2[i]);
			if (mi > INT_MAX) { cout << -1 << endl; }
			else { cout << mi << endl; }
		}
	}

	cin.ignore(2); return 0;
}