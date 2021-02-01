#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double pi = 3.14159265359;

int main() {
	long long x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	long long dx = x1 - x2, dy = y1 - y2;
	long double d = sqrt(dx * dx + dy * dy);
	if (d >= r1 + r2) { cout << 0.0 << endl; }
	else if (d <= abs(r1 - r2)) { 
		long long m = (r1 < r2) ? r1 : r2;
		cout << fixed << setprecision(10) << pi * m * m << endl;
	}
	else {
		long double a = acos((r2 * r2 + d * d - r1 * r1 + 0.0) / (2 * r2 * d + 0.0));
		long double b = acos((r1 * r1 + d * d - r2 * r2 + 0.0) / (2 * r1 * d + 0.0));
		long double s1 = a * r2 * r2, t1 = r2 * r2 * sin(2 * a) / 2.0;
		long double s2 = b * r1 * r1, t2 = r1 * r1 * sin(2 * b) / 2.0;
		long double ans = s1 + s2 - t1 - t2;
		cout << fixed << setprecision(10) << ans << endl;
	}
	cin.ignore(2); return 0;
}