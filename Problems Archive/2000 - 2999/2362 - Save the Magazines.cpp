#include <bits/stdc++.h>
using namespace std;

vector<int> v; string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> s; v.resize(n);
		for (auto& x : v) cin >> x;

		int i = 0; while (i < n && s[i] == '1') i++;
		for (int j = i + 1; i < n; i = j++) {
			if (j == n || s[j] == '0') { continue; }
			while (j < n && s[j] == '1') { j++; continue; }
			int k = min_element(v.begin() + i, v.begin() + j) - v.begin();
			s[i] = '1'; s[k] = '0';
		}

		int res = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '1') res += v[i];
		cout << res << '\n';
	}
}