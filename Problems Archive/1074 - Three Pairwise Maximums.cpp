#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int x, y, z; cin >> x >> y >> z;
		if (x > z) { swap(x, z); }
		if (y > z) { swap(y, z); }
		if (x > y) { swap(x, y); }
		if (z != y) { cout << "NO" << endl; continue; }
		cout << "YES" << endl;
		cout << z << ' ' << x << ' ' << 1 << endl;
	}
	cin.ignore(2); return 0;
}