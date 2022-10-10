#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;

struct StVal {
	ll res = 0, sum = 0, sufMax = 0, prefMax = 0; StVal() {}
	StVal(const ll _v) { res = sum = sufMax = prefMax = _v; }
	StVal(const StVal &v1, const StVal &v2) { 
		sum = v1.sum + v2.sum;
		sufMax = max(v2.sufMax, v1.sufMax + v2.sum);
		prefMax = max(v1.prefMax, v1.sum + v2.prefMax);
		res = max({ v1.res, v2.res, v1.sufMax + v2.prefMax });
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
			st[si] = StVal(v[lo]); leaves[lo] = si;
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
		int si = leaves[i]; st[si] = StVal(x);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; v.resize(n);
	for (auto &x : v) { cin >> x; }
	SegTree st(n); while (m--) {
		int k, x; cin >> k >> x; st.update(--k, x);
		cout << max(st.query(0, n - 1).res, 0ll) << '\n';
	}
}