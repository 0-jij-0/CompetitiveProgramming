#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll euler_phi(ll n) {
	ll res = n;
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0) {
			while (n % i == 0) { n /= i; }
			res -= res / i;
		}
	if (n > 1) { res -= res / n; }
	return res;
}

ll power(ll x, ll n, ll mod) {
	if (n == 0) { return 1; }
	ll res = power(x, n / 2, mod);
	res *= res; res %= mod;
	if (n % 2) { return (res * x) % mod; }
	return res;
}

int a[4] = { 1, 2, 9, 262144 };

ll exponial(ll n, ll mod) {
	if (n < 5) { return a[n - 1] % mod; }
	if (n % mod == 0) { return 0; }
	ll res = 1, next_mod = euler_phi(mod);
	ll next_exp = exponial(n - 1, next_mod);
	return power(n, (next_exp % next_mod) + next_mod, mod);
}

int main() {
	ll n, m; cin >> n >> m;
	cout << exponial(n, m) << endl;
	cin.ignore(2); return 0;
}