#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int dp[102][102][1002];
int n, k;

int min_moves(int i, int j, int p) {
	if (dp[i][j][p] != -1) { return dp[i][j][p]; }
	if (i == n) { return 0; }
	if (j == k) { return dp[i][j][p] = (v[i] != p) + min_moves(i + 1, j, p); }
	int a = (v[i] == p) ? min_moves(i + 1, j, p) : 1 + min_moves(i + 1, j, p);
	int b = min_moves(i + 1, j + 1, v[i]);
	return dp[i][j][p] = min(a, b);
}

int main() {
	int t; cin >> t;
	for(int idx = 0; idx < t; idx++) {
		cin >> n >> k; v.resize(n);
		for (auto &x : v) { cin >> x; }
		int m = *max_element(v.begin(), v.end());
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= k; j++)
				for (int l = 0; l <= m; l++)
					dp[i][j][l] = -1;

		int res = n;
		for (int i = 1; i <= m; i++) {
			res = min(res, min_moves(0, 0, i));
		}
		cout << "Case #" << idx + 1 << ": " << res << endl;
	}
	cin.ignore(2); return 0;
}