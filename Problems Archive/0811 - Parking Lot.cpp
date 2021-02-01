#include <iostream>
using namespace std;
typedef long long ll;

ll power(ll x, ll n) {
	if (n < 0) { return 0; }
	if (!n) { return 1; }
	ll res = power(x, n >> 1);
	res *= res;
	if (n & 1) { return res * x; }
	return res;
}

int main() {
	ll n; cin >> n;
	ll ans1 = 2 * 4 * 3 * power(4, n - 3);
	ll ans2 = 4 * 3 * 3 * (n - 3)*power(4, n - 4);
	cout << ans1 + ans2 << endl;
	cin.ignore(2); return 0;
}