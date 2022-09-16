#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

struct SuffixArray {
	vector<int> SA; int n;

private:

	// lexicographic order for pairs and triples
	inline bool leq(int a1, int a2, int b1, int b2) {
		return(a1 < b1 || a1 == b1 && a2 <= b2);
	}
	inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
		return(a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3));
	}

	// stably sort a[0..n-1] to b[0..n-1] with keys in 0..alphabetSize from r
	static void radixPass(vector<int>& a, vector<int>& b, int* r, int n, int alphabetSize) {
		vector<int> C(alphabetSize + 1); // counter array
		for (int i = 0; i <= alphabetSize; i++) C[i] = 0; // reset counters
		for (int i = 0; i < n; i++) C[r[a[i]]]++; // count occurrences
		for (int i = 0, sum = 0; i <= alphabetSize; i++) // exclusive prefix sums
		{
			int t = C[i]; C[i] = sum; sum += t;
		}
		for (int i = 0; i < n; i++) b[C[r[a[i]]]++] = a[i]; // sort
	}

	// find the suffix array SA of s[0..n-1] in {1..alphabetSize}�n
	// require s[n]=s[n+1]=s[n+2]=0, n>=2
	void buildSuffixArray(vector<int>& s, vector<int>& SA, int n, int alphabetSize) {
		int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
		vector<int> s12(n02 + 3); s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;
		vector<int> SA12(n02 + 3); SA12[n02] = SA12[n02 + 1] = SA12[n02 + 2] = 0;
		vector<int> s0(n0), SA0(n0);

		// generate positions of mod 1 and mod 2 suffixes
		// the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
		for (int i = 0, j = 0; i < n + (n0 - n1); i++)
			if (i % 3 != 0) s12[j++] = i;

		// lsb radix sort the mod 1 and mod 2 triples
		radixPass(s12, SA12, &s[0] + 2, n02, alphabetSize);
		radixPass(SA12, s12, &s[0] + 1, n02, alphabetSize);
		radixPass(s12, SA12, &s[0], n02, alphabetSize);

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
			buildSuffixArray(s12, SA12, n02, name);
			// store unique names in s12 using the suffix array
			for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
		}

		// generate the suffix array of s12 directly
		else for (int i = 0; i < n02; i++) SA12[s12[i] - 1] = i;

		// stably sort the mod 0 suffixes from SA12 by their first character
		for (int i = 0, j = 0; i < n02; i++)
			if (SA12[i] < n0) s0[j++] = 3 * SA12[i];
		radixPass(s0, SA0, &s[0], n0, alphabetSize);

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
	}

public:

	SuffixArray(const string& s, char first, int alphabetSize) : n((int)s.size()) {
		if (n == 1) { SA = { 0 }; return; }
		vector<int> S(n + 3, 0); SA.resize(n);
		for (int i = 0; i < n; i++) S[i] = s[i] - first + 1;

		buildSuffixArray(S, SA, n, alphabetSize);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s; SuffixArray SA(s, 'a', 26);
	cout << s.size() << ' '; for (auto& x : SA.SA)
		cout << x << ' '; cout << '\n';
}