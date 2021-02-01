#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

int dp[1000001][26];

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll primeStrings(const int &k, int n) {
	if (n == 1) { return dp[n][k] = k; }
	if (dp[n][k] != -1) { return dp[n][k]; }
	ll res = 0; bool isPrime = true;
	for (int i = 2; i * i <= n; i++) if (n % i == 0) {
		isPrime = false; res = (res + primeStrings(k, i)) % mod;
		if (i * i != n) res = (res + primeStrings(k, n / i)) % mod;
	}
	return dp[n][k] = (power(k, n) - k - res + 2*mod) % mod;
}

int main() {
	fill(dp[0], dp[0] + 26 * 1000001, -1);
	int t; cin >> t; while (t--) {
		int k, n; cin >> k >> n;
		cout << primeStrings(k, n) << '\n';
	}
	cin.ignore(2); return 0;
}