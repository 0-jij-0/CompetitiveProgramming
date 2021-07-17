#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
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

void suffArray(string s, vector<int> &sufA) {
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
}

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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int k; string s; cin >> s >> k;
	vector<int> SA; suffArray(s, SA);
	while (k--) {
		string t; cin >> t;
		cout << (isSubstr(s, t, SA) ? "YES" : "NO") << '\n';
	}

	cin.ignore(2); return 0;
}