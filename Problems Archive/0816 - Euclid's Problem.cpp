#include <iostream>
using namespace std;
typedef long long ll;

ll extGCD(ll a, ll b, ll &x, ll &y) {
	if (b == 0) { x = 1; y = 0;	return a; }
	ll x1, y1, d = extGCD(b, a % b, x1, y1);
	x = y1; y = x1 - y1 * (a / b);
	return d;
}

int main() {
	while (true) {
		ll a; cin >> a; if (cin.fail()) { break; }
		ll b, x, y; cin >> b;
		ll g = extGCD(a, b, x, y);
		cout << x << ' ' << y << ' ' << g << endl;
	}
	cin.ignore(2); return 0;
}