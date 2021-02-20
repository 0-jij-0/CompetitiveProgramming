#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v;
int dp[101][101][101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; ll x; cin >> n >> x; v.resize(n);
	for (auto& x : v) { cin >> x; }

	fill(dp[0][0][0], dp[0][0][0] + 101 * 101 * 101 * 101, -(1 << 30));
	for(int i = 0; i <= n; i++) for (int mod = 1; mod <= n; mod++) dp[i][0][0][mod] = 0;

	for (int i = 1; i <= n; i++) for (int k = 1; k <= i; k++) 
		for (int m = 0; m < n; m++)	for (int mod = m + 1; mod <= n; mod++) {
			int c = v[i - 1] % mod;	c = (m - c + mod) % mod;
			dp[i][k][m][mod] = max(dp[i - 1][k][m][mod], v[i - 1] + dp[i - 1][k - 1][c][mod]);
		}

	ll res = 1ll << 60;
	for (int k = 1; k <= n; k++) {
		int c = x % k; if (dp[n][k][c][k] <= 0) { continue; }
		res = min(res, (x - dp[n][k][x % k][k]) / k);
	}

	cout << res << '\n';
	cin.ignore(2); return 0;
}