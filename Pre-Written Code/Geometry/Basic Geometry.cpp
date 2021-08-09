#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 2 * 1000 * 1000 * 1000;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

struct Point {
	ll x, y; Point() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	bool operator == (const Point& rhs) const { return x == rhs.x && y == rhs.y; }
	Point operator - (const Point& rhs) const { return Point(x - rhs.x, y - rhs.y); }
	Point operator + (const Point& rhs) const { return Point(x + rhs.x, y + rhs.y); }
};

istream& operator >> (istream& is, Point& p) { is >> p.x >> p.y; return is; }
ll dotProduct(Point A, Point B) { return A.x * B.x + A.y * B.y; }
ll crossProduct(Point A, Point B) { return A.x * B.y - A.y * B.x; }
ll dist2(Point A, Point B) { return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }

struct Polygon {
	vector<Point> points; int n;
	Polygon(int _n) : n(_n), points(_n) {}
	Point& operator [](const int i) { return points[i]; }

	ll area() { //Returns double the area
		ll a = 0; int n = (int)points.size() - 1;
		for (int i = 0; i < n; i++)
			a += crossProduct(points[i], points[i + 1]);
		return abs(a);
	}

	ll boundaryLatticeCount() { //Assumes points have integer coordinates
		ll B = 0; for (int i = 0; i < n; i++) {
			ll dx = abs(points[i].x - points[i + 1].x);
			ll dy = abs(points[i].y - points[i + 1].y);
			B += gcd(dx, dy);
		}
		return B;
	}

	ll interiorLatticeCount() { //Pick theorem: A = I + B/2 - 1
		ll A =area(), B = boundaryLatticeCount();
		return (A - B + 2) >> 1;
	}
};

//0: Colinear 1: Clockwise 2: Counterclockwise
int orientation(Point& A, Point& B, Point& C) {
	ll x = crossProduct(C - B, B - A);
	return x ? 1 + (x < 0) : 0;
}

bool pointInsideSegment(Point& A, Point& B, Point& P) {
	if (P == A || P == B) { return true; }
	return crossProduct(A - P, B - P) == 0 && dotProduct(A - P, B - P) < 0;
}

bool pointInTriangle(Point& A, Point& B, Point& C, Point& P) {
	ll ABC = abs(crossProduct(B - A, C - A));
	ll PAB = abs(crossProduct(A - P, B - P));
	ll PAC = abs(crossProduct(A - P, C - P));
	ll PBC = abs(crossProduct(B - P, C - P));
	return ABC == PAB + PAC + PBC;
}

bool intersectionSegmentSegment(Point& A1, Point& B1, Point& A2, Point& B2) {
	int O1 = orientation(A1, B1, A2), O2 = orientation(A1, B1, B2);
	int O3 = orientation(A2, B2, A1), O4 = orientation(A2, B2, B1);
	if (O1 != O2 && O3 != O4) { return true; }

	if (O1 == 0 && pointInsideSegment(A1, B1, A2)) return true;
	if (O2 == 0 && pointInsideSegment(A1, B1, B2)) return true;
	if (O3 == 0 && pointInsideSegment(A2, B2, A1)) return true;
	if (O4 == 0 && pointInsideSegment(A2, B2, B1)) return true;
	return false;
}

//0: Outside  1: Inside  2: Boundary
int pointInsidePolygon(Polygon& P, Point& A) {
	bool boundary = false; int n = P.n - 1;
	for (int i = 0; i < n; i++)
		if (pointInsideSegment(P[i], P[i + 1], A)) {
			boundary = true; break;
		}
	if (boundary) { return 2; }

	Point B(A.x + 1, INF);
	int cnt = 0; for (int i = 0; i < n; i++)
		cnt += intersectionSegmentSegment(P[i], P[i + 1], A, B);
	return cnt & 1;
}

//First Points must be sorted by angle w.r.t first point
bool pointInConvexPolygon(vector<Point>& P, Point X) {
	if (pointInsideSegment(P.front(), P.back(), X)) { return true; }
	if (orientation(P.front(), P.back(), X) == 2) { return false; }

	int l = 0, r = (int)P.size() - 1; while (l != r) {
		int mid = (l + r + 1) >> 1;
		bool b = orientation(P[0], P[mid], X) == 2;
		b ? l = mid : r = mid - 1;
	}
	return pointInTriangle(P.front(), P[l], P[l + 1], X);
} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin.ignore(2); return 0;
}