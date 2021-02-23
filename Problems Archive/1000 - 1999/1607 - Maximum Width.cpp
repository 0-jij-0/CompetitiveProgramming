#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s, t; int n, m;
vector<int> suf, pref;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> s >> t;
	int i = 0, j = 0; while (j != m) {
		if (s[i] != t[j]) { i++; continue; }
		pref.push_back(i); i++; j++;
	}

	i = n - 1, j = m - 1; while (j != -1) {
		if (s[i] != t[j]) { i--; continue; }
		suf.push_back(i); i--; j--;
	}
	reverse(suf.begin(), suf.end());

	int res = 1; i = 0; while (++i != m)
		res = max(res, suf[i] - pref[i - 1]);

	cout << res << '\n';
	cin.ignore(2); return 0;
}