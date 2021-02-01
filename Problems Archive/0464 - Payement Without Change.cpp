#include <iostream>
using namespace std;

int main() {
	int q; cin >> q;
	while (q--) {
		int a, b, n, s; cin >> a >> b >> n >> s;
		int x = s / n, y = s % n;
		if (x <= a && y <= b) { cout << "YES" << endl; continue; }
		if (x <= a && y > b) { cout << "NO" << endl; continue; }
		if (x > a && y > b) { cout << "NO" << endl; continue; }
		int z = x - a; x = a; y += n * z;
		cout << (y <= b ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}