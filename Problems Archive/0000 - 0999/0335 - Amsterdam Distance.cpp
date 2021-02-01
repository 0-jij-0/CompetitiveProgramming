#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

int n, m; long double r;
int ax, ay, bx, by;
const long double pi = 3.14159265358979323846264338327;

int main() {
	cin >> m >> n >> r;
	cin >> ax >> ay >> bx >> by;
	long double ratio1, ratio2, ratio3;
	ratio1 = (abs(ay - by) + 0.0) / (n + 0.0);
	long double d1 = ratio1 * r;
	if (ax != bx) {
		ratio2 = (abs(ax - bx) + 0.0) / (m + 0.0);
		int min_y = min(ay, by);
		ratio3 = (min_y + 0.0) / (n + 0.0);
		d1 += pi * ratio3 * r * ratio2;
	}
	ratio1 = (ay + 0.0) / (n + 0.0); ratio2 = (by + 0.0) / (n + 0.0);
	long double d2 = (ratio1 * r) + (ratio2 * r);

	cout << fixed << setprecision(10) << min(d1, d2) << endl;
	cin.ignore(2); return 0;
}