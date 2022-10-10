#include <bits/stdc++.h>
using namespace std;

int dp[2][100001];
vector<int> h, s; int n, x;

int main() {
	cin >> n >> x; h.resize(n); s.resize(n);
	for (auto &x : h) { cin >> x; }
	for (auto &x : s) { cin >> x; }
	fill(dp[0], dp[0] + 2 * 100001, 0);
	for(int i = 1; i <= n; i++)
		for (int t = 0; t <= x; t++) {
			int take = t < h[i - 1] ? -1 : s[i - 1] + dp[(i + 1) & 1][t - h[i - 1]];
			dp[i & 1][t] = max({ t ? dp[i & 1][t - 1] : -1, dp[(i + 1) & 1][t], take });
		}
	cout << dp[n & 1][x] << '\n';
}