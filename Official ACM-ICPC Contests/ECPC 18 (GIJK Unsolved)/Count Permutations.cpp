#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
 
ll dp[202][202][202];
 
ll f(int n, int K) {
	if (K == 0) { return 0; }
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= K; j++)
			for (int l = 0; l <= i; l++)
				dp[i][j][l] = 0;
 
	dp[0][1][0] = 1;
	for (int i = 1; i < n; i++) {
		//Make streak 1
		for (int j = 1; j <= K; j++) {
			for (int l = 0; l <= i; l++) {
				dp[i][1][l] += (dp[i - 1][j][i - 1] - (l ? dp[i - 1][j][l - 1] : 0));
				dp[i][1][l] %= mod;
			}
		}
 
		//Increase streak
		for (int j = 2; j <= K; j++) {
			for (int l = 1; l <= i; l++) {			
				dp[i][j][l] += dp[i - 1][j - 1][l - 1];
				dp[i][j][l] %= mod;
			}
		}
 
		for (int j = 1; j <= K; j++)
			for (int l = 1; l <= i; l++) {
				dp[i][j][l] += dp[i][j][l - 1]; dp[i][j][l] %= mod;
			}
	}
 
	ll ans = 0;
	for (int i = 1; i <= K; i++) {
		ans += dp[n - 1][i][n - 1]; ans %= mod;
	}
	return ans;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("permutations.in", "r", stdin);
 
	int t; cin >> t;
	while (t--) {
		int n, K; cin >> n >> K;
		ll ans = f(n, K) - f(n, K - 1); ans %= mod;
		if (ans < 0) { ans += mod; }
		cout << ans << '\n';
	}
}