#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct StVal {
	ll v = 0; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal &v1, const StVal &v2) { v = max(v1, v2); }
	operator ll() const { return v; }
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

	StVal query(const int l, const int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i, ll x) {
		int si = leaves[i]; st[si].v = x;
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}

	ll findMax() {
		ll res = 0;
		for (int i = 0; i < n; i++)
			res = max(res, st[leaves[i]].v);
		return res;
	}
};

vector<int> h, a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; SegTree st(n + 1);
	h.resize(n); a.resize(n);
	for (auto &x : h) { cin >> x; }
	for (auto &x : a) { cin >> x; }
	
	for (int i = 0; i < n; i++)
		st.update(h[i], st.query(0, h[i]) + a[i]);

	cout << st.findMax() << '\n';
	cin.ignore(2); return 0;
}