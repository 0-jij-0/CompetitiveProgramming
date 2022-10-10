#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll fact[2000001];

ll modInv(ll x) {
	ll res = 1;
	for (ll n = mod - 2; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll choose(int n, int k) {
	if (k < 0) { return 0; }
	ll denum = (fact[n - k] * fact[k]) % mod;
	return (fact[n] * modInv(denum)) % mod;
}

vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fact[0] = fact[1] = 1;
	for (int i = 2; i <= 2000000; i++)
		fact[i] = (fact[i - 1] * i) % mod;

	int n, m; cin >> n >> m; v.resize(m);
	for (auto& [x, y] : v) cin >> x >> y;
	sort(v.begin(), v.end()); v.emplace_back(n, n);

	vector<ll> dp(m + 1);
	for (int i = 0; i <= m; i++) {
		auto &[Xi, Yi] = v[i];
		dp[i] = choose(Xi + Yi - 2, Xi - 1);
		for (int j = 0; j < i; j++) {
			auto& [Xj, Yj] = v[j];
			ll cont = (dp[j] * choose(Xi + Yi - Xj - Yj, Yi - Yj)) % mod;
			dp[i] = (dp[i] - cont + mod) % mod;
		}
	}

	cout << dp[m] << '\n';
}