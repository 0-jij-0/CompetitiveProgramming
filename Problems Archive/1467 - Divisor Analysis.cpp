#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll modInv(ll x) { return power(x, mod - 2); }
ll divCount(const ll& p, const ll& e) { return e + 1; }
ll divSum(const ll& p, const ll& e) { return ((power(p, e + 1) - 1) * modInv(p - 1)) % mod; }

int main() {
	int n; cin >> n; bool square = true;
	ll dC = 1, dC2 = 1, dC3 = 1, dS = 1, dP = 1, N = 1, SR = 1;
	for (int i = 0; i < n; i++) {
		ll p, e; cin >> p >> e; ll dc = divCount(p, e);
		dC = (dC * dc) % mod; dC2 = (dC2 * dc) % (mod - 1);
		dS = (dS * divSum(p, e)) % mod;
		N = (N * power(p, e)) % mod;
		SR = (SR * power(p, e >> 1)) % mod;

		if (square && e % 2 != 0) {
			square = false;
			dC3 = (dC3 * dc / 2) % (mod - 1);
		}
		else { dC3 = (dC3 * dc) % (mod - 1); }
	}
	dP = square ? power(SR, dC2) : power(N, dC3);
	cout << dC << ' ' << dS << ' ' << dP << '\n';
	cin.ignore(2); return 0;
}