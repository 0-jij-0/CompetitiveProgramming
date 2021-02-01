#include <iostream>
using namespace std;

typedef long long ll;

ll dp[10][1001];
int n, m;
const ll mod = 1000 * 1000 * 1000 + 7;

ll count(int i, int dif) {
	if (i == m || dif == 0) { return 1; }
	if (dp[i][dif] != -1) { return dp[i][dif]; }

	ll res = 0;

	for(int ndif = dif; ndif >= 0; ndif--){
		ll f = dif - ndif + 1;
		res += (f * count(i + 1, ndif)) % mod;
		res %= mod;
	}
	return dp[i][dif] = res;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = -1;

	cout << count(0, n - 1) << endl;
	cin.ignore(2); return 0;
}