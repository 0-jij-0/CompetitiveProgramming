#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<vector<ll>> v;
vector<ll> groupCost, dp;

int main() {
	int n; cin >> n; v.resize(n, vector<ll>(n));
	groupCost.resize(1 << n, 0); 
	dp.resize(1 << n, -(1ll << 60));
	dp[(1 << n) - 1] = 0;

	for (auto& x : v) for (auto& y : x) cin >> y;

	for (int m = 3; m < (1 << n); m++)
		for(int i = 0; i < n - 1; i++) if(m & (1 << i))
			for (int j = i + 1; j < n; j++) if (m & (1 << j))
				groupCost[m] += v[i][j];

	for(int m = (1 << n) - 1; m; m--)
		for (int s = m; s; s = (s - 1) & m)
			dp[m ^ s] = max(dp[m ^ s], dp[m] + groupCost[s]);

	cout << dp[0] << '\n';
	cin.ignore(2); return 0;
}