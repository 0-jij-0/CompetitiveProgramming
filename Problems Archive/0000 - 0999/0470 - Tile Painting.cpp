#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

bool isPrime(ll n) {
	if (n < 2) { return false; }
	if (n < 4) { return true; }
	if (n % 6 != 1 && n % 6 != 5) { return false; }

	ll m = (ll)floor(sqrt(n + 0.0));
	for(ll i = 2; i <= m; i++)
		if (n % i == 0) { return false; }
	return true;
}

ll spf(ll n) {
	for(ll i = 2; i < n; i++)
		if (n % i == 0) { return i; }
	return -1;
}

int main() {
	ll n; cin >> n;
	if (n == 1) { cout << 1 << endl; }
	else {
		if (isPrime(n)) { cout << n << endl; }
		else {
			ll s = spf(n);
			while (n % s == 0) { n /= s; }
			cout << (n == 1 ? s : 1) << endl;
		}
	}
	cin.ignore(2); return 0;
}