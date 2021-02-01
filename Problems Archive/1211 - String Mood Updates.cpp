#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

string s;
set<char> vowels = { 'A', 'E', 'I', 'O', 'U' };

struct StVal {
	ll a00 = 0, a01 = 0, a10 = 0, a11 = 0; StVal() {}
	StVal(const char c) {
		if (c == 'S' || c == 'D') { a00 = a10 = 1; a01 = a11 = 0; }
		else if (c == 'H') { a00 = a10 = 0; a11 = a01 = 1; }
		else if (vowels.count(c)) { a00 = a11 = 0; a01 = a10 = 1; }
		else if (c == '?') { a00 = 20; a01 = 6; a10 = 7; a11 = 19; }
		else { a00 = a11 = 1; a01 = a10 = 0; }
	}
	StVal(const StVal &v1, const StVal &v2) {
		a00 = (v1.a00 * v2.a00 + v1.a01 * v2.a10) % mod;
		a01 = (v1.a00 * v2.a01 + v1.a01 * v2.a11) % mod;
		a10 = (v1.a10 * v2.a00 + v1.a11 * v2.a10) % mod;
		a11 = (v1.a10 * v2.a01 + v1.a11 * v2.a11) % mod;
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
			st[si] = StVal(s[lo]); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	StVal query() { return query(0, n - 1, 1, 0, n - 1); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i, char c) {
		int si = leaves[i]; st[si] = StVal(c);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q >> s; SegTree st(n);
	cout << st.query().a11 << '\n';
	while (q--) {
		int i; char c; cin >> i >> c;
		i--; st.update(i, c);
		cout << st.query().a11 << '\n';
	}

	cin.ignore(2); return 0;
}