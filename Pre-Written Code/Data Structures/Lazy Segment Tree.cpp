#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct StVal { 
	ll v = 0; StVal() {}
	StVal(ll _v) : v(_v) {}
	StVal(const StVal &L, const StVal &R) { v = L + R; }
	operator ll() const { return v; }
};

struct StUpdate {
	ll u = 0; StUpdate() {}
	StUpdate(ll v) : u(v) {} 
	StUpdate(const StUpdate &oldU, const StUpdate &newU) { u = oldU + newU; }
	operator ll() const { return u; }
	void apply(StVal &v, int lo, int hi) {
		v.v += u * (hi - lo + 1);
	}
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<StUpdate> lazy;
	vector<int> leaves;

	SegTree(int n) : n(n), leaves(n) {
		init(1, 0, n - 1); lazy.resize(st.size());
	}

	void init(int si, int lo, int hi) {
		if (lo == hi) {
			if(si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(); leaves[lo] = si;
		} else {
			int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	void updateLazy(int si, int lo, int hi) {
		lazy[si].apply(st[si], lo, hi);
		if (lo != hi) {
			lazy[si << 1] = StUpdate(lazy[si << 1], lazy[si]);
			lazy[si << 1 | 1] = StUpdate(lazy[si << 1 | 1], lazy[si]);
		}
		lazy[si] = StUpdate();
	}

	StVal query(int l, int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(int l, int r, int si, int lo, int hi) {
		updateLazy(si, lo, hi);
		if (l <= lo && hi <= r) return st[si];
		
		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(int l, int r, StUpdate u) { if (l <= r) update(l, r, u, 1, 0, n - 1); }
	void update(int l, int r, StUpdate &u, int si, int lo, int hi) {
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

	void update(int i, int x) {
		int si = leaves[i]; st[si] = st[si] + x;
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}

	void updateAllLazy() { updateAllLazy(1, 0, n - 1); }
	void updateAllLazy(int si, int lo, int hi) {
		updateLazy(si, lo, hi);
		if (lo != hi) {
			const int mid = (lo + hi) >> 1;
			updateAllLazy(si << 1, lo, mid);
			updateAllLazy(si << 1 | 1, mid + 1, hi);
		}
	}

	vector<StVal> retreive() {
		updateAllLazy();
		vector<StVal> res(n);
		for (int i = 0; i < n; ++i)
			res[i] = st[leaves[i]];
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}