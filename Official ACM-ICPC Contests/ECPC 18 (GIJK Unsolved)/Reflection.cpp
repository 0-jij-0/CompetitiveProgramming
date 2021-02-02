#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
 
struct StVal {
	ll a = 1, b = 0; StVal() {}
	StVal(const ll _a, const ll _b) : a(_a), b(_b) {}
	StVal(const StVal& v1, const StVal& v2) { }
};
 
struct StUpdate {
	bool rev = 0; ll add = 0; StUpdate() {}
	StUpdate(const bool b, const ll a = 0) : rev(b), add(a) {}
	StUpdate(const StUpdate& u1, const StUpdate& u2) { 
		if (u2.rev) { add = -u1.add + u2.add; }
		else { add = u1.add + u2.add; }
		if (u1.rev != u2.rev) { rev = true; }
		else { rev = false; }
	}
	void apply(StVal& sv, const int lo, const int hi) {
		if (rev) { sv.a *= -1; sv.b *= -1; }
		sv.b += add;
	}
};
 
struct SegTree {
	int n;
	vector<StVal> st;
	vector<StUpdate> lazy;
	vector<int> leaves;
 
	SegTree(const int n) : n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
		lazy.resize(st.size());
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
 
	void updateLazy(const int si, const int lo, const int hi) {
		lazy[si].apply(st[si], lo, hi);
		if (lo != hi) {
			lazy[si << 1] = StUpdate(lazy[si << 1], lazy[si]);
			lazy[si << 1 | 1] = StUpdate(lazy[si << 1 | 1], lazy[si]);
		}
		lazy[si] = StUpdate();
	}
 
	StVal query(const int l, const int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (l <= lo && hi <= r) return st[si];
 
		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}
 
	void update(const int l, const int r, const StUpdate u) { if (l <= r) update(l, r, u, 1, 0, n - 1); }
	void update(const int l, const int r, const StUpdate& u, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) {
			lazy[si] = StUpdate(lazy[si], u);
			updateLazy(si, lo, hi);
		}
		else {
			updateLazy(si, lo, hi);
			if (hi < l || r < lo) return;
			const int mid = (lo + hi) >> 1;
			update(l, r, u, si << 1, lo, mid);
			update(l, r, u, si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}
};
 
int main() {
	freopen("reflection.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int t; cin >> t;
	while (t--) {
		int Q; cin >> Q;
		SegTree st(1e5 + 1);
		while (Q--) {
			int x; cin >> x;
			StVal ans = st.query(x, x);
			int y = ans.a * x + ans.b;
			cout << y << '\n';
			st.update(x, 1e5, StUpdate(true, 2*y));
		}
	}
}