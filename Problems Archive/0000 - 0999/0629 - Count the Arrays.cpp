#include <iostream>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
ll fact[200001];

ll power(ll x, int n) {
	if (n == 0) { return 1; }
	ll res = power(x, n / 2);
	res = (res * res) % mod;
	if (n % 2) { return (res * x) % mod; }
	return res;
}

ll modInv(ll n) { return power(n, mod - 2); }
ll nChooseK(int n, int k) { return (fact[n] * modInv((fact[k] * fact[n - k]) % mod)) % mod; }

int main() {
	int n, m; cin >> n >> m; fact[0] = 1;
	for (int i = 1; i <= m; i++) { fact[i] = (fact[i - 1] * i) % mod; }
	ll res = ((nChooseK(m, n - 1) * power(2, n - 3) % mod) * (n - 2)) % mod;
	cout << res << endl; cin.ignore(2); return 0;
}