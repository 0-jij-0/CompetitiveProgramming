#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dp[2000][2002]; vector<ll> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	v.resize(n); for (auto& x : v) cin >> x;
	for (int i = 0; i < n; i++) dp[i][0] = 0;
	for (int i = 0; i < n; i++) dp[i][i + 2] = -(1ll << 60);

	dp[0][1] = v[0]; for (int i = 1; i < n; i++)
		for (int L = 1; L <= min(i + 1, m); L++) {
			dp[i][L] = max(dp[i - 1][L], dp[i - 1][L - 1] + L * v[i]);
		}

	cout << dp[n - 1][m] << '\n';
}