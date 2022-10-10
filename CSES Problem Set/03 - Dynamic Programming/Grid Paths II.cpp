#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;

int dp[2][1001];
vector<string> v; int n;

int main() {
	cin >> n; v.resize(n); dp[0][0] = 1;
	for (auto &x : v) { cin >> x; }
	if (v[0][0] == '*') { cout << 0 << '\n'; return 0; }
	
	for (int i = 1; i < n; i++)
		dp[0][i] = dp[0][i - 1] && (v[0][i] == '.');

	for (int i = 1; i < n; i++) {
		dp[i & 1][0] = dp[(i & 1) ^ 1][0] && (v[i][0] == '.');
		for (int j = 1; j < n; j++)
			if (v[i][j] == '*') dp[i & 1][j] = 0;
			else dp[i & 1][j] = (dp[(i & 1) ^ 1][j] + dp[i & 1][j - 1]) % mod;
	}

	cout << dp[(n & 1) ^ 1][n - 1] << '\n';
}