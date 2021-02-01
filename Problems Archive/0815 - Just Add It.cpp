#include <iostream>
using namespace std;
typedef long long ll;

const ll mod = 1000 * 1000 * 10 + 7;

ll power(ll x, ll n) {
	if (!n) { return 1; }
	ll res = power(x, n >> 1);
	res = (res * res) % mod;
	if (n & 1) { return (res * x) % mod; }
	return res;
}

int main() {
	while (true) {
		ll n, k; cin >> n >> k;
		if (n + k == 0) { break; }
		ll a = (2 * power(n - 1, k)) % mod;
		ll b = power(n, k);
		ll c = (2 * power(n - 1, n - 1)) % mod;
		ll d = power(n, n);
		cout << (a + b + c + d) % mod << endl;
	}
	cin.ignore(2); return 0;
}