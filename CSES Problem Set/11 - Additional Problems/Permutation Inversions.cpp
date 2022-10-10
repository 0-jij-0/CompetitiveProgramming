#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll dp[2][124751];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	int n, k; cin >> n >> k;
	dp[0][0] = 1; for (int i = 1; i <= n; i++) {
		int ma = (i * (i - 1)) >> 1; 
		ll pref = 0; int cur = i & 1, prev = cur ^ 1;
		for (int j = 0; j <= min(k, i - 1); j++)
			dp[cur][j] = (pref = (pref + dp[prev][j]) % mod);
		for (int j = i; j <= min(ma, k); j++)
			dp[cur][j] = (pref = (pref + dp[prev][j] - dp[prev][j - i] + mod) % mod);
	}
 
	cout << dp[n & 1][k] << '\n';
}