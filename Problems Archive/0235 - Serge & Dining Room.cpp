#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

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

	void update(const int i, bool inc) { // single index update, [!!!] NON-LAZY SEGMENT TREE ONLY !!!
		int si = leaves[i];
		st[si].sum += (inc) ? 1 : -1; st[si].m = min(st[si].sum, 0);
		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}

	int traverse() {
		int si = 1; if (st[si].m >= 0) { return -1; }
		int sum = 0, lo = 0, hi = 1000000;
		while (lo != hi) {
			int mid = (lo + hi) >> 1;
			int left = si << 1, right = left + 1;
			if (right < (int) st.size() && sum + st[right].m < 0) {
				lo = mid + 1; si = right; continue;
			}
			hi = mid, sum += st[right].sum; si = left;
		}
		return lo;
	}
};

struct StVal { // define
	int sum = 0, m = 0; // optional
	StVal() {}
	StVal(const StVal &v1, const StVal &v2) { 
		sum = v1.sum + v2.sum;
		m = min(v2.m, v2.sum + v1.m);
	}
};

typedef SegTree<StVal> MyST;
int n, m, q;
vector<int> a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	a.resize(n); b.resize(m);
	for (auto &x : a) { cin >> x; }
	for (auto &x : b) { cin >> x; }

	MyST st(1000001);
	for (auto &x : a) { st.update(x, false); }
	for (auto &x : b) { st.update(x, true); }
	

	cin >> q;
	for (int j = 0; j < q; j++) {
		int c, i, x; cin >> c >> i >> x; i--;
		if (c == 1) { st.update(a[i], true); a[i] = x; st.update(a[i], false); }
		else { st.update(b[i], false); b[i] = x; st.update(b[i], true); }
		cout << st.traverse() << endl;
	}

	cin.ignore(2); return 0;
}