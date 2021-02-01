#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct StVal {
	ll v = 0; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal &v1, const StVal &v2) { v = v1 + v2; }
	operator ll() const { return v; }
};

struct StUpdate {
	ll x = 0; StUpdate() {}
	StUpdate(const ll v) : x(v) {}
	StUpdate(const StUpdate &u1, const StUpdate &u2) { x = max(u1, u2); }
	operator ll() const { return x; }
	void apply(StVal &v, const int lo, const int hi) {
		if (lo == hi) { v.v = max(v.v, x); }
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

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(); leaves[lo] = si;
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

	void updateAllLazy() { updateAllLazy(1, 0, n - 1); }
	void updateAllLazy(const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (lo != hi) {
			const int mid = (lo + hi) >> 1;
			updateAllLazy(si << 1, lo, mid);
			updateAllLazy(si << 1 | 1, mid + 1, hi);
		}
	}

	vector<ll> retreive() {
		updateAllLazy();
		vector<ll> res(n);
		for (int i = 0; i < n; ++i)
			res[i] = st[leaves[i]].v;
		return move(res);
	}
};

vector<int> monsters;
vector<pair<int, int>> heroes;

int find_min_days(vector<ll> &v) {
	if (*max_element(monsters.begin(), monsters.end()) > max_element(heroes.begin(), heroes.end())->first) { return -1; }
	int d = 1; int cur = 1, max_p = 0;
	for (int i = 0; i < (int)monsters.size(); i++) {
		max_p = max(max_p, monsters[i]);
		if (v[cur] >= max_p) { cur++; continue; }
		d++; cur = 1; i--; max_p = 0;
	}
	return d;
}

int main() {
	int t; cin >> t;
	while (t--) {
		heroes.clear(); monsters.clear();
		int n; cin >> n; monsters.resize(n);
		for (auto &x : monsters) { cin >> x; }
		int m; cin >> m; heroes.resize(m);
		for (auto &x : heroes) { cin >> x.first >> x.second; }

		SegTree st(n + 1);
		for (auto &x : heroes) { st.update(1, x.second, x.first); }
		vector<ll> v = st.retreive();
		//for (auto &x : v) { cout << x << ' '; }
		cout << find_min_days(v) << endl;
	}
	cin.ignore(2); return 0;
}