#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> a, b;

struct StVal { // define
	ll v = 0; // optional
	StVal() {}
	StVal(const ll _v) : v(_v) {} // optional
	StVal(const StVal &v1, const StVal &v2) { v = v1 + v2; }
	operator ll() const { return v; } // optional
};

struct StUpdate { // define
	int v = -1;
	StUpdate() {}
	StUpdate(const int v) : v(v) {} // optional
	void apply(StVal &s, const int lo, const int hi) {
		if (v != -1) { s.v = a[v]; }
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

	void init(const int si, const int lo, const int hi) { // init st[] and leaves[]
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
			leaves[lo] = si; st[si] = b[lo];
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]); // optional if T(T(), T()) = T()
		}
	}

	void updateLazy(const int si, const int lo, const int hi) {
		if (lazy[si].v == -1) { return; }
		lazy[si].apply(st[si], lo, hi);
		if (lo != hi) {	
			int l = lazy[si].v, mid = l + ((hi - lo) >> 1);
			lazy[si << 1].v = l;
			lazy[si << 1 | 1].v = mid + 1;
		}
		lazy[si] = StUpdate();
	}

	StVal query(const int l, const int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) { return query(l, r, si << 1, lo, mid); }
		if (mid < l) { return query(l, r, si << 1 | 1, mid + 1, hi); }
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}


	void update(const int y, const int x, const int k) { update(y, x, k, 1, 0, n - 1); }
	void update(const int y, const int x, const int k, const int si, const int lo, const int hi) {
		int l = y, r = y + k - 1;
		if (l <= lo && hi <= r) {
			lazy[si].v = x + lo - y;
			updateLazy(si, lo, hi);
		}
		else {
			updateLazy(si, lo, hi);
			if (hi < l || r < lo) return;
			const int mid = (lo + hi) >> 1;
			update(y, x, k, si << 1, lo, mid);
			update(y, x, k, si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	a.resize(n); b.resize(n);
	for (auto &x : a) { cin >> x; }
	for (auto &x : b) { cin >> x; }
	SegTree st(n);

	for (int i = 0; i < m; i++) {
		int c; cin >> c;
		if (c == 1) {
			int x, y, k; cin >> x >> y >> k;
			x--; y--; st.update(y, x, k);
		}
		else {
			int x; cin >> x; x--;
			cout << st.query(x, x).v << endl;
		}
	}

	cin.ignore(2); return 0;
}