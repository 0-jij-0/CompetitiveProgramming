#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t;
	while (t--) {
		ll x, y; cin >> x >> y; ll ma = max(--x, --y); 
		if (ma == 0) { cout << 1 << endl; continue; }
		if (ma == x && x % 2) { cout << (x + 1) * (x + 1) - y << endl; continue; }
		if (ma == x) { cout << x * x + y + 1 << endl; continue; }
		if (y % 2) { cout << y * y + x + 1 << endl; continue; }
		cout << (y + 1) * (y + 1) - x << endl;
	}
	cin.ignore(2); return 0;
}