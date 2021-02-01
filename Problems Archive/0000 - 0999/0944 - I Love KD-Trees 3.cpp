#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;

const int MIN = 0, MAX = 100001; //Min and max possible values in the array; [-1e9,1e9] are too much --> compress
vector<int> A, B;

//Wavelet Tree supports:
//Queries:  Kth element in a range // Number of elements = k in a range // Number of elements <= k in a range
//Updates:  Swap two consecutive elements // Toggle elements (on elements are counted in queries; off elements aren't)
//Updates not implemented yet
struct WaveletTree {
	int lVal, rVal; int n;
	WaveletTree *lC, *rC;
	vector<int> left; 		//left[i] = number of elements from the first i elements that go to left child
							//Used to map the indices of range queries (we can deduce from it how much goes to the right child)

	WaveletTree(int _n) : WaveletTree(0, n = _n - 1, MIN, MAX) {}

	//Numbers are in the range [lVal, rVal]
	//Array indices are in [lo, hi]
	WaveletTree(int lo, int hi, int x, int y) {
		lVal = x; rVal = y;
		if (lVal == rVal || hi < lo) { return; }

		int mid = (lVal + rVal) >> 1;
		auto f = [&](const int &x) { left.push_back(x <= mid); };
		for_each(A.begin() + lo, A.begin() + hi + 1, f);
		partial_sum(left.begin(), left.end(), left.begin());

		auto comp = [&](const int &x) { return x <= mid; };
		int pivot = stable_partition(A.begin() + lo, A.begin() + hi + 1, comp) - A.begin();
		lC = new WaveletTree(lo, pivot - 1, lVal, mid);
		rC = new WaveletTree(pivot, hi, mid + 1, rVal);
	}

	//kth smallest element in [l, r]
	int kthSmallest(int l, int r, int k) {
		if (l > r) { return MAX + 2; }
		if (lVal == rVal) { return lVal; }

		int befL = (l ? left[l - 1] : 0);
		int inLeft = left[r] - befL;		//#numbers <= mid

		if (k <= inLeft) { return lC->kthSmallest(befL, left[r] - 1, k); }
		return rC->kthSmallest(l - befL, r - left[r], k - inLeft);
	}

	void swapAdjacent(int i) {
		int f = B[i], s = B[i + 1];
		if (f != s) { return swapAdjRec(i, f, s); }
	}

	void swapAdjRec(int i, const int &f, const int &s) {
		int mid = (lVal + rVal) >> 1;
		if (f <= mid && s <= mid) { return lC->swapAdjRec(left[i] - 1, f, s); }
		if (f > mid && s > mid) { return rC->swapAdjRec(i - left[i], f, s); }
		(f <= mid ? left[i]-- : left[i]++);
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
		if (t) {
			int i; cin >> i; if (i == n - 1 || B[i] == B[i + 1]) { continue; }
			int idx1 = lower_bound(occ[B[i]].begin(), occ[B[i]].end(), i) - occ[B[i]].begin();
			int idx2 = lower_bound(occ[B[i + 1]].begin(), occ[B[i + 1]].end(), i + 1) - occ[B[i + 1]].begin();
			occ[B[i]][idx1]++; occ[B[i + 1]][idx2]--; 
			T.swapAdjacent(i); swap(B[i], B[i + 1]);
		}
		else {
			int i, l, k; cin >> i >> l >> k; l--;
			int d = T.kthSmallest(0, i, k);
			if ((int)occ[d].size() <= l) { cout << -1 << '\n'; }
			else { cout << occ[d][l] << '\n'; }
		}
	}

	cin.ignore(2); return 0;
}