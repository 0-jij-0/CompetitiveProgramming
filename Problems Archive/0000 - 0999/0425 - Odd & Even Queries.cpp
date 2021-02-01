#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;
const long long mod = 1000 * 1000 * 1000 + 7;

struct StVal {
	int x[2] = { 0, 0 }; StVal() {}
	StVal(const int a) { x[a % 2]++; }
	StVal(const StVal &v1, const StVal &v2) { 
		x[0] = v1.x[0] + v2.x[0];
		x[1] = v1.x[1] + v2.x[1];
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

long long power(int x, int n) {
	if (n == 0) { return 1; }
	long long res = power(x, n / 2);
	res = (res * res) % mod;
	if (n % 2) { return (res * x) % mod; }
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q; 
		v.clear(); v.resize(n);
		for (auto &x : v) { cin >> x; }
		SegTree st(n);
		while (q--) {
			int l, r, t; cin >> l >> r >> t;
			l--; r--; StVal s = st.query(l, r);
			if (t) {
				long long res = power(2, s.x[1]);
				cout << (res - 1 + mod) % mod << endl;
			}
			else {
				long long res = power(2, s.x[1]);
				res *= (power(2, s.x[0]) - 1 + mod) % mod;
				cout << res % mod << endl;
			}
		}
	}

	cin.ignore(2); return 0;
}