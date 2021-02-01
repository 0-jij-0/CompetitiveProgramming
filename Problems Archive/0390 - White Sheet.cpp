#include <iostream>
using namespace std;

int x, y, x2, y2;

bool update(int x3, int y3, int x4, int y4) {
	if (x3 >= x2 || y3 >= y2 || x4 <= x || y4 <= y) { return true; }
	if (y3 > y && y4 < y2) { return true; }
	if (x3 > x && x4 < x2) { return true; }
	if (x3 > x && x3 < x2 && y3 > y && y3 < y2) { return true; }
	if (x4 > x && x4 < x2 && y4 > y && y4 < y2) { return true; }
	if (x3 <= x && x4 >= x2 && y3 <= y && y4 >= y2) { return false; }
	if (x3 <= x && x4 >= x2 && y3 <= y) { y = y4; return true; }
	if (x3 <= x && x4 >= x2) { y2 = y3; return true; }
	if (y3 <= y && y4 >= y2 && x3 <= x) { x = x4; return true; }
	x2 = x3; return true;
}

int main() {
	cin >> x >> y >> x2 >> y2;
	int x3, y3, x4, y4;
	cin >> x3 >> y3 >> x4 >> y4;
	int x5, y5, x6, y6;
	cin >> x5 >> y5 >> x6 >> y6;
	bool b = update(x3, y3, x4, y4);
	if (!b) { cout << "NO" << endl; }
	else {
		b = update(x5, y5, x6, y6);
		cout << (b ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}