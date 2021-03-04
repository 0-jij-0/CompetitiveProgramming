#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> a;

struct StVal {
	int v = 1, maxV = 0; ll vS = 0; StVal() {}
	StVal(const int _v) : v(_v), vS(_v), maxV(_v) {}
	StVal(const StVal& v1, const StVal& v2) {
		v = v1.v & v2.v; vS = v1.vS + v2.vS;
		maxV = max(v1.maxV, v2.maxV);
	}
};

struct SegTree {
	int n; vector<StVal> st;
	SegTree(const int n) : n(n) { init(1, 0, n - 1); }

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) { st.resize(si + 1); }
			st[si] = StVal(a[lo]); return;
		}
		int lC = si << 1, rC = (si << 1) | 1, mid = (lo + hi) >> 1;
		init(lC, lo, mid); init(rC, mid + 1, hi);
		st[si] = StVal(st[lC], st[rC]);
	}

	void query1(const int l, const int r) { query1(l, r, 1, 0, n - 1); }
	void query1(const int l, const int r, const int si, const int lo, const int hi) {
		if (lo == hi) { st[si].v = st[si].vS = st[si].maxV = (st[si].v | (st[si].v - 1)); return; }
		if (l <= lo && hi <= r && (st[si].v & 1)) return;

		const int mid = (lo + hi) >> 1;
		if (r <= mid) query1(l, r, si << 1, lo, mid);
		else if (mid < l) query1(l, r, si << 1 | 1, mid + 1, hi);
		else {
			query1(l, r, si << 1, lo, mid);
			query1(l, r, si << 1 | 1, mid + 1, hi);
		}

		st[si] = StVal(st[si << 1], st[(si << 1) | 1]);
	}

	void query2(const int l, const int r) { query2(l, r, 1, 0, n - 1); }
	void query2(const int l, const int r, const int si, const int lo, const int hi) {
		if (lo == hi) { st[si].v = st[si].vS = st[si].maxV = (st[si].v ^ (st[si].v - 1)); return; }
		if (l <= lo && hi <= r && st[si].maxV == 1) return;

		const int mid = (lo + hi) >> 1;
		if (r <= mid) query2(l, r, si << 1, lo, mid);
		else if (mid < l) query2(l, r, si << 1 | 1, mid + 1, hi);
		else {
			query2(l, r, si << 1, lo, mid);
			query2(l, r, si << 1 | 1, mid + 1, hi);
		}

		st[si] = StVal(st[si << 1], st[(si << 1) | 1]);
	}
};

int main() {
	freopen("orxor.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q; a.resize(n); 
	for (auto& x : a) { cin >> x; }

	SegTree st(n); while (q--) {
		int t, l, r; cin >> t >> l >> r; l--; r--;
		t == 1 ? st.query1(l, r) : st.query2(l, r);
		cout << st.st[1].vS << '\n';
	}

	cin.ignore(2); return 0;
}