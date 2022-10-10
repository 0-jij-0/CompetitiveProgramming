#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;

struct StVal {
	int v = 0, idx = 0; StVal() {}
	StVal(const int _v, int _id) : v(_v), idx(_id) {}
	StVal(const StVal &v1, const StVal &v2) { 
		if (v1 < v2) { v = v1; idx = v1.idx; }
		else { v = v2; idx = v2.idx; }
	}
	operator int() const { return v; }
};

struct StUpdate {
	int v = 0; StUpdate() {}
	StUpdate(const int v) : v(v) {}
	StUpdate(const StUpdate &u1, const StUpdate &u2) { v = u1 + u2; }
	operator int() const { return v; }
	void apply(StVal &V) { V.idx += v; }
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
			st[si] = StVal(v[lo], lo); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	void updateLazy(const int si, const int &lo, const int &hi) {
		lazy[si].apply(st[si]);
		if (lo != hi) {
			lazy[si << 1] = StUpdate(lazy[si << 1], lazy[si]);
			lazy[si << 1 | 1] = StUpdate(lazy[si << 1 | 1], lazy[si]);
		}
		lazy[si] = StUpdate();
	}

	StVal query(const int l, const int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int &l, const int &r, const int si, const int lo, const int hi) {
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

	void update(const int i) {
		int si = leaves[i]; st[si].v = 1 << 30;
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	SegTree st(n); int l = 0, r = n - 1;
	vector<int> a(n); iota(a.begin(), a.end(), 0);
	auto comp = [&](const int &i, const int &j) {return v[i] < v[j]; };
	sort(a.begin(), a.end(), comp); ll res = 0; 
	
	for(int i = 0; i < n; i++) {
		int idx = st.query(a[i], a[i]).idx; st.update(a[i]);
		if (idx - l < r - idx) { res += idx - l++; st.update(0, a[i] - 1, 1); }
		else { res += r-- - idx; st.update(a[i] + 1, n - 1, -1); }
	}
	cout << res << '\n';
}