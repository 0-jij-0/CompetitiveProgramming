#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x*x) % mod)
		if (n & 1)res = (res*x) % mod;
	return res;
}

int main() {
	int n; cin >> n;
	if (n == 1) { cout << 0 << '\n'; return 0; }
	ll one = power(9, n), two = power(8, n);
	ll sub = ((one << 1) - two + mod) % mod;
	cout << (power(10, n) - sub + mod) % mod << '\n';
	cin.ignore(2); return 0;
}