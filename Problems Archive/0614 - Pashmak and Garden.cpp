#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	if (x1 > x2) { swap(x1, x2); swap(y1, y2); }
	if (x1 == x2) {
		int d = abs(y2 - y1);
		cout << x1 + d << ' ' << y1 << ' ' << x1 + d << ' ' << y2 << endl;
	}
	else if (y1 == y2) {
		int d = abs(x2 - x1);
		cout << x1 << ' ' << y1 + d << ' ' << x2 << ' ' << y1 + d << endl;
	}
	else if (abs(x2 - x1) != abs(y2 - y1)) { cout << -1 << endl; }
	else { cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1 << endl; }
	cin.ignore(2); return 0;
}