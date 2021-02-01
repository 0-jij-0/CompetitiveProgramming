#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

string s, f;

struct StVal {
	int v = 0; StVal() {}
	StVal(const int _v) : v(_v) {}
	StVal(const StVal& v1, const StVal& v2) { v = v1 + v2; }
	operator int() const { return v; }
};

struct StUpdate {
	int v = -1; StUpdate() {}
	StUpdate(const int v) : v(v) {}
	StUpdate(const StUpdate& u1, const StUpdate& u2) { 
		v = (u2 == -1) ? u1 : u2;
	}
	operator int() const { return v; }
	void apply(StVal& V, const int lo, const int hi) {
		if (v == -1) { return; }
		V.v = this->v * (hi - lo + 1);
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
			st[si] = StVal(f[lo] - '0'); leaves[lo] = si;
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

vector<pair<int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, q; cin >> n >> q >> s >> f;
		SegTree st(n); Q.resize(q);
		for (auto& x : Q) { cin >> x.first >> x.second; }

		bool ok = true;
		for (int i = q - 1; i >= 0; i--) {
			int l = --Q[i].first, r = --Q[i].second;
			int v = st.query(l, r), len = (r - l + 1);
			if (len % 2 == 0 && v == len / 2) { ok = false; break; }
			st.update(l, r, v > (len / 2));
		}

		for (int i = 0; i < n && ok; i++)
			ok = ok && (st.query(i, i) == (s[i] - '0'));
		cout << (ok ? "YES" : "NO") << '\n';
	}

	cin.ignore(2); return 0;
}