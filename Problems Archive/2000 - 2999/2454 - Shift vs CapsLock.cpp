#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[300001][2];

bool isLower(char c) { return c >= 'a' && c <= 'z'; }

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll X, Y, Z; string s;
	cin >> X >> Y >> Z >> s;
	int n = (int)s.size();

	dp[0][0] = 0; dp[0][1] = Z;
	for (int i = 0; i < n; i++) {
		dp[i + 1][0] = min(dp[i][0] + (isLower(s[i]) ? X : Y), dp[i][1] + min(X, Y) + Z);
		dp[i + 1][1] = min(dp[i][1] + (isLower(s[i]) ? Y : X), dp[i][0] + min(X, Y) + Z);
	}

	cout << min(dp[n][0], dp[n][1]) << '\n';
}