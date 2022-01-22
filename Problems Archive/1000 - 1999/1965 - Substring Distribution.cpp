#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> countingSortStable(vector<int>& p, vector<int>& c) {
	int n = p.size(); vector<int> cnt(n, 0);
	for (auto& x : c) { cnt[x]++; }

	vector<int> res(n), pos(n); pos[0] = 0;
	partial_sum(cnt.begin(), --cnt.end(), pos.begin() + 1);
	for (auto x : p) res[pos[c[x]]++] = x;
	return move(res);
}

void suffArray(string &s, vector<int>& SA, vector<int>& LCP) {
	s.push_back('#'); int n = (int) s.size();
	vector<int> c(n); SA.resize(n);
	iota(SA.begin(), SA.end(), 0);

	auto comp = [&](const int& i, const int& j) {
		return s[i] < s[j] || (s[i] == s[j] && i < j);
	}; sort(SA.begin(), SA.end(), comp);
	
	c[SA[0]] = 0; for (int i = 1; i < n; i++) 
		c[SA[i]] = c[SA[i - 1]] + (s[SA[i]] != s[SA[i - 1]]);

	for(int k = 1; k <= n; k <<= 1) {
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

	LCP.clear(); LCP.resize(n); int k = 0;
	for (int i = 0; i < n - 1; i++) {
		int pi = c[i], j = SA[pi - 1];
		while (s[i + k] == s[j + k]) { k++; }
		LCP[pi] = k; k = max(k - 1, 0);
	}
	s.pop_back();
}

vector<int> distribution(string& s) {
	vector<int> SA, LCP; suffArray(s, SA, LCP);
	int n = s.size(); vector<int> res(n, 0);
	for (int i = 1; i <= n; i++) {
		res[LCP[i]]++; if (SA[i]) res[n - SA[i]]--;
	}
	partial_sum(res.begin(), res.end(), res.begin());
	return move(res);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s; cin >> s;
	vector<int> res = distribution(s);
	for (auto& x : res) cout << x << ' '; cout << '\n';
	cin.ignore(2); return 0;
}