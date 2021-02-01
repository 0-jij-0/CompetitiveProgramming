#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

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

ll power(ll x, ll n, const ll &mod) {
	if (!n) { return 1; }
	ll res = power(x, n >> 1, mod);
	res = (res * res) % mod;
	if (n & 1) { return (res * x) % mod; }
	return res;
}

int main() {
	int n; cin >> n;
	while (n--) {
		ll x, Y; cin >> x >> Y;
		ll y = 1; while (Y--) { y *= 10; }

		ll py = euler_phi(y), ppy = euler_phi(py);
		ll p = power(10, 100, ppy); p += ppy;
		p = power(10, p, py); p += py;
		ll res = power(x, p, y), cur = res;
		for (int i = 0; i < 86399; i++) {
			cur = (cur * x) % y;
			res = min(res, cur);
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}