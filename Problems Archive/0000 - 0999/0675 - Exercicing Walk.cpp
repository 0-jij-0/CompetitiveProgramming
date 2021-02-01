#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		int absH = b - a, absV = d - c;
		if ((a + b) && x1 == x2) { cout << "NO" << endl; continue; }
		if ((c + d) && y1 == y2) { cout << "NO" << endl; continue; }
		if (absH >= 0 && x2 - x < absH) { cout << "NO" << endl; continue; }
		if (absV >= 0 && y2 - y < absV) { cout << "NO" << endl; continue; }
		if (absH < 0 && x - x1 < -absH) { cout << "NO" << endl; continue; }
		if (absV < 0 && y - y1 < -absV) { cout << "NO" << endl; continue; }
		cout << "YES" << endl;
	}
	cin.ignore(2); return  0;
}