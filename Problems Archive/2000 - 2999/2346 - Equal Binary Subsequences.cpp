#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> s; n <<= 1;

		if (count(s.begin(), s.end(), '1') & 1) {
			cout << "-1\n"; continue;
		}

		vector<int> swaps;
		for (int i = 0; i < n; i += 2)
			if (s[i] != s[i + 1]) swaps.push_back(i);

		cout << swaps.size() << ' '; char prev = '0';
		for (auto& x : swaps) {
			cout << (s[x] == prev ? x + 2 : x + 1) << ' ';
			prev = prev == '0' ? '1' : '0';
		}

		cout << '\n'; for (int i = 0; i < n; i += 2)
			cout << i + 1 << ' '; cout << '\n';
	}
}