#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1 << 30;

struct Point {
	ll x, y; Point() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	bool operator == (const Point& rhs) const { return x == rhs.x && y == rhs.y; }
	Point operator - (const Point& rhs) const { return Point(x - rhs.x, y - rhs.y); }
	Point operator + (const Point& rhs) const { return Point(x + rhs.x, y + rhs.y); }
};

istream& operator >> (istream& is, Point& p) { is >> p.x >> p.y; return is; }
ostream& operator << (ostream& os, const Point& p) { os << p.x << p.y; return os; }
ll dotProduct(Point A, Point B) { return A.x * B.x + A.y * B.y; }
ll crossProduct(Point A, Point B) { return A.x * B.y - A.y * B.x; }
ll dist2(Point A, Point B) { return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }

//0: Colinear 1: Clockwise 2: Counterclockwise
inline int orientation(Point& A, Point& B, Point& C) {
	ll x = crossProduct(C - B, B - A);
	return x ? 1 + (x < 0) : 0;
}

//Checks if P belongs to (AB)
inline bool pointInLine(Point& A, Point& B, Point& P) {
	return crossProduct(A - P, B - P) == 0;
}

//Checks if P belongs to [AB]
inline bool pointInSegment(Point& A, Point& B, Point& P) {
	return pointInLine(A, B, P) && dotProduct(A - P, B - P) <= 0;
}

//Check if (AB) and (CD) intersect
inline bool intersectionLineLine(Point& A, Point& B, Point& C, Point& D) {
	return crossProduct(B - A, D - C) != 0 || pointInLine(A, B, C);
}

//Checks if [AB] and (CD) intersect
inline bool intersectionSegmentLine(Point& A, Point& B, Point& C, Point& D) {
	if (!intersectionLineLine(A, B, C, D)) return false;
	if (pointInLine(C, D, A) || pointInLine(C, D, B)) return true;

	return orientation(C, D, A) != orientation(C, D, B);
}

//Check if [AB] and [CD] intersect
inline bool intersectionSegmentSegment(Point& A, Point& B, Point& C, Point& D) {
	return intersectionSegmentLine(A, B, C, D) && intersectionSegmentLine(C, D, A, B);
}

inline bool pointInTriangle(Point& A, Point& B, Point& C, Point& P) {
	ll ABC = abs(crossProduct(B - A, C - A));
	ll PAB = abs(crossProduct(A - P, B - P));
	ll PAC = abs(crossProduct(A - P, C - P));
	ll PBC = abs(crossProduct(B - P, C - P));
	return ABC == PAB + PAC + PBC;
}

//0: Outside  1: Inside  2: Boundary
//Assumes first and last point in P are equal
int pointInPolygon(vector<Point>& P, Point& A) {
	bool boundary = false; int n = (int)P.size() - 1;
	for (int i = 0; i < n; i++)
		if (pointInSegment(P[i], P[i + 1], A)) {
			boundary = true; break;
		}
	if (boundary) { return 2; }

	Point B(A.x + 1, INF);
	int cnt = 0; for (int i = 0; i < n; i++)
		cnt += intersectionSegmentSegment(P[i], P[i + 1], A, B);
	return cnt & 1;
}

//Points must be sorted by angle w.r.t first point
bool pointInConvexPolygon(vector<Point>& P, Point X) {
	if (pointInSegment(P.front(), P.back(), X)) { return true; }
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

}