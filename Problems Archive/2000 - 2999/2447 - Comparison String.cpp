#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n; string s; cin >> n >> s;
		int i = 0, j = 0, res = 0;
		while (i != n) {
			while (j < n && s[j] == s[i]) j++;
			res = max(res, j - i); i = j;
		}
		cout << res + 1 << '\n';
	}
}