#include <bits/stdc++.h>
using namespace std;
typedef double ld;

ld dp[2][601];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, a, b; cin >> n >> a >> b;
	fill(dp[0], dp[0] + 601, 0.0);

	dp[0][0] = 1.0;
	for (int i = 1; i <= n; i++) {
		fill(dp[i & 1], dp[i & 1] + 601, 0.0);
		for (int s = i; s <= 6 * i; s++)
			for (int k = 1; k <= min(6, s); k++)
				dp[i & 1][s] += dp[(i & 1) ^ 1][s - k] / 6;
	}

	ld res = 0.0;
	for (int i = max(n, a); i <= b; i++)
		res += dp[n & 1][i];

	cout << fixed << setprecision(6) << res << '\n';
}