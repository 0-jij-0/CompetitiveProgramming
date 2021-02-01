#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> X, Y;

struct Rect {
	int x1, x2, y1, y2; Rect() {}
	Rect(int _x1, int _x2, int _y1, int _y2) :
		x1(_x1), x2(_x2), y1(_y1), y2(_y2) {}
};

struct StVal {
	ll e = 0, o = 0; StVal() {}
	StVal(const int i) : e(X[i + 1] - X[i]) {}
	StVal(const StVal &v1, const StVal &v2) { 
		o = v1.o + v2.o; e = v1.e + v2.e;
	}
	operator ll() const { return o; }
};

struct StUpdate {
	ll v = 0; StUpdate() {}
	StUpdate(const ll v) : v(v) {}
	StUpdate(const StUpdate &u1, const StUpdate &u2) { v = u1 + u2; }
	operator ll() const { return v; }
	void apply(StVal &V) { if (v & 1) swap(V.e, V.o); }
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
			st[si] = StVal(lo); leaves[lo] = si;
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
};

vector<vector<pair<int, int>>> start, endd;
vector<Rect> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; start.resize(200001); endd.resize(200001);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		v.emplace_back(x1, x2, y1, y2);
		X.push_back(x1); X.push_back(x2);
		Y.push_back(y1); Y.push_back(y2);
	}
	sort(X.begin(), X.end()); sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());

	for (int i = 0; i < n; i++) {
		int LX = lower_bound(X.begin(), X.end(), v[i].x1) - X.begin();
		int RX = lower_bound(X.begin(), X.end(), v[i].x2) - X.begin();
		int SY = lower_bound(Y.begin(), Y.end(), v[i].y1) - Y.begin();
		int EY = lower_bound(Y.begin(), Y.end(), v[i].y2) - Y.begin();
		start[SY].push_back({ LX, RX - 1 }); endd[EY].push_back({ LX, RX - 1 });
	}

	int N = (int)X.size(), M = (int)Y.size();
	SegTree st(N - 1); ll res = 0;
	for (int i = 0; i < M - 1; i++) {
		for (auto &x : start[i]) st.update(x.first, x.second, 1);
		for (auto &x : endd[i]) st.update(x.first, x.second, 1);
		res += st.query(0, N - 2) * (Y[i + 1] - Y[i]);
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}