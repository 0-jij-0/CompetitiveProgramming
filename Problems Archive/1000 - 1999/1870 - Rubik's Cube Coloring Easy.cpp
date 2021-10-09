#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll power(ll x, ll n, ll m = 1ll << 61) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % m)
		if (n & 1) res = (res * x) % m;
	return res;
}

int main() {
	int k; cin >> k; 
	ll res = 6 * power(4, power(2, k) - 2, mod);
	cout << res % mod << '\n';
	cin.ignore(2); return 0;
}