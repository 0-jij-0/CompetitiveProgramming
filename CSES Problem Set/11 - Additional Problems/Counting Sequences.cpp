#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<ll> fact(1000001, 1);

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll nCk(int n, int k) {
	ll denum = (fact[k] * fact[n - k]) % mod;
	return (fact[n] * power(denum, mod - 2)) % mod;
}

int main() {
	for (int i = 1; i <= 1000000; i++)
		fact[i] = (i * fact[i - 1]) % mod;

	int n, k; cin >> n >> k; 
	bool sub = false; ll res = 0;
	for (int i = 0; i < k; i++, sub ^= 1) {
		ll cur = (nCk(k, i) * power(k - i, n)) % mod;
		res = (sub ? res - cur + mod : res + cur) % mod;
	}
	cout << res << '\n';
}