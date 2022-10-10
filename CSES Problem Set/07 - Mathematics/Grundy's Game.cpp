#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1223, 0);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 1222; i++) {
		vector<bool> freq(100, false);
		for (int j = 1; j < (i + 1) >> 1; j++) freq[dp[j] ^ dp[i - j]] = true;
		dp[i] = find(freq.begin(), freq.end(), false) - freq.begin();
	}

	int t; cin >> t; while (t--) {
		int n; cin >> n; 
		if (n > 1222) { cout << "first" << '\n'; continue; }
		cout << (dp[n] ? "first" : "second") << '\n';
	}
}