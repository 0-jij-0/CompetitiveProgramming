#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000 * 1000 * 1000 + 7;

int dp[2][1000002];
vector<int> v;

int main() {
	int n, x; cin >> n >> x; v.resize(n);
	for (auto &x : v) { cin >> x; }
	fill(dp[0], dp[0] + 2 * 1000002, 0);
	dp[0][0] = 1; for (int i = 1; i <= n; i++) {
		for (int t = 0; t <= x; t++) {
			dp[i & 1][t] = dp[(i + 1) & 1][t]; if (v[i - 1] <= t)
				dp[i & 1][t] = (dp[i & 1][t] + dp[i & 1][t - v[i - 1]]) % mod;
		}
	}
	cout << dp[n & 1][x] << '\n';
}