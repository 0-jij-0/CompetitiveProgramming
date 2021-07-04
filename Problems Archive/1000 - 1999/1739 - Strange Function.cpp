#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	int t; cin >> t; while (t--) {
		ll n; cin >> n; ll res = 0;
		ll cur = 1; for (ll i = 2; cur <= n; i++) {
			ll g = i / gcd(i, cur);
			ll cont = ((n / cur) - (n / cur) / g) % mod;
			cont = (cont * i) % mod; cur *= g;
			res = (res + cont) % mod; 
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}