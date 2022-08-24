#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1 << 30;

struct StVal {
	int v = INF; StVal() {}
	StVal(const int _v) : v(_v) {}
	StVal(const StVal& v1, const StVal& v2) { v = min(v1, v2); }
	operator int() const { return v; }
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) { init(1, 0, n - 1); }

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	int query(int l, int r, int p) { return query(l, r, 1, 0, n - 1, p); }
	int query(int l, int r, const int si, const int lo, const int hi, const int p) {
		int mid = (lo + hi) >> 1;
		if (l <= lo && hi <= r) {
			if (st[si] > p) { return 0; }
			if (lo == hi) { update(lo, INF); return 1; }

			int res = st[si << 1] <= p ? query(l, r, si << 1, lo, mid, p) : 0;
			if (st[si << 1 | 1] <= p) res += query(l, r, si << 1 | 1, mid + 1, hi, p);
			return res;
		}

		int L = mid < l ? 0 : query(l, r, si << 1, lo, mid, p);
		int R = r <= mid ? 0 : query(l, r, si << 1 | 1, mid + 1, hi, p);
		return L + R;

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

	int n, m; cin >> n >> m;
	SegTree st(n); while (m--) {
		int t; cin >> t; if (--t) {
			int l, r, p; cin >> l >> r >> p;
			cout << st.query(l, --r, p) << '\n';
		}
		else {
			int i, h; cin >> i >> h;
			st.update(i, h);
		}
	}
}