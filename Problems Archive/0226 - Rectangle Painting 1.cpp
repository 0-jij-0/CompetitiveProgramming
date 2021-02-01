#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[50][50][50][50];
vector<vector<bool>> grid;

int min_cost(int i1, int i2, int j1, int j2) {
	if (dp[i1][i2][j1][j2] != -1) { return dp[i1][i2][j1][j2]; }
	if (i1 == i2 && j1 == j2) { return grid[i1][j1]; }
	int res = max(i2 - i1, j2 - j1) + 1;
	for (int i = i1; i < i2; i++) {
		int a = min_cost(i1, i, j1, j2) + min_cost(i + 1, i2, j1, j2);
		res = min(res, a);
	}
	for (int j = j1; j < j2; j++) {
		int a = min_cost(i1, i2, j1, j) + min_cost(i1, i2, j + 1, j2);
		res = min(res, a);
	}
	dp[i1][i2][j1][j2] = res; return res;
}

int main() {
	for (int i1 = 0; i1 < 50; i1++)
		for (int i2 = 0; i2 < 50; i2++)
			for (int i3 = 0; i3 < 50; i3++)
				for (int i4 = 0; i4 < 50; i4++)
					dp[i1][i2][i3][i4] = -1;

	int n; cin >> n; grid.resize(n);
	for (int i = 0; i < n; i++) { grid[i].resize(n); }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			grid[i][j] = (c == '#');
		}
	}
	cout << min_cost(0, n - 1, 0, n - 1) << endl;
	cin.ignore(2); return 0;
}