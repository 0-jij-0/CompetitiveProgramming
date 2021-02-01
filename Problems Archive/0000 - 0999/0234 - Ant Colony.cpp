#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

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

	void update(const int i, int x) { 
		int si = leaves[i];
		st[si].min = st[si].g = x; st[si].count = 1;
		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}
};

struct StVal { // define
	int g = 0, min = 0, count = 0;
	StVal() {}
	StVal(const StVal &v1, const StVal &v2) { 
		g = gcd(v1.g, v2.g);
		if (v1.min == v2.min) {
			min = v1.min; count = v1.count + v2.count;
		}
		else {
			min = (v1.min < v2.min) ? v1.min : v2.min;
			count = (v1.min < v2.min) ? v1.count : v2.count;
		}
	}
};

typedef SegTree<StVal> MyST;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; MyST st(n);
	for (int i = 0; i < n; i++) {
		int a; cin >> a; st.update(i, a);
	}
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int l, r; cin >> l >> r;
		StVal v = st.query(l - 1, r - 1);
		if (v.g != v.min) { cout << r - l + 1 << endl; continue; }
		cout << r - l + 1 - v.count << endl;
	}

	cin.ignore(2); return 0;
}