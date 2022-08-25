#include <iostream>
#include <vector>
using namespace std;

struct StVal {
	int sum = 0; StVal() {}
	StVal(const int v) : sum(v) {}
	StVal(const StVal& v1, const StVal& v2) { sum = v1.sum + v2.sum; }
};

struct StUpdate {
	bool inv = 0; StUpdate() {}
	StUpdate(const bool b) : inv(b) {}
	StUpdate(const StUpdate& oldU, const StUpdate& newU) { inv = oldU ^ newU; }
	operator bool() const { return inv; }
	void apply(StVal& v, int lo, int hi) { 
		if (inv) v.sum = hi - lo + 1 - v.sum;
	}
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<StUpdate> lazy;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) {
		init(1, 0, n - 1); lazy.resize(st.size());
	}

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
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

	int query(int k) { return query(1, 0, n - 1, k); }
	int query(const int si, const int lo, const int hi, int k) {
		updateLazy(si, lo, hi);
		if (lo == hi) { return lo; }
		const int mid = (lo + hi) >> 1;
		updateLazy(si << 1, lo, mid);
		if (st[si << 1].sum > k) { return query(si << 1, lo, mid, k); }
		return query(si << 1 | 1, mid + 1, hi, k - st[si << 1].sum);
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
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	SegTree st(n); while (m--) {
		int t; cin >> t; if (--t) {
			int k; cin >> k;
			cout << st.query(k) << '\n';
		}
		else {
			int l, r; cin >> l >> r;
			st.update(l, --r, true);
		}
	}

	cout << '\n';
}