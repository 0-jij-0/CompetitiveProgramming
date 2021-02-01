#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;
typedef long long ll;

struct FT {
	int n; vector<int> vals; FT() {};
	FT(int n) : n(n) { vals.resize(n + 1, 0); }

	void update(int i, int x) {
		for (++i; i <= n; i += i & -i) { vals[i] += x; }
	}

	int query(int i) const { 
		int sum = 0;
		for (++i; i; i -= i & -i) { sum += vals[i]; }
		return sum;
	}
	int query(int l, int r) { return query(r) - query(l - 1); }
};

const int MIN = 0, MAX = 100002;
vector<int> A, B; 

struct WaveletTree {
	int lVal, rVal; int n;
	WaveletTree *lC, *rC;
	vector<int> left; 		
	FT aLeft, aRight, aLeaf; 

	WaveletTree(int _n) : WaveletTree(0, _n - 1, MIN, MAX) { }

	WaveletTree(int lo, int hi, int x, int y) {
		lVal = x; rVal = y; n = hi - lo + 1;
		if (lVal == rVal || hi < lo) { 
			aLeaf = FT(n);
			for (int i = 0; i < n; i++) { aLeaf.update(i, 1); }
			return;
		}
		aLeft = aRight = FT(n); int mid = (lVal + rVal) >> 1, back = 0;
		for (int i = lo; i <= hi; i++) {
			left.push_back(back += (A[i] <= mid));
			(A[i] <= mid ? aLeft : aRight).update(i - lo, 1);
		}

		auto comp = [&](const int &x) { return x <= mid; };
		int pivot = stable_partition(A.begin() + lo, A.begin() + hi + 1, comp) - A.begin();
		lC = new WaveletTree(lo, pivot - 1, lVal, mid);
		rC = new WaveletTree(pivot, hi, mid + 1, rVal);
	}

	inline int activeLeft(const int &i) { return (i >= 0 && i < n) ? aLeft.query(i) : 0; }
	inline int activeLeaf(const int &i) { return (i >= 0 && i < n) ? aLeaf.query(i) : 0; }
	inline int activeRight(const int &i) { return (i >= 0 && i < n) ? aRight.query(i) : 0; }
	inline int mapLeft(const int &i) { return (i >= 0 && i < n) ? left[i] - 1 : 0; }
	inline int mapRight(const int &i) { return (i >= 0 && i < n) ? i - left[i] : 0; }

	int LessThanK(int l, int r, int k) {
		if (l > r || k < lVal) { return 0; }
		if (rVal <= k) { 
			if(rVal == lVal){ return activeLeaf(r) - activeLeaf(l - 1); }
			return activeLeft(r) + activeRight(r) - activeLeft(l - 1) - activeRight(l - 1); 			
		}
		int befL = (l ? left[l - 1] : 0);
		return lC->LessThanK(befL, left[r] - 1, k) + rC->LessThanK(l - befL, r - left[r], k);
	}
	int inRange(int l, int r, int x, int y) { return LessThanK(l, r, y) - LessThanK(l, r, x - 1); }

	void toggle(int i) { if (i >= 0 && i < n) return toggle(i, B[i]); }
	void toggle(int i, const int &x) {
		if (lVal == rVal) { return aLeaf.update(i, aLeaf.query(i, i) ? -1 : 1); }
		int mid = (lVal + rVal) >> 1; FT &ft = x <= mid ? aLeft : aRight;
		ft.update(i, ft.query(i, i) ? -1 : 1);
		if (x > mid) { return rC->toggle(mapRight(i), x); }
		return lC->toggle(mapLeft(i), x);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q; A.resize(n);
	vector<vector<int>> occ(n); map<int, int> comp;
	for (auto &x : A) { cin >> x; comp[x]++; }
	int id = 0; for (auto &x : comp) { x.second = id++; }
	for (int i = 0; i < n; i++) { A[i] = comp[A[i]]; occ[A[i]].push_back(i); }
	B = A; WaveletTree T(n);

	while (q--) {
		int t; cin >> t;
		if (t) { int i; cin >> i; T.toggle(i); continue; }
		int i, l, k; cin >> i >> l >> k;
		if (!comp.count(k)) { cout << 0 << '\n'; continue; }
		cout << T.inRange(i, l, comp[k], comp[k]) << '\n';
	}

	cin.ignore(2); return 0;
}