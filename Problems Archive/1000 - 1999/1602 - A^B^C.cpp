#include <iostream>
using namespace std;
typedef long long ll;

int power(ll x, ll n, int mod) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res % mod;
}

int r[4] = { 6, 2, 4, 8 };

int main() {
	int a, b, c; cin >> a >> b >> c;
	if (a % 10 == 0) { cout << 0 << '\n'; return 0; }
	if (a % 5 == 0) { cout << 5 << '\n'; return 0; }
	
	int y = 0; while (a % 2 == 0) { a >>= 1; y++; }
	int s = power(b, c, 4), ans = power(a, s, 10);
	s = (y * s) % 4; s = (!y ? 1 : r[s]);
	cout << (s * ans) % 10 << '\n';

	cin.ignore(2); return 0;
}