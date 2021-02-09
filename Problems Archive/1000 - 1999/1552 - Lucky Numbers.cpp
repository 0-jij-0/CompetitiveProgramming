#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;
typedef long long ll;

const int MIN = 0, MAX = 10; //Min and max possible values in the array; [-1e9,1e9] are too much --> compress
vector<int> A, B; //A used to build wavelet tree B copy of A

//Wavelet Tree supports:
//Queries:  Kth element in a range // Number of elements = k in a range // Number of elements <= k in a range
//Updates:  Swap two consecutive elements // Toggle elements (on elements are counted in queries; off elements aren't)
//Updates not implemented yet
struct WaveletTree {
	int lVal, rVal; int n;
	WaveletTree* lC, * rC;
	vector<int> left; 		//left[i] = number of elements from the first i elements that go to left child
							//Used to map the indices of range queries (we can deduce from it how much goes to the right child)

	WaveletTree(int _n) : WaveletTree(0, n = _n - 1, MIN, MAX) {}

	//Numbers are in the range [lVal, rVal]
	//Array indices are in [lo, hi]
	WaveletTree(int lo, int hi, int x, int y) {
		lVal = x; rVal = y;
		if (lVal == rVal || hi < lo) { lC = rC = nullptr; return; }

		int mid = (lVal + rVal) >> 1;
		auto f = [&](const int& x) { left.push_back(x <= mid); };
		for_each(A.begin() + lo, A.begin() + hi + 1, f);
		partial_sum(left.begin(), left.end(), left.begin());

		auto comp = [&](const int& x) { return x <= mid; };
		int pivot = stable_partition(A.begin() + lo, A.begin() + hi + 1, comp) - A.begin();
		lC = new WaveletTree(lo, pivot - 1, lVal, mid);
		rC = new WaveletTree(pivot, hi, mid + 1, rVal);
	}

	//Query #2: #numbers <= k in [l, r]
	int LessThanK(int l, int r, int k) {
		if (l > r || k < lVal) { return 0; }
		if (rVal <= k) { return r - l + 1; }

		int befL = (l ? left[l - 1] : 0);
		return lC->LessThanK(befL, left[r] - 1, k) + rC->LessThanK(l - befL, r - left[r], k);
	}
	//EXTRA: x <= #numbers <= y in [l, r]
	int inRange(int l, int r, int x, int y) { return LessThanK(l, r, y) - LessThanK(l, r, x - 1); }

	//Query #3: #numbers = k in [l, r]
	int countK(int l, int r, int k) {
		if (l > r || k < lVal || k > rVal) { return 0; }
		if (lVal == rVal) { return r - l + 1; }

		int mid = (lVal + rVal) >> 1, befL = (l ? left[l - 1] : 0);
		if (k <= mid) { return lC->countK(befL, left[r] - 1, k); }
		return rC->countK(l - befL, r - left[r], k);
	}
};

int check(int i) {
	string s = to_string(i);
	sort(s.begin(), s.end());
	int res = 0, x = (int)s.size();
	for (int i = 1; i < x; i++)
		res = max(res, abs(s[i] - s[i - 1]));
	return res;
}

int main() {
	freopen("lucky.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	A.resize(1000 * 1000 + 1);
	for (int i = 1; i <= 1000000; i++)
		A[i] = check(i);

	WaveletTree wt(1000 * 1000 + 1);

	int q; cin >> q; while (q--) {
		int l, r, x; cin >> l >> r >> x;
		cout << wt.LessThanK(l, r, x) << '\n';
	}

	cin.ignore(2); return 0;
}