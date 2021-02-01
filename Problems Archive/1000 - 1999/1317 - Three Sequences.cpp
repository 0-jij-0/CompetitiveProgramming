#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

struct StVal {
	ll pos = 0, neg = 0; StVal() {}
	StVal(const ll _v) { (_v > 0 ? pos : neg) = _v; }
	StVal(StVal &s, const int &x) { 
		ll v = (s.pos ? s.pos : s.neg) + x; 
		pos = 0; neg = 0; (v > 0 ? pos : neg) = v;
	}
	StVal(const StVal &v1, const StVal &v2) { 
		pos = v1.pos + v2.pos; neg = v1.neg + v2.neg;
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
			st[si] = StVal(v[lo + 1] - v[lo]); leaves[lo] = si;
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
		if (i < 0 || i >= n) { return; }
		int si = leaves[i]; st[si] = StVal(st[si], x);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

ll query(const int &n, SegTree &st) {
	ll pos = v[0] + st.query(0, n - 1).pos;	
	return pos > 0 ? (pos + 1) / 2 : pos / 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	int q; cin >> q;

	if (n == 1) {
		cout << (v[0] + 1) / 2 << '\n';
		while (q--) { 
			int l, r, x; cin >> l >> r >> x; v[0] += x; 
			cout << (v[0] > 0 ? (v[0] + 1) / 2 : v[0] / 2) << '\n';
		}
		cin.ignore(2); return 0;
	}

	SegTree st(n - 1); cout << query(n - 1, st) << '\n';

	while (q--) {
		int l, r, x; cin >> l >> r >> x; 
		l--; r--; if (!l) { v[0] += x; }
		st.update(l - 1, x); st.update(r, -x);
		cout << query(n - 1, st) << '\n';
	}

	cin.ignore(2); return 0;
}