#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll div4 = (mod + 1) / 4;

ll power2(ll n) {
	ll res = 1;
	for (ll x = 2; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

int main() {
	ll n; cin >> n; ll n2 = n * n;

	ll fix0 = power2(n2);
	ll fix13 = power2((n2 + 3) >> 2);
	ll fix2 = power2((n2 + 1) >> 1);
	ll res = fix0 + 2 * fix13 + fix2;
	cout << (res * div4) % mod << '\n';
}