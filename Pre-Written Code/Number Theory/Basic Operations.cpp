#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> rabinMillerBases = {2, 3, 5, 7, 11};

ll power(ll x, ll n, ll mod) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

bool rabinMiller(ll n) {
	if (n < 2) { return false; }
	if (n < 4) { return true; }
	if (n % 6 != 1 && n % 6 != 5) return false;

	int r = 0; ll d = n - 1; while (!(d & 1)) { r++; d >>= 1; }
	for (auto& a : rabinMillerBases) {
		if (a >= n) { return true; }
		ll x = power(a, d, n); bool ok = false;
		if (x == 1 || x == n - 1) { continue; }
		for (int i = 1; i < r; i++) {
			x = (x * x) % n;
			if (x == n - 1) { ok = true; break; }
		}
		if (!ok) { return false; }
	}
	return true;
}

ll extGCD(ll a, ll b, ll &x, ll &y) {
	if (b == 0) { x = 1; y = 0;	return a; }
	ll x1, y1, d = extGCD(b, a % b, x1, y1);
	x = y1; y = x1 - y1 * (a / b);
	return d;
}

ll modInv(ll a, ll m) {
	ll x, y, g = extGCD(a, m, x, y);
	if (g != 1) { return 0; }
	return (x % m + m) % m;
}

ll eulerPhi(ll n) {
	ll res = n;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			while (n % i == 0) { n /= i; }
			res -= res / i;
		}
	if (n > 1) { res -= res / n; }
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}