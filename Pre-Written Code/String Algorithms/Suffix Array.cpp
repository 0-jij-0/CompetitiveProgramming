#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> countingSortStable(vector<int>& p, vector<int>& c) {
	int n = p.size(); vector<int> cnt(n, 0);
	for (auto& x : c) { cnt[x]++; }

	vector<int> res(n), pos(n); pos[0] = 0;
	partial_sum(cnt.begin(), --cnt.end(), pos.begin() + 1);
	for (auto x : p) res[pos[c[x]]++] = x;
	return res;
}

//Builds the suffix array of s in O(nlogn)
void suffixArray(string& s, vector<int>& SA, vector<int>& LCP) {
	s.push_back('#'); int n = (int)s.size();
	vector<int> c(n); SA.resize(n);
	iota(SA.begin(), SA.end(), 0);

	auto comp = [&](const int& i, const int& j) {
		return s[i] < s[j] || (s[i] == s[j] && i < j);
	}; sort(SA.begin(), SA.end(), comp);

	c[SA[0]] = 0; for (int i = 1; i < n; i++)
		c[SA[i]] = c[SA[i - 1]] + (s[SA[i]] != s[SA[i - 1]]);

	for (int k = 1; k <= n; k <<= 1) {
		for (int i = 0; i < n; i++) SA[i] = (SA[i] - k + n) % n;
		SA = countingSortStable(SA, c);

		vector<int> newC(n); newC[SA[0]] = 0;
		for (int i = 1; i < n; i++) {
			pair<int, int> prev = { c[SA[i - 1]], c[(SA[i - 1] + k) % n] };
			pair<int, int> now = { c[SA[i]], c[(SA[i] + k) % n] };
			newC[SA[i]] = newC[SA[i - 1]] + (prev != now);
		}
		c = move(newC);
	}

	//Finds the Longest Common Prefix of all contiguous suffixes in the suffix array in O(n)
	//lcp[pi] = lcp(s[p[i]..], s[p[i-1]..])
	LCP.clear(); LCP.resize(n); int k = 0;
	for (int i = 0; i < n - 1; i++) {
		int pi = c[i], j = SA[pi - 1]; //pi pos of suffix i in the suffix array
		while (s[i + k] == s[j + k]) { k++; }
		LCP[pi] = k; k = max(k - 1, 0);
	}
	s.pop_back();
}

//Checks if t is a substring of s in O(|t|log|s|)
bool isSubstr(string &s, string &t, vector<int> &sufA) {
	int l = 0, r = (int)s.size(); 
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
		int l = 0, r = (int)s.size();
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

ll countDistinctSubstr(string &s, vector<int> &sufA, vector<int> &lcp) {
	int n = s.size(); ll res = n;
	res = (res * (res + 1)) >> 1;
	for (int i = 1; i <= n; i++) res -= lcp[i];
	return res;
}

string longestCommonSubstr(string &s, string &t) {
	string tt = s + '$' + t; //'$' > '#'
	vector<int> sufA, lcp;
	suffixArray(tt, sufA, lcp);

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

string findKthDistinctSubstr(string &s, ll k, vector<int>& sufA, vector<int>& lcp) {
	int n = s.size(), idx = -1, len = -1;
	for (int i = 1; i <= n; i++) {
		ll curSub = n - sufA[i] - lcp[i];
		if (k > curSub) { k -= curSub; continue; }
		idx = sufA[i]; len = lcp[i] + k; break;
	}
	return s.substr(idx, len);
}

string findKthSubstr(int l, int r, ll k, RMQ& rmq, vector<int>& SA, vector<ll>& pref, const string& s) {
	if (l == r) { return s.substr(SA[l], (int)k); }

	int i = rmq.query(l + 1, r), len = r - l + 1;
	ll h = rmq.get(i), rightLCPPart = h * (r - i + 1);
	if (k <= h * len) { return s.substr(SA[l], (int)(k + len - 1) / len); }

	ll leftTotal = (i ? pref[i - 1] - (l ? pref[l - 1] : 0) : 0);
	if (k <= leftTotal + rightLCPPart) return findKthSubstr(l, i - 1, k - rightLCPPart, rmq, SA, pref, s);
	else return findKthSubstr(i, r, k - leftTotal, rmq, SA, pref, s);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
}