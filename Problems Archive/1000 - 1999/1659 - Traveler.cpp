#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
typedef long long ll;

vector<ll> X, C;
vector<array<ll, 2>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; X.resize(n); 
	C.resize(n); v.resize(n + 1, { (1 << 30), -(1 << 30) });
	for (int i = 0; i < n; i++) cin >> X[i] >> C[i];

	v[0][0] = v[0][1] = 0; for (int i = 0; i < n; i++) {
		v[C[i]][0] = min(v[C[i]][0], X[i]);
		v[C[i]][1] = max(v[C[i]][1], X[i]);
	}

	vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

	while (v[n][0] == (1 << 30)) { n--; }
	dp[n][0] = v[n][1] - v[n][0] + abs(v[n][1]); 
	dp[n][1] = (v[n][1] - v[n][0]) + abs(v[n][0]);
	for (int i = n - 1; i >= 0; i--) {
		if (v[i][0] == (1 << 30)) { 
			dp[i][0] = dp[i + 1][0]; dp[i][1] = dp[i + 1][1]; 
			v[i][0] = v[i + 1][0]; v[i][1] = v[i + 1][1];
			continue;
		}
		ll d00 = abs(v[i][0] - v[i + 1][0]), d01 = abs(v[i][0] - v[i + 1][1]);
		ll d10 = abs(v[i][1] - v[i + 1][0]), d11 = abs(v[i][1] - v[i + 1][1]);
		dp[i][0] = v[i][1] - v[i][0] + min(d10 + dp[i + 1][0], d11 + dp[i + 1][1]);
		dp[i][1] = v[i][1] - v[i][0] + min(d00 + dp[i + 1][0], d01 + dp[i + 1][1]);
	}

	cout << dp[0][0] << '\n';
	cin.ignore(2); return 0;
}