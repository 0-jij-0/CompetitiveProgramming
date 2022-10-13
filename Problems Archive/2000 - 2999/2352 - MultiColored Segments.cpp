#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX - 1;

struct Segment {
	int l, r, c, i, iL, iR; Segment() {}
	Segment(int _l, int _r, int _c, int _i) :
		l(_l), r(_r), c(_c), i(_i) {}
};

bool compareL(const Segment& A, const Segment& B)  {
	return A.l < B.l;
}

bool compareR(const Segment& A, const Segment& B)  {
	return A.r < B.r;
}

struct StVal1 {
	int X = 1 << 30, b = 1; StVal1() {}
	StVal1(int x) : X(x) {}
	StVal1(const StVal1& L, const StVal1& R) {
		if (L.b ^ R.b) { b = 1; X = L.b ? L.X : R.X; }
		else { b = L.b; X = min(L.X, R.X); }
	}
};

struct StVal2 {
	int X = 0, b = 1; StVal2() {}
	StVal2(int x) : X(x) {}
	StVal2(const StVal2& L, const StVal2& R) {
		if (L.b ^ R.b) *this = L.b ? L : R;
		else { b = L.b; X = max(L.X, R.X); }
	}
};

template<class StVal>
struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(int n, vector<int> &v) : n(n), leaves(n) { init(1, 0, n - 1, v); }

	void init(int si, int lo, int hi, vector<int> &v) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(v[lo]); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid, v);
			init(si << 1 | 1, mid + 1, hi, v);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	StVal query(int l, int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(int l, int r, int si, int lo, int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	//Currently Incremental Point Updates
	void update(int i) {
		int si = leaves[i]; st[si].b ^= 1;
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

vector<Segment> vL, vR;
vector<vector<Segment>> colors;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; colors.clear(); colors.resize(n);
		vR.clear(); for (int i = 0; i < n; i++) {
			int l, r, c; cin >> l >> r >> c;
			vR.emplace_back(l, r, --c, i);
		}

		sort(vR.begin(), vR.end(), compareL);
		for (int i = 0; i < n; i++) vR[i].iR = i;
		
		sort(vR.begin(), vR.end(), compareR);
		for (int i = 0; i < n; i++) vR[i].iL = i;
		for (int i = 0; i < n; i++) colors[vR[i].c].push_back(vR[i]);

		vL = vR; sort(vL.begin(), vL.end(), compareL);

		vector<int> L(n), R(n);
		for (int i = 0; i < n; i++) 
			L[vR[i].iL] = vR[i].l, R[vR[i].iR] = vR[i].r;

		SegTree<StVal1> stL(n, L);
		SegTree<StVal2> stR(n, R);

		vector<int> res(n, 1 << 30);
		for (int i = 0; i < n; i++) {
			for (auto& x : colors[i]) {
				stL.update(x.iL), stR.update(x.iR);
			}

			for (auto& x : colors[i]) {
				auto lastL = upper_bound(vL.begin(), vL.end(), Segment(x.r, 0, 0, 0), compareL) - vL.begin();
				auto firstR = lower_bound(vR.begin(), vR.end(), Segment(0, x.l, 0, 0), compareR) - vR.begin();
				auto valR = stR.query(0, lastL - 1); auto valL = stL.query(firstR, n - 1);
				int maxR = valR.b ? valR.X : -(1 << 30), minL = valL.b ? valL.X : INF;
				res[x.i] = min({ x.l - maxR, minL - x.r }); res[x.i] = max(0, res[x.i]);
			}

			for (auto& x : colors[i]) stL.update(x.iL), stR.update(x.iR);
		}

		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
}