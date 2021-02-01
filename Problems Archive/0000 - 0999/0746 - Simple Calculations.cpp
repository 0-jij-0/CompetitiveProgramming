#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;

ll euler_phi(ll n) {
	ll res = n;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			while (n % i == 0) { n /= i; }
			res -= res / i;
		}
	if (n > 1) { res -= res / n; }
	return res;
}

ll power(ll x, ll n, const ll &mod) {
	if (!n) { return 1; }
	ll res = power(x, n >> 1, mod);
	res = (res * res) % mod;
	if (n & 1) { return (res * x) % mod; }
	return res;
}

int main() {
	ifstream ifs("calc.in");
	ofstream ofs("calc.out");
	ll n, k; cin >> n >> k;
	ll res = 0;
	if (n < 60) {
		ll p = 1ll << n;
		res = power(2, p, k);
	}
	else {
		ll phiK = euler_phi(k);
		ll p = power(2, n, phiK);
		res = power(2, phiK + p, k);
	}
	cout << (res + 1) % k << endl; 
	ifs.close(); ofs.close();
	cin.ignore(2); return 0;
}