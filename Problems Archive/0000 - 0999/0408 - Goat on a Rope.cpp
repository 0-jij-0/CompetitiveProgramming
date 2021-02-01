#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

long double pointDist(int x, int y, int x1, int y1) {
	int dx = x - x1, dy = y - y1;
	return (long double)sqrt(dx*dx + dy*dy);
}

long double segDist(int x, int y, int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		int a = y1, b = y2;
		if (a > b) { swap(a, b); }
		if (y >= b) { return pointDist(x, y, x2, b); }
		else if (y <= a) { return pointDist(x, y, x1, a); }
		return (long double)abs(x - x1);
	}
	else {
		int a = x1, b = x2;
		if (a > b) { swap(a, b); }
		if (x >= b) { return pointDist(x, y, b, y2); }
		else if (x <= a) { return pointDist(x, y, a, y1); }
		return (long double)abs(y - y1);
	}
}

long double d1, d2, d3, d4;

int main() {
	int x, y; cin >> x >> y;
	int x1, y1; cin >> x1 >> y1;
	int x2, y2; cin >> x2 >> y2;
	d1 = segDist(x, y, x1, y1, x1, y2);
	d2 = segDist(x, y, x1, y1, x2, y1);
	d3 = segDist(x, y, x1, y2, x2, y2);
	d4 = segDist(x, y, x2, y1, x2, y2);
	cout << fixed << setprecision(3) << min(min(d1, d2), min(d3, d4)) << endl;
	cin.ignore(2); return 0;
}