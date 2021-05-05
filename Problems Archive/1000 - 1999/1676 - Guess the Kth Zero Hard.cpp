#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <assert.h>
using namespace std;
typedef long long ll;

int query(bool b, int l, int r = 0) {
	if (!b) {
		cout << "? " + to_string(l) + " " + to_string(r) << endl;
		int s; cin >> s; return s;
	}
	cout << "! " + to_string(l) << endl;
	return 0;
}

vector<int> v;

struct StVal {
	ll v = 0; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal& v1, const StVal& v2) { v = v1 + v2; }
	operator ll() const { return v; }
};

struct StUpdate {
	ll v = 0; StUpdate() {}
	StUpdate(const ll v) : v(v) {}
	StUpdate(const StUpdate& u1, const StUpdate& u2) { v = u1 + u2; }
	operator ll() const { return v; }
	void apply(StVal& v, const int lo, const int hi) {
		v.v += this->v * (hi - lo + 1);
	}
};

struct SegTree {
	int n = 0; SegTree() {}
	vector<StVal> st;
	vector<StUpdate> lazy;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) {
		init(1, 0, n - 1); lazy.resize(st.size());
	}

	void init(const int si, const int lo, const int hi) {
		if (n == 0) { return; }
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(v[lo]); leaves[lo] = si;
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

SegTree st(0);

int findID(int k) {
	int l = 0, r = st.n - 1;
	while (l != r) {
		int mid = (l + r) >> 1;
		st.query(mid, mid) < k ? l = mid + 1 : r = mid;
	}
	return l;
}

int main() {
	int n, t; cin >> n >> t;
	v.resize((n + 31) / 32); bool ok = true;
	
	while (t--) {
		int k; cin >> k; if (ok) { 
			ok = false; for (int i = 0; i < n; i += 32) {
				int l = i, r = min(n - 1, i + 31);
				v[i / 32] = r - l + 1 - query(0, l + 1, r + 1);
			}
			partial_sum(v.begin(), v.end(), v.begin());
			st = SegTree((int)v.size()); int cur = 0;
		}
		
		int idx = findID(k);
		if (idx != 0) { k -= st.query(idx - 1, idx - 1); }

		int l = idx * 32, r = min(n - 1, l + 31);
		while (l != r) {
			int mid = (l + r) >> 1;
			int x = query(0, l + 1, mid + 1);
			int res = mid - l + 1 - x;
			if (res < k) { l = mid + 1, k -= res; }
			else { r = mid; }
		}
		query(1, l + 1); st.update(idx, st.n - 1, -1);
	}
	cin.ignore(2); return 0;
}