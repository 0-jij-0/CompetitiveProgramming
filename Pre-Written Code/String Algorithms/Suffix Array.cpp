#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

void countingSort(vector<int> &p, vector<int> &c) {
	int n = p.size();
	vector<int> cnt(n, 0);
	for (auto &x : c) { cnt[x]++; }

	vector<int> newP(n);
	vector<int> pos(n); pos[0] = 0;
	for (int i = 1; i < n; i++) { pos[i] = pos[i - 1] + cnt[i - 1]; }
	for (auto x : p) {
		int i = c[x];
		newP[pos[i]] = x; pos[i]++;
	}
	p = newP;
}

//Builds the suffix array (lexicographical ordering of the suffixes defined by their start idx) of s in O(nlogn)
//sufA[i] gives the start index in s of the ith suffix
void suffArray(string s, vector<int> &sufA, vector<int> &lcp) {
	s.push_back('#');
	int n = s.size();
	vector<int> p(n), c(n);

	vector<pair<char, int>> a(n);
	for (int i = 0; i < n; i++) { a[i] = { s[i], i }; }
	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) { p[i] = a[i].second; }
	c[p[0]] = 0;
	for (int i = 1; i < n; i++) {
		if (a[i].first == a[i - 1].first) { c[p[i]] = c[p[i - 1]]; }
		else { c[p[i]] = c[p[i - 1]] + 1; }
	}

	int k = 0;
	while (c[p[n - 1]] != n - 1) {
		for (int i = 0; i < n; i++) { p[i] = (p[i] - (1 << k) + n) % n; }
		//p was shifted back but no need to change c
		//p is already sorted by the second half so radix sort only needs one additional counting sort
		countingSort(p, c);

		vector<int> newC(n); newC[p[0]] = 0;
		for (int i = 1; i < n; i++) {
			pair<int, int> prev = { c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n] };
			pair<int, int> now = { c[p[i]], c[(p[i] + (1 << k)) % n] };
			if (prev == now) { newC[p[i]] = newC[p[i - 1]]; }
			else { newC[p[i]] = newC[p[i - 1]] + 1; }
		}

		c = newC; k++;
	}
	sufA = p;

	//Finds the Longest Common Prefix of all contiguous suffixes in the suffix array in O(n)
	//lcp[pi] = lcp(s[p[i]..], s[p[i-1]..])
	lcp.clear(); lcp.resize(n); k = 0;
	for (int i = 0; i < n - 1; i++) {
		int pi = c[i];	//pos of suffix i in the suffix array
		int j = p[pi - 1];

		while (s[i + k] == s[j + k]) { k++; }
		lcp[pi] = k; k = max(k - 1, 0);
	}
	//LCP of any two suffixes i, j becomes min(lcp[pos[i]]...lcp[pos[j]]) = min(lcp[c[i]]...lcp[c[j]])

	//	for (int i = 0; i < n; i++) { cout << lcp[i] << " " << sufA[i] << " " << s.substr(sufA[i], n - sufA[i]) << endl; }
}

//Checks if t is a substring of s in O(|t|log|s|)
bool isSubstr(string &s, string &t, vector<int> &sufA) {
	int l = 0, r = s.size();
	while (l <= r) {
		int mid = (l + r) >> 1;
		int curS = sufA[mid], curT = 0;

		while (curS < s.size() && curT < t.size()) {
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
int countSubstr(string &s, string &t, vector<int> &sufA) {
	int firstOcc = -1, lastOcc = -2;

	//At k = 0, find the first occ of the substr, at k = 1, the last occ
	for (int k = 0; k < 2; k++) {
		int l = 0, r = s.size();
		while (l <= r) {
			int mid = (l + r) >> 1;
			int curS = sufA[mid], curT = 0;

			while (curS < s.size() && curT < t.size()) {
				if (s[curS] == t[curT]) { curS++; curT++; }
				else if (s[curS] > t[curT]) { r = mid - 1; break; }
				else { l = mid + 1; break; }
			}
			if (curT == t.size()) {
				if (!k) { firstOcc = mid; r = mid - 1; }
				else { lastOcc = mid; l = mid + 1; }
			}
			if (curS == s.size()) { l = mid + 1; }
		}
	}

	return lastOcc - firstOcc + 1;
}

//Counts the number of different substrings in s in O(n)
ll numOfDifSubstr(string &s, vector<int> &sufA, vector<int> &lcp) {
	ll res = 0; int n = s.size();
	for (int i = 1; i <= n; i++) {
		res += (n - sufA[i] - lcp[i]);
	}
	return res;
}

//Finds the longest common substring between s and t
string LCSubstr(string &s, string &t) {
	string tt = s + '$' + t;		//'$' > '#'
	vector<int> sufA, lcp;
	suffArray(tt, sufA, lcp);

	//Enough to check consecutive suffixes where a suffix starts in s and another in t
	int n = tt.size(), sep = t.size(), LCSlen = 0, LCSstart = -1;
	for (int i = 2; i <= n; i++) {
		int len1 = n - sufA[i], len2 = n - sufA[i - 1];
		if (len1 > len2) { swap(len1, len2); }
		if (len1 <= sep && len2 > sep + 1) {
			if (LCSlen < lcp[i]) {
				LCSlen = lcp[i];
				LCSstart = min(sufA[i], sufA[i - 1]);
			}
		}
	}
	return s.substr(LCSstart, LCSlen);
}

//Finds the kth distinct substring in the corresponding string in O(n)
string findKthDistinct(string &s, ll k, vector<int>& sufA, vector<int>& lcp) {
	int n = s.size(), idx = -1, len = -1;
	for (int i = 1; i <= n; i++) {
		ll curSub = n - sufA[i] - lcp[i];
		if (k > curSub) { k -= curSub; continue; }
		idx = sufA[i]; len = lcp[i] + k;
		break;
	}
	return s.substr(idx, len);
}

//O(nlogn)
//st is a segment tree of the lcp array that returns the min and the min index
//Returns {startPos, len} of the kth substring
//Initial call: l = 1, r = lcp.size()-1 (remember that l,r are indices in the lcp/suf array; NOT the string)
pair<int, int> findKthSubstr(ll& k, int l, int r, int rem, int n, vector<int>& sufA, SegTree& st) {
	if (l > r) { return { -1, -1 }; }
	if (l == r) {
		ll curS = n - sufA[l] - rem;
		if (k > curS) { k -= curS; return { -1, -1 }; }
		return { sufA[l], rem + k };
	}

	StVal mi = st.query(l + 1, r);
	int idx = mi.idx;
	ll range = r - l + 1, height = mi.v - rem;

	ll curS = range * height;
	if (k <= curS) {
		k = (k + range - 1) / range;
		return { sufA[l], rem + k };
	}

	k -= curS; rem = mi.v;
	pair<int, int> c1 = findKthSubstr(k, l, idx - 1, rem, n, sufA, st);
	if (c1.first != -1) { return c1; }
	return findKthSubstr(k, idx, r, rem, n, sufA, st);
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
}