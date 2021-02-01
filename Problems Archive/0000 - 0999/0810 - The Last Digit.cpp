#include <iostream>
using namespace std;
typedef long long ll;

ll power(ll x, ll n) {
	if (n < 0) { return 0; }
	if (!n) { return 1; }
	ll res = power(x, n >> 1);
	res = (res * res) % 10;
	if (n & 1) { return (res * x) % 10; }
	return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		ll a, b; cin >> a >> b;
		cout << power(a, b) << endl;
	}
	cin.ignore(2); return 0;
}