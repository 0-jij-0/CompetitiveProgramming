#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll eulerPhi(ll n) {
	ll res = n;
	for (int i = 2; i * i <= n; i++) if (n % i == 0) {
		while (n % i == 0) n /= i; res -= res / i;
	}
	if (n > 1) { res -= res / n; }
	return res;
}

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

int main() {
	int n, m; cin >> n >> m; ll res = 0;
	for (int i = 1; i * i <= n; i++) if(n % i == 0) {
		res = (res + eulerPhi(n / i) * power(m, i)) % mod;
		if (i * i != n) { res = (res + eulerPhi(i) * power(m, n / i)) % mod; }
	}

	res = (res * power(n, mod - 2)) % mod;
	cout << res << '\n'; cin.ignore(2); return 0;
}