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

int main() {
	ll n; cin >> n; 
	ll res = power(2, n * n); if (n & 1) {
		ll N = (n + 1) / 2, fix13 = (N * N - N + 1);
		res = (res + 2 * power(2, fix13)) % mod;

		ll fix2 = (n * n - 1) / 2 + 1;
		res = (res + power(2, fix2)) % mod;
	}
	else {
		ll N = n / 2, fix13 = N * N;
		res = (res + 2 * power(2, fix13)) % mod;

		ll fix2 = n * n / 2;
		res = (res + power(2, fix2)) % mod;
	}

	res = (res * power(4, mod - 2)) % mod;
	cout << res << '\n';
	cin.ignore(2); return 0;
}