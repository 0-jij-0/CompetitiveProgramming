#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long ll;

const double inf = 1000 * 1000 * 1000 + 0.0;

struct StVal { // define
	double v = -inf; int w = 0;
	StVal() {}
	StVal(const StVal &v1, const StVal &v2) {
		if (v1.w == 0 && v2.w == 0) { v = 0.0, w = 0; }
		else {
			v = (v1.v*v1.w + v2.v*v2.w) / (v1.w + v2.w + 0.0);
			w = v1.w + v2.w;
		}
	}
	operator double() const { return v; } // optional
};

struct StUpdate { // define
	double v = 0.0; // optional
	StUpdate() {}
	StUpdate(double _v) : v(_v) {}
	StUpdate(const StUpdate &u1, const StUpdate &u2) { v = u1 + u2; }
	operator double() const { return v; } // optional
	void apply(StVal &v, const int lo, const int hi) {
		v.v += this->v;
		if (v.v == -inf && v.w != 0) { v.w--; }
		else if (v.v != -inf && hi == lo) { v.w = 1; }
	}
};

struct SegTree {
	int n, size;
	vector<StVal> st;
	vector<StUpdate> lazy;
	vector<int> leaves;

	SegTree(const int n) : n(n), size(0) {
		leaves.resize(n);
		init(1, 0, n - 1);
		lazy.resize(st.size());
	}

	void init(const int si, const int lo, const int hi) { // init st[] and leaves[]
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
			leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]); // optional if T(T(), T()) = T()
		}
	}

	void updateLazy(const int si, const int lo, const int hi) {
		lazy[si].apply(st[si], lo, hi);
		if (lo != hi) {
			lazy[si << 1] = StUpdate(lazy[si << 1], lazy[si]);
			lazy[si << 1 | 1] = StUpdate(lazy[si << 1 | 1], lazy[si]);
		}
		lazy[si] = StUpdate();
	}

	StVal query(const int l, const int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}


	void update(const int l, const int r, const StUpdate u) { if (l <= r) update(l, r, u, 1, 0, n - 1); }
	void update(const int l, const int r, const StUpdate &u, const int si, const int lo, const int hi) {
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
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n; SegTree st(n + 1);
	st.update(0, 0, inf); st.size++;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		if (t == 1) {
			int a, x; cin >> a >> x;
			st.update(0, a - 1, x + 0.0);
		}
		else if (t == 2) {
			int k; cin >> k;
			st.update(st.size, st.size, inf + k);
			st.size++;
		}
		else {
			double k = st.query(st.size - 1, st.size - 1).v;
			st.size--; st.update(st.size, st.size, -k - inf);
		}
		double avg = st.query(0, n);
		cout << fixed << setprecision(10) << avg << endl;
	}
	cin.ignore(2); return 0;
}