#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll modInv(ll x) { return power(x, mod - 2); }

ll geomSum(ll f, ll q, ll k) {
	ll num = (power(q, k) - 1 + mod) % mod;
	ll denum = (q - 1 + mod) % mod;
	ll frac = num * modInv(denum) % mod;
	return (f * frac) % mod;
}

int main() {
	freopen("dice.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k, r, m; cin >> n >> k >> r >> m;
		ll lose = ((r - 1) * modInv(r)) % mod;
		ll win = power(lose, k - 1);
		win = (win * modInv(r)) % mod;

		ll draw = power(lose, n);

		cout << geomSum(win, draw, m) << '\n';
	}
}