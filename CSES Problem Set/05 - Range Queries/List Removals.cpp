#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;

struct StVal {
	int v = 0, c = 1; StVal() {}
	StVal(const ll _v) : v(_v), c(1) {}
	StVal(const StVal &v1, const StVal &v2) { v = max(v1, v2); c = v1.c + v2.c; }
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
			st[si] = StVal(v[lo]); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	int query(int k) { return query(1, 0, n - 1, k); }
	int query(const int si, const int lo, const int hi, int k) {
		if (lo == hi) { update(lo); return v[lo]; }
		const int mid = (lo + hi) >> 1;
		if (st[si << 1].c >= k) { return query(si << 1, lo, mid, k); }
		return query(si << 1 | 1, mid + 1, hi, k - st[si << 1].c);
	}

	void update(const int i) {
		int si = leaves[i]; st[si].c = 0;
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	SegTree st(n); while (n--) {
		int k; cin >> k; cout << st.query(k) << ' ';
	}
	cout << '\n';
}