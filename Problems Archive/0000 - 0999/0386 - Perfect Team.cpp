#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int q; cin >> q;
	while (q--) {
		int c, m, x; cin >> c >> m >> x;
		int dif = abs(c - m); x += dif;
		m = c = min(m, c);
		if (x > m) { cout << m << endl; }
		else { cout << x + (m + c - 2 * x) / 3 << endl; }
	}
	cin.ignore(2); return 0;
}