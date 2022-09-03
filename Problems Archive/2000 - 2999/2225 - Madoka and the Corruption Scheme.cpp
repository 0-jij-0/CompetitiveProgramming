#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll fact[100001];

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll choose(int n, int k) {
	ll denum = (fact[k] * fact[n - k]) % mod;
	return (fact[n] * power(denum, mod - 2)) % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fact[0] = fact[1] = 1;
	for (int i = 2; i <= 100000; i++)
		fact[i] = (fact[i - 1] * i) % mod;

	int n, k; cin >> n >> k;
	if (k >= n) { cout << power(2, n) << '\n'; return 0; }

	ll lose = 0; for (int i = 0; i < (n - k); i++)
		lose = (lose + choose(n, i)) % mod;

	cout << (power(2, n) - lose + mod) % mod << '\n';
}