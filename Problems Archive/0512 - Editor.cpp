#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct StVal {
	int pre = 0, mi = 0, ma = 0;
	StVal() {}
	StVal(const char _c) {
		if (_c == '(') { pre = mi = ma = 1; }
		else if (_c == ')') { pre = mi = ma = -1; }
	}
	StVal(const StVal &v1, const StVal &v2) { 
		pre = v1.pre + v2.pre;
		mi = min(v1.mi, v1.pre + v2.mi);
		ma = max(v1.ma, v1.pre + v2.ma);
	}
};

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
			st[si] = StVal();
			leaves[lo] = si;
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

	void update(const int i, const char c) {
		int si = leaves[i]; st[si] = StVal(c);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; SegTree st(n);
	int i = 0; int res = 0; int q = n;
	while (q--) {
		char c; cin >> c;
		if (c == 'R') { cout << res << ' '; i++; continue; }
		else if (c == 'L') { cout << res << ' '; i = max(0, i - 1); continue; }
		st.update(i, c); StVal v = st.query(0, n - 1);
		res = (v.pre || v.mi) ? -1 : v.ma;
		cout << res << ' ';
	}
	cout << endl; cin.ignore(2); return 0;
}