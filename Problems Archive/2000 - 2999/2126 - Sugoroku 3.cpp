#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll modInv(ll x) { return power(x, mod - 2); }

ll dp[200001];
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n - 1);
	for (auto& x : v) cin >> x;

	dp[n - 1] = dp[n]  = 0;
	for (int i = n - 2; i >= 0; i--) {
		ll p = modInv(v[i] + 1);
		dp[i] = (1 + (dp[i + 1] - dp[i + v[i] + 1] + mod) * p) % mod;
		dp[i] = (dp[i] * modInv(1 - p + mod)) % mod;
		if (i) dp[i] = (dp[i] + dp[i + 1]) % mod;
	}

	cout << dp[0] % mod << '\n';
}