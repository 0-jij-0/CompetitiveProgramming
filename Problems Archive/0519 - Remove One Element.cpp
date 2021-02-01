#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[200001][2][2];
int n; vector<int> v;

int max_len(int i, bool b, bool c) {
	if (i == n) { return 0; }
	if (dp[i][b][c] != -1) { return dp[i][b][c]; }

	int res = b ? 0 : max_len(i + 1, 1, 1);
	if (!c && v[i] <= v[i - 1]) { return dp[i][b][c] = res; }
	if (c && v[i] <= v[i - 2]) { return dp[i][b][c] = res; }
	res = max(res, 1 + max_len(i + 1, b, 0));
	return dp[i][b][c] = res;
}

int main() {
	cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }

	for (int i = 0; i < n; i++)
		dp[i][0][0] = dp[i][0][1] =
		dp[i][1][0] = dp[i][1][1] = -1;

	int res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, 1 + max_len(i + 1, 0, 0));

	cout << res << endl;
	cin.ignore(2); return 0;
}