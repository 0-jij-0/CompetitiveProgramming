#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SuffixArray {
	string s; vector<int> SA, LCP; int n;

private :

	// lexicographic order for pairs and triples
	inline bool leq(int a1, int a2, int b1, int b2) {
		return(a1 < b1 || a1 == b1 && a2 <= b2);
	}
	inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3)	{
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

	// find the suffix array SA of s[0..n-1] in {1..alphabetSize}ˆn
	// require s[n]=s[n+1]=s[n+2]=0, n>=2
	void buildSuffixArray(vector<int> &s, vector<int> &SA, int n, int alphabetSize) {
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

	// Kasai LCP Algorithm
	void buildLCPArray(vector<int> &S, vector<int> &LCP){
		vector<int> invSA(n, 0);
		for (int i = 0; i < n; i++)	invSA[SA[i]] = i;

		for (int i = 0, k = 0; i < n; i++, k -= (k != 0)) {
			if (!invSA[i]) { k = 0; continue; }

			int j = SA[invSA[i] - 1];
			while (S[i + k] == S[j + k]) k++;
			LCP[invSA[i]] = k;
		}
	}

public :

	SuffixArray(const string& s, char first, int alphabetSize) : s(s), n((int)s.size()) {
		if (n == 1) { SA = LCP = { 0 }; return; }
		vector<int> S(n + 3, 0); SA.resize(n); LCP.resize(n);
		for (int i = 0; i < n; i++) S[i] = s[i] - first + 1;

		buildSuffixArray(S, SA, n, alphabetSize);
		buildLCPArray(S, LCP);
	}

	bool isSubstr(string& t) {
		int l = 0, r = n - 1, m = (int)t.size();
		while (l <= r) {
			int mid = (l + r) >> 1;
			int curS = SA[mid], curT = 0;

			while (curS < n && curT < m) {
				if (s[curS] == t[curT]) { curS++; curT++; }
				else if (s[curS] > t[curT]) { r = mid - 1; break; }
				else { l = mid + 1; break; }
			}
			if (curT == t.size()) { return true; }
			if (curS == s.size()) { l = mid + 1; }
		}
		return false;
	}

	//Counts how many times t appears as a substring of s in O(|t|log|s|)
	int countSubstr(string& t) {
		int firstOcc = -1, lastOcc = -2, m = (int)t.size();

		//At k = 0, find the first occ of the substr, at k = 1, the last occ
		for (int k = 0; k < 2; k++) {
			int l = 0, r = n - 1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				int curS = SA[mid], curT = 0;

				while (curS < n && curT < m) {
					if (s[curS] == t[curT]) { curS++; curT++; }
					else if (s[curS] > t[curT]) { r = mid - 1; break; }
					else { l = mid + 1; break; }
				}
				if (curT == m) {
					if (!k) { firstOcc = mid; r = mid - 1; }
					else { lastOcc = mid; l = mid + 1; }
				}
				if (curS == n) { l = mid + 1; }
			}
		}

		return lastOcc - firstOcc + 1;
	}

	ll countDistinctSubstr() {
		int n = s.size(); ll res = n;
		res = (res * (res + 1)) >> 1;
		for (int i = 1; i < n; i++) res -= LCP[i];
		return res;
	}

	string findKthDistinctSubstr(ll k) {
		int n = s.size(), idx = -1, len = -1;
		for (int i = 1; i < n; i++) {
			ll curSub = n - SA[i] - LCP[i];
			if (k > curSub) { k -= curSub; continue; }
			idx = SA[i]; len = LCP[i] + k; break;
		}
		return s.substr(idx, len);
	}

	string kthSubstr(ll k) {
		vector<ll> pref(n); pref[0] = n - SA[0];
		for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + n - SA[i];
		return findKthSubstr(0, n - 1, k, RMQ(LCP), pref);
	}

	string findKthSubstr(int l, int r, ll k, const RMQ& rmq, vector<ll>& pref) {
		if (l == r) { return s.substr(SA[l], (int)k); }

		int i = rmq.query(l + 1, r), len = r - l + 1;
		ll h = rmq.get(i), rightLCPPart = h * (r - i + 1);
		if (k <= h * len) { return s.substr(SA[l], (int)(k + len - 1) / len); }

		ll leftTotal = (i ? pref[i - 1] - (l ? pref[l - 1] : 0) : 0);
		if (k <= leftTotal + rightLCPPart) return findKthSubstr(l, i - 1, k - rightLCPPart, rmq, pref);
		else return findKthSubstr(i, r, k - leftTotal, rmq, pref);
	}
};

string longestCommonSubstring(string& s, string& t, char first, int alphabetSize) {
	string tt = s + string(1, first - 1) + t; //'$' > '#'
	SuffixArray SA(tt, first - 1, alphabetSize + 1);

	//Enough to check consecutive suffixes where a suffix starts in s and another in t
	int n = tt.size(), sep = t.size(), LCSlen = 0, LCSstart = -1;
	for (int i = 1; i < n; i++) {
		int len1 = n - SA.SA[i], len2 = n - SA.SA[i - 1];
		if (len1 > len2) { swap(len1, len2); }
		if (len1 <= sep && len2 > sep + 1) {
			if (LCSlen < SA.LCP[i]) {
				LCSlen = SA.LCP[i];
				LCSstart = min(SA.SA[i], SA.SA[i - 1]);
			}
		}
	}
	return s.substr(LCSstart, LCSlen);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


}