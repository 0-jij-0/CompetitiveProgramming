#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

const int MIN = 0, MAX = 100000;
vector<int> A;

struct WaveletTree {
	int lVal, rVal;
	WaveletTree *lC, *rC;
	vector<int> left;
	WaveletTree(int n) : WaveletTree(0, n - 1, MIN, MAX) {}

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

	int kthSmallest(int l, int r, int k) {
		if (l > r) { return MAX + 2; }
		if (lVal == rVal) { return lVal; }

		int befL = (l ? left[l - 1] : 0);
		int inLeft = left[r] - befL;

		if (k <= inLeft) { return lC->kthSmallest(befL, left[r] - 1, k); }
		return rC->kthSmallest(l - befL, r - left[r], k - inLeft);
	}

	int LessThanK(int l, int r, int k) {
		if (l > r || k < lVal) { return 0; }
		if (rVal <= k) { return r - l + 1; }

		int befL = (l ? left[l - 1] : 0);
		return lC->LessThanK(befL, left[r] - 1, k) + rC->LessThanK(l - befL, r - left[r], k);
	}

	int countK(int l, int r, int k) {
		if (l > r || k < lVal || k > rVal) { return 0; }
		if (lVal == rVal) { return r - l + 1; }

		int mid = (lVal + rVal) >> 1, befL = (l ? left[l - 1] : 0);
		if (k <= mid) { return lC->countK(befL, left[r] - 1, k); }
		return rC->countK(l - befL, r - left[r], k);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	vector<int> comp;
	int n, q; cin >> n >> q;
	vector<vector<int>> occ(n);
	A.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i]; comp.push_back(A[i]);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for (int i = 0; i < n; i++) {
		A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin();
		occ[A[i]].push_back(i);
	}

	WaveletTree T(n);

	while (q--) {
		int k, i, l; cin >> k >> i >> l;
		int d = T.kthSmallest(0, i, k);
		if ((int)occ[d].size() < l) { cout << -1 << '\n'; }
		else { cout << occ[d][l - 1] << '\n'; }
	}

	cin.ignore(2); return 0;
}