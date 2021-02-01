#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

vector<ll> v;

struct StVal { // define
	ll mini = 1000000; int idx = -1; StVal() {}
	StVal(const StVal &v1, const StVal &v2) {
		if (v1.mini == v2.mini) {
			mini = v1.mini;	idx = max(v1.idx, v2.idx);
		}
		else if (v1.mini < v2.mini) {
			mini = v1.mini; idx = v1.idx;
		}
		else { mini = v2.mini; idx = v2.idx; }
	}
};

struct StUpdate { // define
	ll v = 0; // optional
	StUpdate() {}
	StUpdate(const ll v) : v(v) {} // optional
	StUpdate(const StUpdate &u1, const StUpdate &u2) { v = u1.v + u2.v; }
	operator ll() const { return v; } // optional
	void apply(StVal &v, const int lo, const int hi) { // omit last 2 arguments if non-lazy segment tree
		v.mini += this->v;
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
			if(si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
			leaves[lo] = si; st[si].mini = v[lo]; st[si].idx = lo;
		} else {
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
		} else {
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

	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	SegTree st(n);
	int i = 1;
	while (i <= n) {
		int idx = st.query(0, n - 1).idx;
		v[idx] = i;	st.update(idx + 1, n - 1, -i);
		i++; st.update(idx, idx, 1ll << 60);
	}
	for (int i = 0; i < n; i++) {
		cout << v[i];
		if (i + 1 != n) { cout << ' '; }
		else { cout << endl; }
	}
	cin.ignore(2); return 0;
}