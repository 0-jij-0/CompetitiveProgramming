#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template<class V> struct SegTree {
	int n;
	vector<V> st;
	vector<int> leaves;

	SegTree(const int n) : n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
	}

	void init(const int si, const int lo, const int hi) { // init st[] and leaves[]
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = V(); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
			leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = V(st[si << 1], st[si << 1 | 1]); // optional if T(T(), T()) = T()
		}
	}

	V query(const int l, const int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : V(); }
	V query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return V(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i, char c) { // single index update, [!!!] NON-LAZY SEGMENT TREE ONLY !!!
		int si = leaves[i];	st[si] = V(c);
		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}
};

struct StVal { // define
	int length = 0, open = 0, closed = 0; // optional
	StVal() {}
	StVal(char c) :
		open(c == '('), closed(c == ')') {}

	StVal(const StVal &v1, const StVal &v2) { 
		length = v1.length + v2.length;
		int m = min(v1.open, v2.closed);
		length += 2 * m;
		open = v1.open + v2.open - m;
		closed = v1.closed + v2.closed - m;
	}
};

typedef SegTree<StVal> MyST;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s; cin >> s; MyST st((int) s.size());
	for (unsigned int i = 0; i < s.size(); i++) { st.update(i, s[i]); }

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		cout << st.query(l - 1, r - 1).length << endl;
	}
	cin.ignore(2); return 0;
}