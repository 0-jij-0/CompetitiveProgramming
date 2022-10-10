#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll power2(int n) {
	ll res = 1;
	for (ll x = 2; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

int main() {
	int n; cin >> n; cout << power2(n) << '\n';
}