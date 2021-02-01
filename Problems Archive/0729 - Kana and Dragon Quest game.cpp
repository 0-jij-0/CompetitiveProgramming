#include <iostream>
using namespace std;

int spell(int x) { return 10 + (x >> 1); }

int main() {
	int t; cin >> t;
	while (t--) {
		int x, n, m; cin >> x >> n >> m;
		while (n && spell(x) < x) { x = spell(x); n--; }
		cout << ((x <= 10 * m) ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}