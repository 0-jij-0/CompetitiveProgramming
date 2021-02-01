#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> w; vector<ll> v;
vector<vector<ll>> dp;

int main() {
	int n, W; cin >> n >> W; w.resize(n); v.resize(n);
	for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
	dp.resize(2, vector<ll>(W + 1, 0));
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= W; j++) {
			dp[i & 1][j] = max({ dp[i & 1][j], dp[(i ^ 1) & 1][j], dp[i & 1][j - 1] });
			if (j >= w[i - 1]) dp[i & 1][j] = max(dp[i & 1][j], dp[(i ^ 1) & 1][j - w[i - 1]] + v[i - 1]);
		}
	cout << dp[n & 1][W] << '\n';
	cin.ignore(2); return 0;
}