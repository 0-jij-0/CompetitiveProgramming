#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int dp[2][202][5201];
vector<pair<int, int>> v;

int main() {
	int n, k; cin >> n >> k; v.resize(n, { 0, 0 });
	for (auto &x : v) {
		ll a; cin >> a;
		while (a % 2 == 0) { x.first++; a /= 2; }
		while (a % 5 == 0) { x.second++; a /= 5; }
	}
	fill(dp[0][0], dp[0][0] + 2 * 202 * 5201, -100000); dp[0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		fill(dp[(i + 1) & 1][0], dp[(i + 1) & 1][0] + 202 * 5201, -100000);
		for (int j = 0; j <= k; j++)
			for (int p = 0; p <= 5200 - v[i].second; p++) {
				dp[(i + 1) & 1][j][p] = max(dp[(i + 1) & 1][j][p], dp[i & 1][j][p]);
				dp[(i + 1) & 1][j + 1][p + v[i].second] = max(dp[(i + 1) & 1][j + 1][p + v[i].second], dp[i & 1][j][p] + v[i].first);
			}
	}
	int res = 0; for (int i = 0; i < 5200; i++)
		res = max(res, min(i, dp[n & 1][k][i]));
	cout << res << '\n'; cin.ignore(2); return 0;

}