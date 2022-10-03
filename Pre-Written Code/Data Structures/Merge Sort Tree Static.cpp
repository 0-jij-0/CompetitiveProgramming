//Does not handle updates
//Handles queries in O(log^2n)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> base;

struct StVal {
	int v = 0; vector<int> nums;
	StVal() {}
	StVal(const int _v) : v(_v) { nums.push_back(v); }
	StVal(const StVal& v1, const StVal& v2) {
		nums.resize(v1.nums.size() + v2.nums.size());
		merge(v1.nums.begin(), v1.nums.end(), v2.nums.begin(), v2.nums.end(), nums.begin());
	}
	operator int() const { return v; }	//Casts StVal to int
};

struct SegTree {
	int n;
	vector<int> leaves;
	vector<StVal> st;	//st[1] root, st[2] root's left child, st[3] root's right child...
	//To go to a child, *2 (l) or *2+1 (r)	To go to a parent: /2

	SegTree(const int n) : n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
	}

	//lo, hi indices of the actual array; si is the index of the segment tree array
	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) { st.resize(si + 1); }
			st[si] = StVal(base[lo]);			//Set the actual array here
			leaves[lo] = si;
			return;
		}
		int lC = si << 1, rC = (si << 1) | 1, mid = (lo + hi) >> 1;
		init(lC, lo, mid); init(rC, mid + 1, hi);
		st[si] = StVal(st[lC], st[rC]);
	}

	//l and r inclusive, 0-indexed
	//Returns num of elements > k
	int query(const int l, const int r, const int k) { return (l <= r && l < n&& r >= 0) ? query(l, r, k, 1, 0, n - 1) : StVal(); }
	int query(const int l, const int r, const int k, const int si, const int lo, const int hi) { 
		if (l <= lo && hi <= r) {
			return (hi - lo + 1) - (upper_bound(st[si].nums.begin(), st[si].nums.end(), k) - st[si].nums.begin());
		}

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, k, si << 1, lo, mid);
		if (mid < l) return query(l, r, k, si << 1 | 1, mid + 1, hi);
		return query(l, r, k, si << 1, lo, mid) + query(l, r, k, si << 1 | 1, mid + 1, hi);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}