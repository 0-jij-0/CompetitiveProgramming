#include <bits/stdc++.h>
using namespace std;

int dp[1 << 20][2];
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fill(dp[0], dp[0] + (1 << 21), 0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; dp[x][0]++; dp[x][1]++; }

	for (int i = 0; i < 20; i++)
		for (int mask = 1; mask < 1 << 20; mask++)
			if (mask & (1 << i)) dp[mask][0] += dp[mask ^ (1 << i)][0];
			else dp[mask][1] += dp[mask ^ (1 << i)][1];

	for (auto& x : v)
		cout << dp[x][0] << ' ' << dp[x][1] << ' ' 
		<< n - dp[((1 << 20) - 1) ^ x][0] << '\n';
}