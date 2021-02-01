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
	for (int i = 1; i < FCTSZ; i++) fact[i] = (i * fact[i - 1]) % mod;
	int n; cin >> n; ll res = 0;
	for (int i = 0; i <= n; i++) {
		int x = modInv(fact[i]);
		if (i % 2 == 0) { res = (res + x) % mod; }
		else { res = (res - x + mod) % mod; }
	}
	cout << (fact[n] * res) % mod << endl;
	cin.ignore(2); return 0;
}