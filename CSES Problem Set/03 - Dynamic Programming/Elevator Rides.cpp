#include <bits/stdc++.h>
using namespace std;

pair<int, int> dp[1 << 20];

int main() {
	int n, x; cin >> n >> x; vector<int> v(n);
	for (auto& x : v) { cin >> x; }

	dp[0] = { 0, x }; for (int i = 1; i < (1 << n); i++) {
		dp[i] = { n, x }; for (int b = 0; b < n; b++) if (i & (1 << b)) {
			pair<int, int> cur = dp[i ^ (1 << b)];
			cur.second <= x - v[b] ? cur.second += v[b] : (cur.first++, cur.second = v[b]);
			dp[i] = min(dp[i], cur);
		}
	}

	cout << dp[(1 << n) - 1].first << '\n';
}