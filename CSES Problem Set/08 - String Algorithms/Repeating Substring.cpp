#include <bits/stdc++.h>
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

	lcp.clear(); lcp.resize(n); k = 0;
	for (int i = 0; i < n - 1; i++) {
		int pi = c[i];
		int j = p[pi - 1];

		while (s[i + k] == s[j + k]) { k++; }
		lcp[pi] = k; k = max(k - 1, 0);
	}
}

ll numOfDifSubstr(string &s, vector<int> &sufA, vector<int> &lcp) {
	ll res = 0; int n = s.size();
	for (int i = 1; i <= n; i++) {
		res += (n - sufA[i] - lcp[i]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s; cin >> s;
	vector<int> SA, lcp; suffArray(s, SA, lcp);
	int idx = 1; for(int i = 1; i < (int) SA.size(); i++)
		if (lcp[i] > lcp[idx]) { idx = i; }

	cout << (lcp[idx] ? s.substr(SA[idx], lcp[idx]) : "-1") << '\n';
}