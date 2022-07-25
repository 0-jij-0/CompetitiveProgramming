#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct StVal {
	ll mi = 0, ma = 0, sum = 0; StVal() {}
	StVal(const ll v) : mi(v), ma(v), sum(v) {}
	StVal(const StVal& v1, const StVal& v2) { 
		mi = min(v1.mi + v2.sum, v2.mi);
		ma = max(v1.ma + v2.sum, v2.ma);
		sum = v1.sum + v2.sum;
	}
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) { init(1, 0, n - 1);	}

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

	StVal query(const int l, const int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i, bool b) {
		int si = leaves[i]; st[si] = StVal(b ? -1 : 1);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; SegTree st(n);
	for (int i = 0; i < n; i++) {
		int c, s; cin >> c >> s;
		st.update(--c, --s); StVal V = st.query(0, n - 1);
		if (V.ma > 0 && V.mi < 0) { cout << "?\n"; continue; }
		cout << (V.mi < 0 ? '<' : '>') << '\n';
	}
}