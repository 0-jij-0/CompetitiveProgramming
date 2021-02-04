#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct StVal {
	int value = 0;
	StVal *left = NULL, *right = NULL;
	StVal() {}
	StVal(const int _v) : value(_v) { left = right = NULL; }
	StVal(StVal* v1, StVal* v2) {	//v1, v2 are never NULL
		value = *v1 + *v2;
		left = v1; right = v2;
	}
	operator int() const { return value; }
};

struct PSSegTree{
	int n;
	vector<StVal*> versions;	//contains the root of each version, 1-based since version 0 is the empty segtree
	vector<StVal*> st;	//st[1] is the root

	PSSegTree(const int n) : n(n) { init(1, 0, n - 1); versions.push_back(st[1]); }

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = new StVal();
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = new StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	//l and r inclusive, 0-indexed, version v
	StVal* query(const int l, const int r, const int v = 0) {
		return (l <= r && l < n && r >= 0) ? query(l, r, versions[v], 0, n - 1) : new StVal();
	}
	StVal* query(const int l, const int r, StVal* si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return si;

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si->left, lo, mid);
		if (mid < l) return query(l, r, si->right, mid + 1, hi);
		return new StVal(query(l, r, si->left, lo, mid), query(l, r, si->right, mid + 1, hi));
	}

	//PERSISTENT UPDATE
	//v version, i idx, nx new INCREMENT
	StVal* PSUpdate(int v, int i, int nx) {
		int curVal = query(i, i, v)->value + nx;	//increment by nx, remove if we want to assign or if the query returns smthg else
		return PSUpdate(0, n - 1, i, curVal, versions[v]);
	}
	StVal* PSUpdate(int l, int r, int i, int nx, StVal* cur) {
		if (l == r) {
			StVal* nv = new StVal(nx);
			if (l == 0 && r == n - 1) { versions.push_back(nv); }
			return nv;
		}
		int m = (l + r) >> 1;
		if (i <= m) {
			StVal* nl = PSUpdate(l, m, i, nx, cur->left);
			StVal* par = new StVal(nl, cur->right);
			if (l == 0 && r == n - 1) { versions.push_back(par); }
			return par;
		}
		else {
			StVal* nr = PSUpdate(m + 1, r, i, nx, cur->right);
			StVal* par = new StVal(cur->left, nr);
			if (l == 0 && r == n - 1) { versions.push_back(par); }
			return par;
		}
	}
};