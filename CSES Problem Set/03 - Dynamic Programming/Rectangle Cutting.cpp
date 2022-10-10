#include <bits/stdc++.h>
using namespace std;

int dp[501][501];

int main() {
	int a, b; cin >> a >> b;
	if (a < b) swap(a, b);

	for(int i = 1; i <= a; i++)
		for (int j = 1; j <= min(i, b); j++) {
			if (i == j) { dp[i][j] = 0; continue; }
			if (i == 1) { dp[i][j] = dp[j][i] = j - 1; continue; }
			if (j == 1) { dp[i][j] = dp[j][i] = i - 1; continue; }
			dp[i][j] = dp[j][i] = i * j + 1;
			for (int k = 1; k <= i / 2; k++)
				dp[i][j] = dp[j][i] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
			for (int k = 1; k <= j / 2; k++)
				dp[i][j] = dp[j][i] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
		}
	cout << dp[a][b] << '\n';
}