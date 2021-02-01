#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

struct FT {
	int n; vector<int> vals; FT() {};
	FT(int n) : n(n), vals(n + 1, 0) {}

	void update(int i, int x) {
		for (++i; i <= n; i += i & -i) { vals[i] += x; }
	}

	int query(int i) const { // sum from 0 ... i assert(i >= -1 && i < n); 
		int sum = 0;
		for (++i; i; i -= i & -i) { sum += vals[i]; }
		return sum;
	}
	int query(int l, int r) { return query(r) - query(l - 1); }
};

const int MIN = 0, MAX = 1e6; //Min and max possible values in the array; [-1e9,1e9] are too much --> compress
vector<int> A, B; //A used to build wavelet tree B copy of A

//Wavelet Tree supports:
//Queries:  Kth element in a range // Number of elements = k in a range // Number of elements <= k in a range
//Updates:  Toggle elements ON/OFF
struct WaveletTree {
	int lVal, rVal; int n;
	WaveletTree *lC, *rC;
	vector<int> left; 		//left[i] = number of elements from the first i elements that go to left child
	FT aLeft, aRight, aLeaf; //Used to map the indices of range queries (we can deduce from it how much goes to the right child)

	WaveletTree(int _n) : WaveletTree(0, _n - 1, MIN, MAX) { }

	//Numbers are in the range [lVal, rVal]
	//Array indices are in [lo, hi]
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

	//Query #1: kth smallest element in [l, r]
	int kthSmallest(int l, int r, int k) {
		if (l > r) { return MAX + 2; }
		if (lVal == rVal) { return lVal; }

		int befL = (l ? left[l - 1] : 0);
		int inLeft = activeLeft(r) - activeLeft(l - 1);

		if (k <= inLeft) { return lC->kthSmallest(befL, left[r] - 1, k); }
		return rC->kthSmallest(l - befL, r - left[r], k - inLeft);
	}

	//Query #2: #numbers <= k in [l, r]
	int LessThanK(int l, int r, int k) {
		if (l > r || k < lVal) { return 0; }
		if (rVal <= k) {
			if (rVal == lVal) { return activeLeaf(r) - activeLeaf(l - 1); }
			return activeLeft(r) + activeRight(r) - activeLeft(l - 1) - activeRight(l - 1);
		}
		int befL = (l ? left[l - 1] : 0);
		return lC->LessThanK(befL, left[r] - 1, k) + rC->LessThanK(l - befL, r - left[r], k);
	}
	//EXTRA: x <= #numbers <= y in [l, r]
	int inRange(int l, int r, int x, int y) { return LessThanK(l, r, y) - LessThanK(l, r, x - 1); }

	//Query #3: #numbers = k in [l, r]
	int countK(int l, int r, int k) {
		if (l > r || k < lVal || k > rVal) { return 0; }
		if (lVal == rVal) { return activeLeaf(r) - activeLeaf(l - 1); }

		int mid = (lVal + rVal) >> 1, befL = (l ? left[l - 1] : 0);
		if (k <= mid) { return lC->countK(befL, left[r] - 1, k); }
		return rC->countK(l - befL, r - left[r], k);
	}

	//Update: Toggle an element ON or OFF
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

	cin.ignore(2); return 0;
}