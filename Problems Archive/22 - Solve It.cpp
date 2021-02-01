#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double funct(int a, int b, int c, int d, int e, int f, double x) {
	double e_x = exp(-x);
	double sinx = sin(x);
	double cosx = cos(x);
	double tanx = tan(x);
	double x2 = x * x;

	return (a * e_x) + (b * sinx) + (c * cosx) + (d * tanx) + (e * x2) + f;
}

double dichotomy(int a, int b, int c, int d, int e, int f, double i, double j) {
	double x = funct(a, b, c, d, e, f, i);
	double y = 0.0;
	double z = funct(a, b, c, d, e, f, j);
	if (x == 0.0) { return i; }
	if (z == 0.0) { return j; }
	if (x*z > 0.0) { return -1.0; }

	double med = 0.0;
	for(int k = 0; k < 50; k++) {
		med = (i + j) / 2.0;
		x = funct(a, b, c, d, e, f, i);
		y = funct(a, b, c, d, e, f, med);
		z = funct(a, b, c, d, e, f, j);
		if (y == 0.0) { return med; }
		if (x*y < 0.0) { j = med;  continue; }
		i = med;		
	}
	return med;
}

int main() {
	int a, b, c, d, e, f;
	while (true) {
		cin >> a;
		if (cin.fail()) { break; }
		cin >> b >> c >> d >> e >> f;
		double sol = dichotomy(a, b, c, d, e, f, 0.0000, 1.000);
		if (sol == -1.0) { cout << "No solution" << endl; }
		else { cout << fixed << setprecision(4) << sol << endl; }
	}
	cout << endl; cin.ignore(2); return 0;
}