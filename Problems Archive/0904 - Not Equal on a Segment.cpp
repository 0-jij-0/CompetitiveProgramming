#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;

struct StVal {
	int min, minIdx, max, maxIdx; StVal() {}
	StVal(const int _v, int i) {
		min = max = _v; minIdx = maxIdx = i;
	}
	StVal(const StVal &v1, const StVal &v2) {
		if (v1.min < v2.min) { min = v1.min; minIdx = v1.minIdx; }
		else { min = v2.min; minIdx = v2.minIdx; }
		if (v1.max > v2.max) { max = v1.max; maxIdx = v1.maxIdx; }
		else { max = v2.max; maxIdx = v2.maxIdx; }
	}
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n) : n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
	}

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(v[lo], lo); leaves[lo] = si;
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
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; v.resize(n);
	for (auto &x : v) { cin >> x; }
	SegTree st(n);
	while (m--) {
		int l, r, x; cin >> l >> r >> x;
		StVal v = st.query(l - 1, r - 1);
		if (v.max == v.min && v.max == x) { cout << -1 << '\n'; continue; }
		if (v.max != x) { cout << v.maxIdx + 1 << '\n'; continue; }
		cout << v.minIdx + 1 << '\n';
	}
	cin.ignore(2); return 0;
}