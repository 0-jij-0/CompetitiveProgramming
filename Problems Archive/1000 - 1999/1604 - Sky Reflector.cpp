#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll power(ll x, ll n) {
	ll res = 1; if (x == 0) { return 0; }
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

int main() {
	int n, m, k; cin >> n >> m >> k;
	ll res = 0; for (int i = 1; i <= k; i++) {
		ll A = (power(i, n) - power(i - 1, n) + mod) % mod;
		if (m == 1) { res = (res + A) % mod; continue; }
		if (n == 1) {
			ll B = (power(k - i + 1, m) - power(k - i, m) + mod) % mod;
			A = (A * B) % mod;
		}
		else { A = (A * power(k - i + 1, m)) % mod; }
		res = (res + A) % mod;
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}