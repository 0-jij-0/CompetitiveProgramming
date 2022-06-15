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
ll getDivCount(const ll& p, const ll& e) { return e + 1; }
ll getDivSum(const ll& p, const ll& e) { return ((power(p, e + 1) - 1) * modInv(p - 1)) % mod; }
ll getDivProd(const ll& p, const ll& e) { return power(p, (e * (e + 1) >> 1)); }

int main() {
	int n; cin >> n;
	ll divCount = 1, divSum = 1, divProd = 1, powerDivCount = 1;
	for (int i = 0; i < n; i++) {
		ll p, e; cin >> p >> e; 
		ll dC = getDivCount(p, e), dS = getDivSum(p, e), dP = getDivProd(p, e);
		divProd = (power(dP, powerDivCount) * power(divProd, dC)) % mod;
		powerDivCount = (powerDivCount * dC) % (mod - 1);
		divCount = (divCount * dC) % mod;
		divSum = (divSum * dS) % mod;
	}
	cout << divCount << ' ' << divSum << ' ' << divProd << '\n';
}
