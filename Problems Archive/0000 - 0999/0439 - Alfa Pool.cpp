#include <iostream>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

ll dp[100001][2];
ll calc(int n, int l) {
	if (dp[n][l] != -1) { return dp[n][l]; }
	if (n == 0) { return 1; }
	ll tot = 0, ctr = 2;
	if (l == 0) { tot += calc(n, 1); }
	while (ctr - 1 <= n) {
		tot += calc(n - (ctr - 1), 1);
		tot = tot % mod; ctr = ctr * 2;
	}
	return dp[n][l] = tot;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < 100001; i++)
		dp[i][0] = dp[i][1] = -1;
	while (t--) {
		int n; cin >> n;
		cout << calc(n, 0) % mod << endl;
	}
}
