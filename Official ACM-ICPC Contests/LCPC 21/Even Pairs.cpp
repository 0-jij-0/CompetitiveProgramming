#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll div2 = (mod + 1) >> 1;

int countBits(ll n) {
	int res = 0; 
	while (n) { res++; n = n & (n - 1); }
	return res;
}

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

int main() {
	freopen("even.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		ll n; cin >> n;

		ll odd = power(2, countBits(n - 1));
		ll even = ((n % mod) - odd + mod) % mod;

		odd = (odd * (odd - 1)) % mod;
		odd = (odd * div2) % mod;
		even = (even * (even - 1)) % mod;
		even = (even * div2) % mod;
		cout << (even + odd) % mod << '\n';
	}

	cin.ignore(2); return 0;
}