#include <bits/stdc++.h>
using namespace std;

string s, t;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> s >> t; int n = (int)s.size(), m = (int)t.size();
	int i = 0; while (i < m && (s[i] == '?' || t[i] == '?' || s[i] == t[i])) { i++; }
	int j = 0; while (j < m && (s[n - 1 - j] == '?' || t[m - 1 - j] == '?' || s[n - 1 - j] == t[m - 1 - j])) j++;
	
	for (int k = 0; k <= m; k++)
		cout << (k <= i && (m - k) <= j ? "Yes" : "No") << '\n';
}