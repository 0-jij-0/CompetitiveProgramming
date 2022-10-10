#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll mod = 1000 * 1000 * 1000 + 7;

vector<ll> fact(2 * 1000 * 1000 + 1);

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1)res = (res * x) % mod;
	return res;
}

inline ll modInv(ll x) { return power(x, mod - 2); }

ll choose(int n, int k) {
	ll num = fact[n];
	ll den = (fact[n - k] * fact[k]) % mod;
	return (num * modInv(den)) % mod;
}

int main() {
	int n; cin >> n; fact[0] = 1; int m = n >> 1;
	if (n % 2) { cout << 0 << '\n'; return 0; }
	for (int i = 1; i <= 2 * 1000 * 1000; i++)
		fact[i] = (fact[i - 1] * i) % mod;
	cout << (choose(n, m) * modInv(m + 1)) % mod << '\n';
}