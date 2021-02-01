#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[31][31][51];

int minCost(int x, int y, int k) {
	if (x * y == k || k == 0) { return 0; }
	if (dp[x][y][k] != -1) { return dp[x][y][k]; }

	int res = 1 << 29;
	for (int i = 1; i <= x - i; ++i)
		for (int j = 0; j <= k; ++j)
			res = min(res, y * y + minCost(i, y, k - j) + minCost(x - i, y, j));

	for (int i = 1; i <= y - i; ++i)
		for (int j = 0; j <= k; ++j)
			res = min(res, x * x + minCost(x, y - i, k - j) + minCost(x, i, j));

	return dp[x][y][k] = res;
}
int main() {
	fill(dp[0][0], dp[0][0] + 31 * 31 * 51, -1ll);
	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		cout << minCost(a, b, c) << endl;
	}
	cin.ignore(2); return 0;
}