#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Point {
	double x, y; Point() {}
	Point(double _x, double _y) : x(_x), y(_y) {}
};

// Calculate the angle between the line from p1 to p2
// and the line from p3 to p4
double CalcAngle(Point &p1, Point &p2, Point &p3, Point &p4) {
	double x1 = p2.x - p1.x, y1 = p2.y - p1.y;
	double x2 = p4.x - p3.x, y2 = p4.y - p3.y;
	double a1 = atan2(y1, x1), a2 = atan2(y2, x2);
	return abs(a2 - a1);
}

double dist(Point p1, Point p2) {
	double dx = p1.x - p2.x, dy = p1.y - p2.y;
	return sqrt(dx * dx + dy * dy);
}

// Find the points where the two circles intersect; assumes they intersect at 1 or 2 points
vector<Point> FindCircleCircleIntersections(Point c0, double r0, Point c1, double r1)
{
	// Find the distance between the centers.
	double dx = c0.x - c1.x, dy = c0.y - c1.y;
	double d = sqrt(dx * dx + dy * dy);

	double a = (r0 * r0 - r1 * r1 + d * d) / (2 * d);
	double h = sqrt(r0 * r0 - a * a);

	// Find P2.
	double cx2 = c0.x + a * (c1.x - c0.x) / d;
	double cy2 = c0.y + a * (c1.y - c0.y) / d;

	// Get the points P3.
	Point P1 = Point((cx2 + h * (c1.y - c0.y) / d), (cy2 - h * (c1.x - c0.x) / d));
	Point P2 = Point((cx2 - h * (c1.y - c0.y) / d), (cy2 + h * (c1.x - c0.x) / d));
	return { P1, P2 };
}

// Find the tangent points for this circle and external point.
vector<Point> FindTangents(Point &C, double r, Point &P) {
	Point pt1, pt2;
	// Find the distance squared from the external point to the circle's center.
	double dx = C.x - P.x, dy = C.y - P.y;
	double D_squared = dx * dx + dy * dy;

	// Find the distance from the external point to the tangent points.
	double L = sqrt(D_squared - r * r);
	return FindCircleCircleIntersections(C, r, P, L);
}

const double pi = 3.141592653589793;

int main() {
	int xs, ys, xd, yd; cin >> xs >> ys >> xd >> yd;
	Point start(xs, ys), dest(xd, yd);
	int tt; cin >> tt >> tt >> tt;
	int xc, yc; double r; cin >> xc >> yc >> r;
	Point center(xc, yc);

	vector<Point> pS = FindTangents(center, r, start);
	vector<Point> pD = FindTangents(center, r, dest);

	double ans = 1e20;
	for (Point &p1 : pS) {
		for (Point &p2 : pD) {
			double cur = dist(start, p1) + dist(p2, dest);
			double angle = CalcAngle(center, p1, center, p2);
			cur += min(angle, 2*pi - angle) * r; ans = min(ans, cur);
		}
	}

	cout << fixed << setprecision(10) << ans << endl;
	cin.ignore(2); return 0;
}