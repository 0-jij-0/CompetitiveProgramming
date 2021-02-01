#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> w, v;
vector<vector<int>> dp;

int main() {
	int n, W; cin >> n >> W; w.resize(n); v.resize(n);
	for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
	dp.resize(2, vector<int>(n * 1000 + 2, 1 << 30));
	dp[0][0] = 0; for (int i = 1; i <= n; i++) {
		fill(dp[i & 1].begin(), dp[i & 1].end(), 1 << 30);
		dp[i & 1][0] = 0; for (int j = n * 1000; j > 0; j--) {
			dp[i & 1][j] = min({ dp[i & 1][j], dp[(i ^ 1) & 1][j], dp[i & 1][j + 1] });
			if (j >= v[i - 1]) dp[i & 1][j] = min(dp[i & 1][j], dp[(i ^ 1) & 1][j - v[i - 1]] + w[i - 1]);
		}
	}
	int res = upper_bound(dp[n & 1].begin(), dp[n & 1].end(), W) - dp[n & 1].begin();
	cout << res - 1 << '\n'; cin.ignore(2); return 0;
}