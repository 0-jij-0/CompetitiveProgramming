#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll fact[1000001], pow3[1000001];

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll choose(int N, int K) {
	ll denum = (fact[N - K] * fact[K]) % mod;
	return (fact[N] * power(denum, mod - 2)) % mod;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	fact[0] = pow3[0] = 1; 
	for (int i = 1; i <= 1000000; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
		pow3[i] = (3 * pow3[i - 1]) % mod;
	}

	int n, k; cin >> n >> k; ll res = 0;

	if (k == 0) { cout << pow3[n] << '\n'; return 0; }

	for (int S = 1; S <= k && k + S <= n; S++) {
		ll cont = (choose(k - 1, S - 1) * pow3[n - S - k]) % mod;
		cont = (cont * pow3[k - S]) % mod;
		res = (res + cont * choose(n - k, S)) % mod;
	}

	for (int S = 1; S <= k && k + S <= n + 1; S++) {
		ll cont = (choose(k - 1, S - 1) * pow3[n - S - k + 1]) % mod;
		cont = (cont * pow3[k - S]) % mod;
		res = (res + cont * choose(n - k, S - 1)) % mod;
	}

	cout << res << '\n';
}