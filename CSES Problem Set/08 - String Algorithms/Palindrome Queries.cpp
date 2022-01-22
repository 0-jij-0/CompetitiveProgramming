#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int p1 = 257, p2 = 619;
const ll mod1 = 1000 * 1000 * 1000 + 7;
const ll mod2 = 998244353;
ll p1pow[200001], p2pow[200001];

string s;

struct StVal {
	ll h1 = 0, h2 = 0; int len = 0; StVal() {}
	StVal(const char _c) : h1(_c), h2(_c), len(1) {}
	StVal(const StVal& v1, const StVal& v2) { 
		h1 = (v1.h1 * p1pow[v2.len] + v2.h1) % mod1;
		h2 = (v1.h2 * p2pow[v2.len] + v2.h2) % mod2;
		len = v1.len + v2.len;
	}
	bool operator == (const StVal& rhs) const {
		return (h1 == rhs.h1) && (h2 == rhs.h2);
	}
};

struct SegTree {
	int n; bool rev = false;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n, bool rev = false) : n(n), rev(rev), leaves(n) {
		init(1, 0, n - 1); 
	}

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(s[rev ? n - 1 - lo : lo]); 
			leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	StVal query(const int l, const int r) { return query(rev ? n - 1 - r : l, rev ? n - 1 - l : r, 1, 0, n - 1); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i, char c) {
		int si = leaves[rev ? n - 1 - i : i]; st[si] = StVal(c);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	p1pow[0] = p2pow[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		p1pow[i] = (p1pow[i - 1] * p1) % mod1;
		p2pow[i] = (p2pow[i - 1] * p2) % mod2;
	}

	int n, q; cin >> n >> q >> s; 
	SegTree st1(n), st2(n, true);

	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int k; char c; cin >> k >> c; k--;
			st1.update(k, c); st2.update(k, c);
		}
		else {
			int l, r; cin >> l >> r; l--; r--;
			cout << (st1.query(l, r) == st2.query(l, r) ? "YES" : "NO") << '\n';
		}
	}

	cin.ignore(2); return 0;
}