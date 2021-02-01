#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;

struct StVal {
	int x = 0, sum = 0; StVal() {}
	StVal(int _s) : sum(_s) {}
	StVal(const StVal &v1, const StVal &v2) { 
		sum = v1.sum + v2.sum;
		x = v1.x + v2.x;
		if (sum >= 10) { sum -= 10; x++; }
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
			st[si] = StVal(); leaves[lo] = si; st[si] = StVal(v[lo]);
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
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	SegTree st(n); int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		l--; r--; cout << st.query(l, r).x << endl;
	}
	cin.ignore(2); return 0;
}