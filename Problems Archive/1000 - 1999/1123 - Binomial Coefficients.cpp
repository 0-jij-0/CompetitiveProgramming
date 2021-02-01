#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;
const int FCTSZ = 1000 * 1000 + 7;

ll power(ll x, ll n) {
	ll res = 1, a = x;
	for (; n; n >>= 1, a = (a * a) % mod)
		if (n & 1) res = (res * a) % mod;
	return res;
}

ll modInv(ll x) { return power(x, mod - 2); }

vector<ll> fact(FCTSZ, 1);

int main() {
	for (int i = 1; i <= 1000000; i++) fact[i] = (i * fact[i - 1]) % mod;
	int n; cin >> n; while (n--) {
		int a, b; cin >> a >> b;
		ll res = (fact[a] * modInv((fact[b] * fact[a - b]) % mod)) % mod;
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}