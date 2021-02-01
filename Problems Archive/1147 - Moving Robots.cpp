#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long double ld;

ld dp[101][8][8][8][8];

ld prob(int k, int x, int y, const int &a, const int &b) {
	if (x > 7 || y > 7) { return 0.0; }
	if (x < 0 || y < 0) { return 0.0; }
	if (abs(x - a) + abs(y - b) > k) { return dp[k][x][y][a][b] = 0.0; }
	if (k == 0) { return dp[k][x][y][a][b] = 1.0; }
	if (dp[k][x][y][a][b] > -0.1) { return dp[k][x][y][a][b]; }

	ld res = 0.0, N = 0.0;
	if (x != 0) { res += prob(k - 1, x - 1, y, a, b); N++; } 
	if (x != 7) { res += prob(k - 1, x + 1, y, a, b); N++; }
	if (y != 0) { res += prob(k - 1, x, y - 1, a, b); N++; }
	if (y != 7) { res += prob(k - 1, x, y + 1, a, b); N++; }

	return dp[k][x][y][a][b] = res / N;
}

int main() {
	fill(dp[0][0][0][0], dp[0][0][0][0] + 101 * 4096, -1.0);
	int k; cin >> k; vector<vector<ld>> pEmpty(8, vector<ld>(8, 0.0));
	for (int a = 0; a < 8; a++) for (int b = 0; b < 8; b++)
		for (int c = 0; c < 8; c++) for (int d = 0; d < 8; d++)
			pEmpty[a][b] += log2l(1.0 - prob(k, c, d, a, b));

	ld res = 0.0; for (int i = 0; i < 64; i++) { res += exp2l(pEmpty[i / 8][i % 8]); }
	cout << fixed << setprecision(6) << res << endl; cin.ignore(2); return 0;
}