#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct StVal {
	int v = 0; StVal() {}
	StVal(const int _v) : v(_v) {}
	StVal(const StVal& L, const StVal& R) { v = max(L, R); }
	operator int() const { return v; }
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) { init(1, 0, n - 1); }

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

	StVal query(const int l, const int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i, int x) {
		int si = leaves[i]; st[si] = st[si] + x;
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	freopen("qatar.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T; while (T--) {
		int N, M, Q; cin >> N >> M >> Q;
		SegTree rows(N), cols(M); while (Q--) {
			int t; cin >> t; if (t < 3) {
				int A; cin >> A; --A;
				rows.update(A, t == 1 ? 1 : -1);
			} else if (t < 5) {
				int B; cin >> B; --B;
				cols.update(B, t == 3 ? 1 : -1);
			} else {
				int xs, ys, xe, ye; cin >> xs >> ys >> xe >> ye;
				if (--xs > --xe) { swap(xe, xs); }
				if (--ys > --ye) { swap(ys, ye); }
				int maxRow = rows.query(xs, xe), maxCol = cols.query(ys, ye);
				cout << (maxCol || maxRow ? -1 : max(ye - ys, xe - xs)) << '\n';
			}
		}
	}

}