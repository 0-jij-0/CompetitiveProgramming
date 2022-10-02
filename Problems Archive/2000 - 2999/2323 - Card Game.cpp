#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll fact[100];

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll choose(int n, int k) {
	if (k > n) { return 0; }
	ll denum = (fact[n - k] * fact[k]) % mod;
	return (fact[n] * power(denum, mod - 2)) % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fact[0] = fact[1] = 1;
	for (int i = 2; i < 100; i++)
		fact[i] = (fact[i - 1] * i) % mod;

	int t; cin >> t; while (t--) {
		int n; cin >> n; ll res[2] = { 0, 0 };
		for (int i = 0; i < n / 2; i++) {
			int rem1 = (n - 2 * i - 1), rem2 = rem1 - 1;
			res[i & 1] = (res[i & 1] + choose(rem1, rem1 / 2)) % mod;
			res[(i & 1) ^ 1] = (res[(i & 1) ^ 1] + choose(rem2, 2 + (rem2 - 2) / 2)) % mod;
		}
		cout << res[0] << ' ' << res[1] << " 1\n";
	}
}