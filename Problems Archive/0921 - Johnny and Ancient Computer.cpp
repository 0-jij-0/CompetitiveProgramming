#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t;
	while (t--) {
		ll a, b; cin >> a >> b;
		int x = 0; while (!(a & 1)) { x++; a >>= 1; }
		int y = 0; while (!(b & 1)) { y++; b >>= 1; }
		if (a != b) { cout << -1 << '\n'; continue; }
		cout << (abs(x - y) + 2) / 3 << '\n';
	}
	cin.ignore(2); return 0;
}