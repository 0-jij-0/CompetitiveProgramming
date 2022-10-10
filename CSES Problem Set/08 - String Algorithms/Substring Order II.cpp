#include <bits/stdc++.h>
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

	LCP.clear(); LCP.resize(n); int k = 0;
	for (int i = 0; i < n - 1; i++) {
		int pi = c[i], j = SA[pi - 1];
		while (s[i + k] == s[j + k]) { k++; }
		LCP[pi] = k; k = max(k - 1, 0);
	}
	s.pop_back(); SA.erase(SA.begin()); LCP.erase(LCP.begin()); n--;
}

struct RMQ {
	vector<vector<int>> rmq;
	vector<int> v, logb2; RMQ() {}

	inline int combine(int a, int b) { return v[a] < v[b] ? a : b; }
	int get(int i) { return v[i]; }

	RMQ(vector<int>& v) : v(v) {
		int n = (int)v.size(); logb2.resize(n + 1, 0);
		rmq.resize(1, vector<int>(n));
		iota(rmq[0].begin(), rmq[0].end(), 0);

		for (int i = 0; (1 << i) <= n; i++) { logb2[1 << i] = i; }
		for (int i = 1; i <= n; i++) { logb2[i] = max(logb2[i], logb2[i - 1]); }
		rmq.resize(logb2.back() + 1);

		for (int t = 1; t < (int)rmq.size(); t++) {
			rmq[t].resize(n - (1 << t) + 1);
			for (int i = 0; i <= n - (1 << t); i++)
				rmq[t][i] = combine(rmq[t - 1][i], rmq[t - 1][i + (1 << (t - 1))]);
		}
	}

	int query(int i, int j) {
		if (i > j) { swap(i, j); }
		int k = logb2[j - i + 1];
		return combine(rmq[k][i], rmq[k][j - (1 << k) + 1]);
	}
};

string findKthSubstr(int l, int r, ll k, RMQ& rmq, vector<int>& SA, vector<ll>& pref, const string& s) {
	if (l == r) { return s.substr(SA[l], (int)k); }

	int i = rmq.query(l + 1, r), len = r - l + 1;
	ll h = rmq.get(i), rightLCPPart = h * (r - i + 1);
	if (k <= h * len) { return s.substr(SA[l], (int)(k + len - 1) / len); }

	ll leftTotal = (i ? pref[i - 1] - (l ? pref[l - 1] : 0) : 0);
	if (k <= leftTotal + rightLCPPart) return findKthSubstr(l, i - 1, k - rightLCPPart, rmq, SA, pref, s);
	else return findKthSubstr(i, r, k - leftTotal, rmq, SA, pref, s);
}

string kthSubstr(string& s, ll k) {
	int n = (int)s.size(); vector<int> SA, LCP;
	suffixArray(s, SA, LCP); RMQ rmq(LCP);
	vector<ll> pref(n); pref[0] = n - SA[0];
	for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + n - SA[i];
	return findKthSubstr(0, n - 1, k, rmq, SA, pref, s);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; ll k; cin >> s >> k;
	cout << kthSubstr(s, k) << '\n';
}