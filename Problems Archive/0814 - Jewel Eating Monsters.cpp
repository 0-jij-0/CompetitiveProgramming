#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;
typedef long long ll;

ll power(ll x, ll n, ll mod) {
	if (!n) { return 1; }
	ll res = power(x, n >> 1, mod);
	res = (res * res) % mod;
	if (n & 1) { return (res * x) % mod; }
	return res;
}

ll euler_phi(ll n) {
	ll res = n;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			while (n % i == 0) { n /= i; }
			res -= res / i;
		}
	if (n > 1) { res -= res / n; }
	return res;
}

ll gcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) { x = 1; y = 0; return a; }
	ll x1, y1, d = gcd(b, a % b, x1, y1);
	x = y1; y = x1 - y1 * (a / b);
	return d;
}

ll modInv(ll a, ll mod) {
	ll x, y, g = gcd(a, mod, x, y);
	if (g != 1) { return 0; }
	return (x % mod + mod) % mod;
}

bool isPrime(ll x) {
	for (ll i = 2; i*i <= x; i++)
		if (!(x % i)) { return false; }
	return true;
}

ll simulate(ll x, ll a, ll n, ll c) {
	ll res = x;
	for (int i = 0; i < n; i++)
		res = (a * ((res - 1 + c) % c)) % c;
	return res;
}

int main() {
	while (true) {
		ll x, a, n, c; cin >> x >> a >> n >> c;
		if (x + a + n + c == 0) { break; }
		if (!isPrime(c) && !modInv(a - 1, c)) { cout << simulate(x, a, n, c) << endl; continue; }
		a %= c; ll A = power(a, n % euler_phi(c), c);
		ll ans1 = (A * (x % c)) % c;
		ll ans2 = (a == 1) ? (n % c) : ((A - 1) * modInv(a - 1, c)) % c;
		ans2 = (a * ans2) % c; ans2 = (-ans2 + c) % c;
		ll ans = (a == 0) ? 0 : (ans1 + ans2) % c;
		cout << ans << endl;
	} 
	cin.ignore(2); return 0;
}