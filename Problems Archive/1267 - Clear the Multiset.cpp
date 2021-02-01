#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v;

struct StVal {
	int minVal = 1 << 30, minIdx = 0; StVal() {}
	StVal(const int _v, const int i) : minVal(_v), minIdx(i) {}
	StVal(const StVal &v1, const StVal &v2) { 
		if (v1 <= v2) { minVal = v1; minIdx = v1.minIdx; }
		else { minVal = v2; minIdx = v2.minIdx; }
	}
	operator int() const { return minVal; }
};

struct StUpdate {
	int v = 0; StUpdate() {}
	StUpdate(const int v) : v(v) {}
	StUpdate(const StUpdate &u1, const StUpdate &u2) { v = u1 + u2; }
	operator int() const { return v; }
	void apply(StVal &V) { V.minVal -= v; }
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

	void updateLazy(const int si, const int lo, const int hi) {
		lazy[si].apply(st[si]);
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

	void update(const int i) {
		int si = leaves[i];
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}

	void updateAllLazy() { updateAllLazy(1, 0, n - 1); }
	void updateAllLazy(const int si, const int lo, const int hi) {
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
		return move(res);
	}
};

int minOpNum(int l, int r, SegTree &st) {
	if (l > r) { return 0; }
	if (l == r) { return st.query(l, l) != 0; }
	int add = 0; StVal q = st.query(l, r);
	if (q.minVal) { add = q.minVal; st.update(l, r, q.minVal); }
	int left = minOpNum(l, q.minIdx - 1, st);
	int right = minOpNum(q.minIdx + 1, r, st);
	return min(add + left + right, r - l + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	SegTree st(n); int res = minOpNum(0, n - 1, st);
	cout << res << '\n'; cin.ignore(2); return 0;
}