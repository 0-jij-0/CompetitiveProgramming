#include <iostream>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

int ind(int i, int n) {
	if (i % n >= 0) { return i % n; }
	return (i % n) + n;
}

ll dp[1000001][2];
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
	for (int i = 0; i < 1000001; i++)
		dp[i][0] = dp[i][1] = -1;
	static ll pos[1000001]; pos[0] = 1;
	for (int i = 1; i < 1000001; i++)
		pos[i] = (pos[i - 1] + calc(i, 0)) % mod;
	while (t--) {
		int n, n1; cin >> n >> n1;
		if (n == 0) { cout << pos[n1] << endl; }
		else { cout << ind(pos[n1] - pos[n - 1], mod) << endl; }
	}
	cin.ignore(2); return 0;
}