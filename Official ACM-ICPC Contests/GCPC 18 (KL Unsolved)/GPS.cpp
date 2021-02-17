#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double R = 6371000.0;
const double C = 299792458.0;
const double pi = 3.141592653589793;

struct Point {
	double x, y, z; Point() {}
	Point(double _x, double _y, double _z) :
		x(_x), y(_y), z(_z) {}
};

double tanLength(Point &p) { return p.x * p.x + p.y * p.y + p.z * p.z - R * R; }

Point sphericalToCartesian(const double &r, const double &lo, const double &la) {
	return Point(r * sin(la) * cos(lo), r * sin(la) * sin(lo), r * cos(la));
}

double dist(Point &p1, Point &p2) {
	double dx = p1.x - p2.x, dy = p1.y - p2.y, dz = p1.z - p2.z;
	return dx * dx + dy * dy + dz * dz;
}

void rotatePoint(double &x, double &y, double angle) {
	double X = x * cos(angle) - y * sin(angle);
	double Y = x * sin(angle) + y * cos(angle);
	x = X; y = Y;
}

double toRadians(double p) { return (p * pi) / 180.0; }

Point satellitePoint(double p, double k, double r, double X) {
	double z = 0, y = 0, x = r;
	double rotationAngle = 2.0 * X * pi;

	Point S = sphericalToCartesian(r, rotationAngle, pi/2.0);
	rotatePoint(S.y, S.z, k); rotatePoint(S.x, S.y, p);
	return S;
}

int main() {
	int s; cin >> s;
	double lo, la; cin >> lo >> la; 
	la = 90.0 - la; lo += 360.0;
	la = toRadians(la); lo = toRadians(lo);
	Point M = sphericalToCartesian(R, lo, la);

	for (int i = 0; i < s; i++) {
		double p, k, r, x; cin >> p >> k >> r >> x;
		r *= 1000.0; p += 360.0;
		p = toRadians(p); k = toRadians(k);
		Point S = satellitePoint(p, k, r, x);
		double ST = tanLength(S), SM = dist(S, M);
		if (ST < SM) { cout << "no signal" << endl; continue; }
		cout << fixed << setprecision(10) << sqrt(SM) / C << endl;
	}
	cin.ignore(2); return 0;
}