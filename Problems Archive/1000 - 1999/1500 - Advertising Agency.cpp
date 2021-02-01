#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<int> v;
vector<ll> fact(1001);

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll modInv(ll x) { return power(x, mod - 2); }

ll choose(int n, int k) {
	ll num = fact[n];
	ll denum = (fact[n - k] * fact[k]) % mod;
	return (num * modInv(denum)) % mod;
}

int main() {
	fact[0] = 1; for (int i = 1; i <= 1000; i++)
		fact[i] = (i * fact[i - 1]) % mod;

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k; v.resize(n);
		for (auto& x : v) { cin >> x; }
		sort(v.rbegin(), v.rend());
		int mi = v[0], miC = 0;
		for (int i = 0; i < k; i++) {
			if (v[i] == mi) { miC++; continue; }
			mi = v[i]; miC = 1;
		}
		int c = count(v.begin(), v.end(), mi);
		cout << choose(c, miC) << '\n';
	}
	cin.ignore(2); return 0;
}