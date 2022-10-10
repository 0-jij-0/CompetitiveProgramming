#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll choose2(ll n) {
	n %= mod; ll x = n * (n - 1); x %= mod;
	return (x * (mod + 1) / 2) % mod;
}

int main() {
	ll n; cin >> n; ll res = 0;
	for (ll i = 1; i <= n; i++) {
		ll r = n / (n / i), c = (n / i) % mod;
		ll len = (choose2(r + 1) - choose2(i) + mod) % mod;
		res = (res + c * len) % mod; i = r;
	}
	cout << res << '\n';
}