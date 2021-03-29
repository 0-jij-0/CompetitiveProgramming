#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
typedef double ld;
const ld PI = 3.14159265358979;

ld dist2(ld x1, ld y1, ld x2, ld y2) {
	ld dx = x1 - x2, dy = y1 - y2;
	return dx * dx + dy * dy;
}

ld angle(int N) { return 2 * PI / N; }

void rotatePoint(ld& X, ld& Y, ld angle) {
	ld x = X * cos(angle) - Y * sin(angle);
	ld y = X * sin(angle) + Y * cos(angle);
	X = x; Y = y;
}

int main() {
	int n; cin >> n;
	int x0, y0, xn, yn; cin >> x0 >> y0 >> xn >> yn;
	ld R = sqrt(dist2(x0, y0, xn, yn)) / 2.0, a = angle(n);
	ld xm = (x0 + xn + 0.0) / 2.0, ym = (y0 + yn + 0.0) / 2.0;
	ld X0 = x0 - xm, Y0 = y0 - ym, XN = xn - xm, YN = yn - ym;
	ld rotAngle = (x0 == xn) ? PI / 2 : atan((y0 - yn + 0.0) / (x0 - xn + 0.0));

	cout << fixed << setprecision(10);
	rotatePoint(X0, Y0, - rotAngle); rotatePoint(XN, YN, - rotAngle);
	if (X0 < XN) {
		ld X1 = R * cos(PI + a), Y1 = R * sin(PI + a);
		rotatePoint(X1, Y1, rotAngle);
		cout << X1 + xm << ' ' << Y1 + ym << '\n';
	}
	else {
		ld X1 = R * cos(a), Y1 = R * sin(a);
		rotatePoint(X1, Y1, rotAngle);
		cout << X1 + xm << ' ' << Y1 + ym << '\n';
	}

	cin.ignore(2); return 0;
}