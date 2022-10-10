#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[5000][5000];
int opt[5000][5000];
vector<ll> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; }
	partial_sum(v.begin(), v.end(), v.begin());

	for (int i = 0; i < n; i++) opt[i][i] = i, dp[i][i] = 0;

	for(int i = n - 2; i >= 0; i--)
		for (int j = i + 1; j < n; j++) {
			ll res = 1ll << 62, cost = v[j] - (i ? v[i - 1] : 0);
			for (int k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); k++)
				if (res > dp[i][k] + dp[k + 1][j] + cost) {
					res = dp[i][k] + dp[k + 1][j] + cost;
					opt[i][j] = k;
				}
			dp[i][j] = res;
		}

	cout << dp[0][n - 1] << '\n';
}