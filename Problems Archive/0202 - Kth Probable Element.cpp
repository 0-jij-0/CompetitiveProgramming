#include <iostream>
#include <iomanip>
using namespace std;

int m, u, l, n, k;
double dp[1005][105];
double range, rrange, lrange;

double prob(int i, int j) {
	if (dp[i][j] != -1.0) { return dp[i][j]; }
	if (i == m || j == 0) { return 1.0; }
	if (m - i == j) {
		dp[i][j] = lrange*prob(i + 1, j - 1) / range;
		return dp[i][j];
	}
	dp[i][j] = rrange*prob(i + 1, j) / range;
	dp[i][j] += lrange*prob(i + 1, j - 1) / range;
	return dp[i][j];
}

int main() {
	cin >> m >> l >> u >> n >> k;
	for (int i = 0; i < 1005; i++)
		for (int j = 0; j < 105; j++)
			dp[i][j] = -1.0;

	range = u - l + 1.0;
	lrange = n - l, rrange = u - n + 1.0;
	double p1 = prob(0, k);

	for (int i = 0; i < 1005; i++)
		for (int j = 0; j < 105; j++)
			dp[i][j] = -1.0;

	lrange++; rrange--;
	double p2 = (n == u) ? 1.0 : prob(0, k);
	cout << fixed << setprecision(12) << p2 - p1 << endl;
	cin.ignore(2); return 0;
}