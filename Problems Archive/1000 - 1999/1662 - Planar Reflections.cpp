#include <iostream>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k;

		for (int i = 0; i <= n; i++) dp[1][i] = 1;

		for (int i = 2; i <= k; i++) {
			dp[i][0] = 1; for (int j = 1; j <= n; j++) {
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][n - j]) % mod;
			}
		}

		cout << dp[k][n] << '\n';
	}
	cin.ignore(2); return 0;
}