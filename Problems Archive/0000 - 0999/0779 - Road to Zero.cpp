#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t;
	while (t--) {
		ll x, y; cin >> x >> y;
		ll a, b; cin >> a >> b;
		if (2 * a <= b) { cout << a * (x + y) << endl; continue; }
		cout << b * min(x, y) + a * (max(x, y) - min(x, y)) << endl;
	}
	cin.ignore(2); return 0;
}