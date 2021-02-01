#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef double ld;

vector<ld> p, dp[2];

int main() {
	int n; cin >> n; p.resize(n);
	dp[0].resize(n + 1, 0.0); dp[1].resize(n + 1, 0.0);
	for (auto &x : p) { cin >> x; }
	dp[0][0] = 1.0; for (int i = 1; i <= n; i++) {
		dp[i & 1][0] = dp[(i ^ 1) & 1][0] * (1.0 - p[i - 1]);
		for (int j = 1; j <= n; j++)
			dp[i & 1][j] = p[i - 1] * dp[(i ^ 1) & 1][j - 1] + (1.0 - p[i - 1]) * dp[(i ^ 1) & 1][j];
	}
	int s = (n + 1) >> 1; ld res = 0.0;
	while (s <= n) res += dp[n & 1][s++];
	cout << fixed << setprecision(10) << res << '\n';
	cin.ignore(2); return 0;
}