#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;

vector<int> A, B; //A used to build wavelet tree B copy of A

//Wavelet Tree supports:
//Queries:  Kth element in a range // Number of elements = k in a range // Number of elements <= k in a range
//Updates:  Swap two consecutive elements // Toggle elements (on elements are counted in queries; off elements aren't)
//Updates not implemented yet
struct WaveletTree {
	int lVal, rVal; int n = 0;
	WaveletTree *lC = nullptr, *rC = nullptr;
	vector<int> left; 		//left[i] = number of elements from the first i elements that go to left child
							//Used to map the indices of range queries (we can deduce from it how much goes to the right child)

	WaveletTree(int _n, int MIN, int MAX) : WaveletTree(0, n = _n - 1, MIN, MAX) {}
	~WaveletTree() { if (lC != nullptr) delete lC; if (rC != nullptr) delete rC; }

	//Numbers are in the range [lVal, rVal]
	//Array indices are in [lo, hi]
	WaveletTree(int lo, int hi, int x, int y) {
		lVal = x; rVal = y;
		if (lVal == rVal || hi < lo) { lC = rC = nullptr; return; }

		int mid = (lVal + rVal) >> 1;
		auto f = [&](const int &x) { left.push_back(x <= mid); };
		for_each(A.begin() + lo, A.begin() + hi + 1, f);
		partial_sum(left.begin(), left.end(), left.begin());

		auto comp = [&](const int &x) { return x <= mid; };
		int pivot = stable_partition(A.begin() + lo, A.begin() + hi + 1, comp) - A.begin();
		lC = new WaveletTree(lo, pivot - 1, lVal, mid);
		rC = new WaveletTree(pivot, hi, mid + 1, rVal);
	}

	//Query #1: kth smallest element in [l, r]
	int kthSmallest(int l, int r, int k) {
		if (l > r) { return INF; }
		if (lVal == rVal) { return lVal; }

		int befL = (l ? left[l - 1] : 0);
		int inLeft = left[r] - befL;		//#numbers <= mid

		if (k <= inLeft) { return lC->kthSmallest(befL, left[r] - 1, k); }
		return rC->kthSmallest(l - befL, r - left[r], k - inLeft);
	}

	//Query #2: #numbers <= k in [l, r]
	int countLessThanK(int l, int r, int k) {
		if (l > r || k < lVal) { return 0; }
		if (rVal <= k) { return r - l + 1; }

		int befL = (l ? left[l - 1] : 0);
		return lC->countLessThanK(befL, left[r] - 1, k) + rC->countLessThanK(l - befL, r - left[r], k);
	}
	//EXTRA: x <= #numbers <= y in [l, r]
	int countInRange(int l, int r, int x, int y) { return countLessThanK(l, r, y) - countLessThanK(l, r, x - 1); }

	//Query #3: #numbers = k in [l, r]
	int countK(int l, int r, int k) {
		if (l > r || k < lVal || k > rVal) { return 0; }
		if (lVal == rVal) { return r - l + 1; }

		int mid = (lVal + rVal) >> 1, befL = (l ? left[l - 1] : 0);
		if (k <= mid) { return lC->countK(befL, left[r] - 1, k); }
		return rC->countK(l - befL, r - left[r], k);
	}

	//Update: Swap two adjacent elements
	void swapAdjacent(int i) { if (i >= 0 && i < n - 1 && B[i] != B[i + 1]) return swapAdjacent(i, B[i], B[i + 1]); }
	void swapAdjacent(int i, const int &f, const int &s) {
		int mid = (lVal + rVal) >> 1;
		if (f <= mid && s <= mid) { return lC->swapAdjacent(left[i] - 1, f, s); }
		if (f > mid && s > mid) { return rC->swapAdjacent(i - left[i], f, s); }
		(f <= mid ? left[i]-- : left[i]++);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}