//Handles queries on submatrices in O(log^2(nm))
//O(4nm) space

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> base;	//nxm

struct StVal {
	int v = 0; StVal() {}
	StVal(const int _v) : v(_v) {}
	StVal(const StVal& v1, const StVal& v2) { v = v1 + v2; }
	operator int() const { return v; }	//Casts StVal to int
};

struct SegTree2D {
	int n, m;
	vector<int> leaves1;
	vector<vector<int>> leaves2;
	vector<vector<StVal>> st;

	SegTree2D(const int n, const int m) : n(n), m(m) {
		leaves1.resize(n); leaves2.resize(n, vector<int>(m));
		init2D(1, 0, n - 1);
	}

	void init2D(const int si1, const int lo, const int hi) {
		if (lo == hi) {
			if (si1 >= (int)st.size()) { st.resize(si1 + 1); }
			init(si1, lo, 1, 0, m - 1);
			leaves1[lo] = si1;
			return;
		}
		int lC = si1 << 1, rC = (si1 << 1) | 1, mid = (lo + hi) >> 1;
		init2D(lC, lo, mid); init2D(rC, mid + 1, hi);
		st[si1].resize(st[lC].size());
		for (int i = 0; i < st[si1].size(); i++) {
			st[si1][i] = StVal(st[lC][i], st[rC][i]);	//Merges ALL the nodes of the children segment trees (not only leaves)
		}
	}

	//lo, hi indices of the actual array; si is the index of the segment tree array
	void init(const int si1, const int prevLo, const int si2, const int lo, const int hi) {
		if (lo == hi) {
			if (si2 >= (int)st[si1].size()) { st[si1].resize(si2 + 1); }
			st[si1][si2] = StVal(base[prevLo][lo]);			//Set the actual array here
			leaves2[prevLo][lo] = si2;
			return;
		}
		int lC = si2 << 1, rC = (si2 << 1) | 1, mid = (lo + hi) >> 1;
		init(si1, prevLo, lC, lo, mid); init(si1, prevLo, rC, mid + 1, hi);
		st[si1][si2] = StVal(st[si1][lC], st[si1][rC]);
	}

	//0-indexed, i is for rows, j for columns
	StVal query(int i1, int i2, int j1, int j2) const {
		if (i1 > i2 || j1 > j2) { return StVal(); }
		return query2D(1, 0, n - 1, i1, i2, j1, j2);
	}

	StVal query2D(int si, int lo, int hi, int i1, int i2, int j1, int j2) const {
		if (i1 <= lo && hi <= i2) return query(si, 1, j1, j2, 0, m - 1);

		const int mid = (lo + hi) >> 1;
		if (i2 <= mid) return query2D(si << 1, lo, mid, i1, i2, j1, j2);
		if (mid < i1) return query2D(si << 1 | 1, mid + 1, hi, i1, i2, j1, j2);
		return StVal(query2D(si << 1, lo, mid, i1, i2, j1, j2), query2D(si << 1 | 1, mid + 1, hi, i1, i2, j1, j2));
	}

	StVal query(int si1, int si2, int l, int r, int lo, int hi) const {
		if (l <= lo && hi <= r) return st[si1][si2];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(si1, si2 << 1, l, r, lo, mid);
		if (mid < l) return query(si1, si2 << 1 | 1, l, r, mid + 1, hi);
		return StVal(query(si1, si2 << 1, l, r, lo, mid), query(si1, si2 << 1 | 1, l, r, mid + 1, hi));
	}

	//Change a leaf and update its ancestors' values
	void update(const int i, const int j, int c) {
		int si1Init = leaves1[i], si2Init = leaves2[i][j];
		st[si1Init][si2Init] = StVal(c);

		for (int si2 = si2Init >> 1; si2; si2 >>= 1)
			st[si1Init][si2] = StVal(st[si1Init][si2 << 1], st[si1Init][si2 << 1 | 1]);

		for (int si1 = si1Init >> 1; si1; si1 >>= 1)
			for (int si2 = si2Init; si2; si2 >>= 1)
				st[si1][si2] = StVal(st[si1 << 1][si2], st[si1 << 1 | 1][si2]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


}