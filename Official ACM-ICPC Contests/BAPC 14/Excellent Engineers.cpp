#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct StVal {
	int v = 1e7; StVal() {}
	StVal(const int _v) : v(_v) {}
	StVal(const StVal &v1, const StVal &v2) { v = min(v1, v2); }
	operator int() const { return v; }	//Casts StVal to int
};
 
struct SegTree {
	int n;
	vector<int> leaves;
	vector<StVal> st;	
 
	SegTree(const int n) : n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
	}
 
	//lo, hi indices of the actual array; si is the index of the segment tree array
	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) { st.resize(si + 1); }
			st[si] = StVal();			//Set the actual array here
			leaves[lo] = si;
			return;
		}
		int lC = si << 1, rC = (si << 1) | 1, mid = (lo + hi) >> 1;
		init(lC, lo, mid); init(rC, mid + 1, hi);
		st[si] = StVal(st[lC], st[rC]);
	}
 
	//l and r inclusive, 0-indexed
	StVal query(const int l, const int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];
 
		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}
 
	//Change a leaf and update its ancestors' values
	void update(const int i, int c) {
		int si = leaves[i];
		st[si] = StVal(c);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};
 
struct pers {
	int r1, r2, r3;
 
	pers() {}
	pers(int _r1, int _r2, int _r3) :r1(_r1), r2(_r2), r3(_r3) {}
 
	bool operator<(pers &other) {
		return r1 < other.r1;
	}
};
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
 
		vector<pers> persons(n);
		for (int i = 0; i < n; i++) {
			int cur1, cur2, cur3; cin >> cur1 >> cur2 >> cur3;
			cur1--; cur2--; cur3--;
			persons[i] = pers(cur1, cur2, cur3);
		}
		sort(persons.begin(), persons.end());
 
		int ans = 0; SegTree st(n);
		for (int i = 0; i < n; i++) {
			if (st.query(0, persons[i].r2) > persons[i].r3) { ans++; }
			st.update(persons[i].r2, persons[i].r3);
		}
 
		cout << ans << '\n';
	}
}