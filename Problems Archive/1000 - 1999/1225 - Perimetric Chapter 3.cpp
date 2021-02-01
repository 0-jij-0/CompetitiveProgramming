#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

struct rect {
	ll x1, x2, h; rect() {}
	rect(ll _x1, ll _x2, ll _h) : x1(_x1), x2(_x2), h(_h) {}
};

vector<rect> v;
vector<ll> comp;

struct StVal {
	ll x1 = 0, x2 = 0, first = 0, last = 0;
	ll perim = 0; StVal() {}
	StVal(const int i) : x1(comp[i]), x2(comp[i + 1]), first(0), last(0), perim(0) {}
	StVal(const StVal &v1, const StVal &v2) { 
		x1 = v1.x1; x2 = v2.x2; first = v1.first; last = v2.last;
		perim = (v1.perim + v2.perim - 2 * min(v1.last, v2.first) + mod + mod) % mod;
	}
};

struct StUpdate {
	ll v = 0; StUpdate() {}
	StUpdate(const ll v) : v(v) {}
	StUpdate(const StUpdate &u1, const StUpdate &u2) { v = max(u1, u2); }
	operator ll() const { return v; }
	void apply(StVal &V, const int lo, const int hi) {
		if (v == 0) { return; }
		V.first = V.last = v;
		V.perim = 2 * (v + V.x2 - V.x1); 
		V.perim %= mod;
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
		lazy[si].apply(st[si], lo, hi);
		if (lo != hi) {
			lazy[si << 1] = StUpdate(lazy[si << 1], lazy[si]);
			lazy[si << 1 | 1] = StUpdate(lazy[si << 1 | 1], lazy[si]);
		}
		lazy[si] = StUpdate();
	}

	StVal query() { return query(0, n - 1, 1, 0, n - 1); }
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

int main() {
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");

	int T; ifs >> T;
	for (int t = 1; t <= T; t++) {
		int n, k; ifs >> n >> k; v.resize(n); comp.clear();
		for (int i = 0; i < k; i++) ifs >> v[i].x1;
		ll AL, BL, CL, DL; ifs >> AL >> BL >> CL >> DL;
		for (int i = 0; i < k; i++) ifs >> v[i].x2;
		ll AW, BW, CW, DW; ifs >> AW >> BW >> CW >> DW;
		for (int i = 0; i < k; i++) ifs >> v[i].h;
		ll AH, BH, CH, DH; ifs >> AH >> BH >> CH >> DH;

		for (int i = k; i < n; i++) {
			v[i].x1 = 1 + ((v[i - 2].x1 * AL) % DL + (v[i - 1].x1 * BL) % DL + CL) % DL;
			v[i].x2 = 1 + ((v[i - 2].x2 * AW) % DW + (v[i - 1].x2 * BW) % DW + CW) % DW;
			v[i].h = 1 + ((v[i - 2].h * AH) % DH + (v[i - 1].h * BH) % DH + CH) % DH;
		}
		for (int i = 0; i < n; i++) {
			comp.push_back(v[i].x1); 
			comp.push_back(v[i].x2 += v[i].x1);
		}
		sort(comp.begin(), comp.end());
		comp.erase(unique(comp.begin(), comp.end()), comp.end());

		ll res = 1; SegTree st((int)comp.size() - 1);
		for (int i = 0; i < n; i++) {
			ll l = v[i].x1, r = v[i].x2;
			l = lower_bound(comp.begin(), comp.end(), l) - comp.begin();
			r = lower_bound(comp.begin(), comp.end(), r) - comp.begin() - 1;
			st.update(l, r, v[i].h); res = (res * st.query().perim) % mod;
		}
		ofs << "Case #" << t << ": " << res << '\n';
	}
	return 0;
}