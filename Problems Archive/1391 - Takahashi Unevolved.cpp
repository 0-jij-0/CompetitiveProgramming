#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ll x, y, a, b; cin >> x >> y >> a >> b;
	ll exp = 0, m = y / x, mult = 0;
	while (m) { mult++; m /= a; }
	for (ll i = 0; i <= mult + 1; i++) {
		if (x >= (y + a - 1) / a) { break; }
		if ((x * a) - x >= b) { break; }
		exp++; x *= a;
	}
	ll add = max(0ll, (y - x - 1) / b);
	cout << exp + add << '\n';
	cin.ignore(2); return 0;
}