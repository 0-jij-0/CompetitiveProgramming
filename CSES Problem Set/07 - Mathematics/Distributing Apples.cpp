#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;
const int FCTSZ = 2 * 1000 * 1000 + 7;

ll power(ll x, ll n) {
	ll res = 1, a = x;
	for (; n; n >>= 1, a = (a * a) % mod)
		if (n & 1) res = (res * a) % mod;
	return res;
}

ll modInv(ll x) { return power(x, mod - 2); }

vector<ll> fact(FCTSZ, 1);

int main() {
	for (int i = 1; i <= FCTSZ; i++) fact[i] = (i * fact[i - 1]) % mod;
	int n, m; cin >> n >> m;
	ll res = (fact[n + m - 1] * modInv((fact[n - 1] * fact[m]) % mod)) % mod;
	cout << res << '\n';
}