#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

struct StVal {
	int v = 0; StVal() {}
	StVal(const int _v) : v(_v) {}
	StVal(const StVal &v1, const StVal &v2) { v = max(v1, v2); }
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
			st[si] = v[lo]; leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	int query(int k) { return query(1, 0, n - 1, k); }
	int query(const int si, const int lo, const int hi, const int k) {
		if (st[si] < k) { return -1; }
		if (lo == hi) { return lo; }
		const int mid = (lo + hi) >> 1;
		if (st[si << 1] >= k) { return query(si << 1, lo, mid, k); }
		return query(si << 1 | 1, mid + 1, hi, k);
	}

	void update(const int i, int x) {
		int si = leaves[i]; st[si] = st[si] - x;
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; v.resize(n);
	for (auto &x : v) { cin >> x; }
	vector<int> res; SegTree st(n); while (m--) {
		int k; cin >> k; int idx = st.query(k);
		res.push_back(st.query(k));
		if (idx != -1) { st.update(idx, k); }
	}
	for (auto &x : res) { cout << x + 1 << ' '; }
	cout << '\n'; cin.ignore(2); return 0;
}