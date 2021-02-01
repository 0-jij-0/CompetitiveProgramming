#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

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

int main() {
	int t; cin >> t;
	while (t--) {
		ll a, m; cin >> a >> m;
		ll g = gcd(a, m); 
		cout << euler_phi(m / g) << endl;
	}
	cin.ignore(2); return 0;
}