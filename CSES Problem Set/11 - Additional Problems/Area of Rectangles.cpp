#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct StVal {
	int minVal = 0, minCount = 1; StVal() {}
	StVal(int _v) : minVal(_v), minCount(1) {}
	StVal(const StVal& L, const StVal& R) { 
		*this = (L.minVal < R.minVal) ? L : R;
		if (L.minVal == R.minVal) minCount += L.minCount;
	}
};

struct StUpdate {
	int u = 0; StUpdate() {}
	StUpdate(int v) : u(v) {}
	StUpdate(const StUpdate& oldU, const StUpdate& newU) { u = oldU + newU; }
	operator int() const { return u; }
	void apply(StVal& v, int lo, int hi) { v.minVal += u; }
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
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(); leaves[lo] = si;
		}
		else {
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

	StVal query(int l, int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(int l, int r, int si, int lo, int hi) {
		updateLazy(si, lo, hi);
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(int l, int r, StUpdate u) { if (l <= r) update(l, r, u, 1, 0, n - 1); }
	void update(int l, int r, StUpdate& u, int si, int lo, int hi) {
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

struct Event {
	int u, x, L, R; Event() {}
	Event(int _u, int _x, int _L, int _R) : 
		u(_u), x(_x), L(_L), R(_R) {}

	bool operator < (const Event& rhs) const { return x < rhs.x; }
};

vector<Event> events;

int yL = -1000000, yR = 1000000;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; SegTree st(yR - yL);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		events.emplace_back(1, x1, y1 - yL, --y2 - yL);
		events.emplace_back(-1, x2, y1 - yL, y2 - yL);
	}

	sort(events.begin(), events.end()); n <<= 1;
	auto executeEvent = [&](const Event& e) { st.update(e.L, e.R, e.u); };

	ll res = 0;
	for (int i = events.front().x, j = 0; i <= events.back().x; i++) {
		while (j != n && events[j].x == i) { executeEvent(events[j++]); }
		StVal V = st.query(0, yR - yL - 1);
		res += yR - yL - (V.minVal == 0) * V.minCount;
	}

	cout << res << '\n';
}