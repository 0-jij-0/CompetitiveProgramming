#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

string s;

struct StVal {
	int res = 0, len = 0, zPref = 0, oPref = 0, zSuf = 0, oSuf = 0; StVal() {}
	StVal(const bool _b) : res(1), len(1) {
		if (_b) { oPref = oSuf = 1; }
		else { zPref = zSuf = 1; }
	}
	StVal(const StVal &v1, const StVal &v2) { 
		len = v1.len + v2.len;
		zPref = v1.zPref == v1.len ? v1.len + v2.zPref : v1.zPref;
		oPref = v1.oPref == v1.len ? v1.len + v2.oPref : v1.oPref;
		zSuf = v2.zSuf == v2.len ? v2.len + v1.zSuf : v2.zSuf;
		oSuf = v2.oSuf == v2.len ? v2.len + v1.oSuf : v2.oSuf;
		res = max({ v1.res, v2.res, v1.zSuf + v2.zPref, v1.oSuf + v2.oPref });
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
			st[si] = StVal(s[lo] - '0'); leaves[lo] = si;
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

	void update(const int i) {
		int si = leaves[i]; st[si] = StVal(st[si].zPref);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> s; int n = (int)s.size(); SegTree st(n);
	int m; cin >> m; while (m--) {
		int k; cin >> k; st.update(--k);
		cout << st.query(0, n - 1).res << ' ';
	}
	cout << '\n'; cin.ignore(2); return 0;
}