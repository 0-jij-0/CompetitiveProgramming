#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, x, a, b; cin >> n >> x >> a >> b;
		if (a > b) { swap(a, b); }
		if (a - 1 <= x) { x -= a - 1; a = 1; }
		else { a -= x; x = 0; }
		if (n - b <= x) { x -= n - b; b = n; }
		else { b += x; x = 0; }
		cout << b - a << endl;
	}
	cin.ignore(2); return 0;
}