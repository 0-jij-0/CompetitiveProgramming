#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

inline ll power(ll x, ll n) {
	ll res = 1, a = x;
	for (; n; n >>= 1, a = (a * a) % mod)
		if (n & 1) res = (res * a) % mod;
	return res;
}

ll modInv(ll x) { return power(x, mod - 2); }

const int MIN = 0, MAX = 3 * 1000 * 100 + 5;
vector<int> A, B; //A used to build wavelet tree B copy of A

struct WaveletTree {
	int lVal, rVal; int n;
	WaveletTree *lC, *rC;
	vector<int> left;		//left[i] = number of elements from the first i elements that go to left child
							//Used to map the indices of range queries (we can deduce from it how much goes to the right child)
	vector<ll> prod;

	WaveletTree(int _n) : WaveletTree(0, n = _n - 1, MIN, MAX) {}

	//Numbers are in the range [lVal, rVal]
	//Array indices are in [lo, hi]
	WaveletTree(int lo, int hi, int x, int y) {
		lVal = x; rVal = y;
		if (hi < lo) { return; }

		int mid = (lVal + rVal) >> 1, back = 0; ll backProd = 1;

		if (lVal != rVal) for (int i = lo; i <= hi; i++)
			left.push_back(back += (A[i] <= mid));

		for (int i = lo; i <= hi; i++)
			prod.push_back(backProd = (backProd * A[i]) % mod);

		if (lVal == rVal) { return; }
		auto comp = [&](const int &x) { return x <= mid; };
		int pivot = stable_partition(A.begin() + lo, A.begin() + hi + 1, comp) - A.begin();
		lC = new WaveletTree(lo, pivot - 1, lVal, mid);
		rC = new WaveletTree(pivot, hi, mid + 1, rVal);
	}

	//Query #2: #numbers <= k in [l, r]
	ll LessThanK(int l, int r, int k) {
		if (l > r || k < lVal) { return 1; }
		if (rVal <= k) { return prod.empty() ? 1 : (prod[r] * (l ? modInv(prod[l - 1]) : 1)) % mod; }

		int befL = (l ? left[l - 1] : 0);
		return (lC->LessThanK(befL, left[r] - 1, k) * rC->LessThanK(l - befL, r - left[r], k)) % mod;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q; A.resize(n);
	for (auto &x : A) { cin >> x; }

	WaveletTree T(n);
	while (q--) {
		int l, r, h; cin >> l >> r >> h;
		cout << T.LessThanK(l, r, h) << '\n';
	}

	cin.ignore(2); return 0;
}