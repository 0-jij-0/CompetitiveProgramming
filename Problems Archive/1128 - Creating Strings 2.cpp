#include <iostream>
#include <vector>
#include <string>
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

vector<ll> fact(FCTSZ, 1), d(26, 0);

int main() {
	for (int i = 1; i < FCTSZ; i++) fact[i] = (fact[i - 1] * i) % mod;
	string s; cin >> s; int n = (int)s.size();
	for (char &c : s) { d[c - 'a']++; }
	ll inv = 1; for (int i = 0; i < 26; i++) inv = (inv * fact[d[i]]) % mod;
	cout << (fact[n] * modInv(inv)) % mod << endl;
	cin.ignore(2); return 0;
}