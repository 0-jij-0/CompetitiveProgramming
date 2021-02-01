#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a[3];
int dp[3][2];

int main() {
	int n; cin >> n; a[0].resize(n + 1, 0);
	a[1].resize(n + 1, 0); a[2].resize(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[0][i] >> a[1][i] >> a[2][i];

	fill(dp[0], dp[0] + 6, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++) {
			dp[j][i & 1] = 0; for (int k = 0; k < 3; k++) if (k != j)
				dp[j][i & 1] = max(dp[j][i & 1], dp[k][(i ^ 1) & 1] + a[k][i]);
		}

	cout << max({ dp[0][n & 1], dp[1][n & 1], dp[2][n & 1] }) << '\n';
	cin.ignore(2); return 0;
}