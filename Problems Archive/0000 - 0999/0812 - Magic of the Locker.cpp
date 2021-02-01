#include <iostream>
using namespace std;
typedef long long ll;

const ll mod = 1000 * 1000 * 1000 + 7;

ll power(ll x, ll n) {
	if (!n) { return 1; }
	ll res = power(x, n >> 1);
	res = (res * res) % mod;
	if (n & 1) { return (res * x) % mod; }
	return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		if (n < 2) { cout << 1 << endl; continue; }
		if (n < 5) { cout << n << endl; continue; }
		if (n % 3 == 0) { cout << power(3, n / 3) << endl; continue; }
		if (n % 3 == 1) { cout << (4 * power(3, (n - 4) / 3)) % mod << endl; continue; }
		if (n % 3 == 2) { cout << (2 * power(3, (n - 2) / 3)) % mod << endl; continue; }
	}
	cin.ignore(2); return 0;
}