#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 998244353;

int dp[51][2501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fill(dp[0], dp[0] + 51 * 2501, 0);
	dp[0][0] = 1;

	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			for (int s = 1; s <= min(j, m); s++)
				dp[i][j] = (dp[i][j] + dp[i - 1][j - s]) % mod;

	int res = 0; for (int i = 0; i <= k; i++)
		res = (res + dp[n][i]) % mod;

	cout << res << '\n';
	cin.ignore(2); return 0;
}