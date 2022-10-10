#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;

int dp[1000001];
vector<int> v; int n;

int main() {
	int x; cin >> n >> x; v.resize(n);
	for (auto &x : v) { cin >> x; }
	dp[0] = 1; for (int i = 1; i <= x; i++)
		for (int j = 0; j < n; j++) if (v[j] <= i)
			dp[i] = (dp[i] + dp[i - v[j]]) % mod;

	cout << dp[x] << '\n';
}