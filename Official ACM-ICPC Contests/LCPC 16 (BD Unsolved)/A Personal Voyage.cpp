#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;

int MIN = 0, MAX = 1000 * 1000;
vector<int> A;

//Wavelet Tree supports:
//Queries: Number of elements <= k in a range
struct WaveletTree {
	int lVal, rVal; int n = 0;
	WaveletTree* lC = nullptr, * rC = nullptr;
	vector<int> left; 		//left[i] = number of elements from the first i elements that go to left child
							//Used to map the indices of range queries (we can deduce from it how much goes to the right child)

	WaveletTree() {}
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

	int countLessThanK(int l, int r, int k) {
		if (l > r || k < lVal) { return 0; }
		if (rVal <= k) { return r - l + 1; }

		int befL = (l ? left[l - 1] : 0);
		return lC->countLessThanK(befL, left[r] - 1, k) + rC->countLessThanK(l - befL, r - left[r], k);
	}
	int countInRange(int l, int r, int x, int y) { return countLessThanK(l, r, y) - countLessThanK(l, r, x - 1); }

	~WaveletTree() {
		if (lC != nullptr) delete lC;
		if (rC != nullptr) delete rC;
	}
};

inline bool leq(int a1, int a2, int b1, int b2) // lexicographic order
{
	return(a1 < b1 || a1 == b1 && a2 <= b2);
} // for pairs

inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3)
{
	return(a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3));
} // and triples

// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
static void radixPass(int* a, int* b, int* r, int n, int K)
{// count occurrences
	int* c = new int[K + 1]; // counter array
	for (int i = 0; i <= K; i++) c[i] = 0; // reset counters
	for (int i = 0; i < n; i++) c[r[a[i]]]++; // count occurrences
	for (int i = 0, sum = 0; i <= K; i++) // exclusive prefix sums
	{
		int t = c[i]; c[i] = sum; sum += t;
	}
	for (int i = 0; i < n; i++) b[c[r[a[i]]]++] = a[i]; // sort
	delete[] c;
}

// find the suffix array SA of s[0..n-1] in {1..K}�n
// require s[n]=s[n+1]=s[n+2]=0, n>=2
void suffixArray(int* s, int* SA, int n, int K) {
	int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
	int* s12 = new int[n02 + 3]; s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;
	int* SA12 = new int[n02 + 3]; SA12[n02] = SA12[n02 + 1] = SA12[n02 + 2] = 0;
	int* s0 = new int[n0];
	int* SA0 = new int[n0];

	// generate positions of mod 1 and mod 2 suffixes
	// the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
	for (int i = 0, j = 0; i < n + (n0 - n1); i++)
		if (i % 3 != 0) s12[j++] = i;

	// lsb radix sort the mod 1 and mod 2 triples
	radixPass(s12, SA12, s + 2, n02, K);
	radixPass(SA12, s12, s + 1, n02, K);
	radixPass(s12, SA12, s, n02, K);

	// find lexicographic names of triples
	int name = 0, c0 = -1, c1 = -1, c2 = -1;
	for (int i = 0; i < n02; i++) {
		if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2)
		{
			name++; c0 = s[SA12[i]]; c1 = s[SA12[i] + 1]; c2 = s[SA12[i] + 2];
		}
		if (SA12[i] % 3 == 1) { s12[SA12[i] / 3] = name; } // left half
		else { s12[SA12[i] / 3 + n0] = name; } // right half
	}

	// recurse if names are not yet unique
	if (name < n02) {
		suffixArray(s12, SA12, n02, name);
		// store unique names in s12 using the suffix array
		for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
	}

	// generate the suffix array of s12 directly
	else for (int i = 0; i < n02; i++) SA12[s12[i] - 1] = i;

	// stably sort the mod 0 suffixes from SA12 by their first character
	for (int i = 0, j = 0; i < n02; i++)
		if (SA12[i] < n0) s0[j++] = 3 * SA12[i];
	radixPass(s0, SA0, s, n0, K);

	// merge sorted SA0 suffixes and sorted SA12 suffixes
	for (int p = 0, t = n0 - n1, k = 0; k < n; k++) {
		auto GetI = [&]() { return SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2; };
		int i = GetI(); // pos of current offset 12 suffix
		int j = SA0[p]; // pos of current offset 0 suffix
		if (SA12[t] < n0 ? // different compares for mod 1 and mod 2 suffixes
			leq(s[i], s12[SA12[t] + n0], s[j], s12[j / 3]) :
			leq(s[i], s[i + 1], s12[SA12[t] - n0 + 1], s[j], s[j + 1], s12[j / 3 + n0]))
		{// suffix from SA12 is smaller
			SA[k] = i; t++;
			if (t == n02) // done --- only SA0 suffixes left
				for (k++; p < n0; p++, k++) SA[k] = SA0[p];
		}
		else {// suffix from SA0 is smaller
			SA[k] = j; p++;
			if (p == n0) // done --- only SA12 suffixes left
				for (k++; t < n02; t++, k++) SA[k] = GetI();
		}
	}
	delete[] s12; delete[] SA12; delete[] SA0; delete[] s0;
}

int countSubstrInRange(string& s, string& t, int L, int R, vector<int>& SA, WaveletTree& WT) {
	int firstOcc = -1, lastOcc = -2;
	int N = (int)s.size(), M = (int)t.size();

	//At k = 0, find the first occ of the substr, at k = 1, the last occ
	for (int k = 0; k < 2; k++) {
		int l = 0, r = N - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			int curS = SA[mid], curT = 0;

			while (curS < N && curT < M) {
				if (s[curS] == t[curT]) { curS++; curT++; }
				else if (s[curS] > t[curT]) { r = mid - 1; break; }
				else { l = mid + 1; break; }
			}
			if (curT == M) {
				if (!k) { firstOcc = mid; r = mid - 1; }
				else { lastOcc = mid; l = mid + 1; }
			}
			if (curS == N) { l = mid + 1; }
		}
	}

	return WT.countInRange(firstOcc, lastOcc, L, R);
}

vector<int> S; string st; vector<int> M, SA;

int main() {
	freopen("apersonal.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T; while (T--) {
		int N; cin >> N; S.clear(); st.clear();
		for (int i = 0; i < N; i++) {
			string s; cin >> s; st += s + "$";
			for (char c : s) S.push_back(c - 'a' + 2);
			S.push_back(1);
		}
		S.push_back(0); S.push_back(0);	S.push_back(0);

		N = (int)st.size(); M.resize(N); A.resize(N); SA.resize(N);
		for (int i = 0; i < N; i++) M[i] = st[i] == '$';
		partial_sum(M.begin(), M.end(), M.begin());

		suffixArray(&S[0], &SA[0], N, 27);
		for (int i = 0; i < N; i++) A[i] = M[SA[i]];

		MAX = M.back(); WaveletTree WT(N);
		int q; cin >> q; while (q--) {
			int i, j; string t; cin >> i >> j >> t; --i; --j;
			cout << countSubstrInRange(st, t, i, j, SA, WT) << '\n';
		}
	}
}