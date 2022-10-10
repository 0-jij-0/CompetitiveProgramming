#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
const int INF = 2 * 1000 * 1000 * 1000;

struct Point {
	ll x, y; Point() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	bool operator == (const Point& rhs) const { return x == rhs.x && y == rhs.y; }
	Point operator - (const Point& rhs) const { return Point(x - rhs.x, y - rhs.y); }
	Point operator + (const Point& rhs) const { return Point(x + rhs.x, y + rhs.y); }
}; typedef vector<Point> Polygon;

istream& operator >> (istream& is, Point& p) { is >> p.x >> p.y; return is; }
ll dotProduct(Point p1, Point p2) { return p1.x * p2.x + p1.y * p2.y; }
ll crossProduct(Point p1, Point p2) { return p1.x * p2.y - p1.y * p2.x; }

//0: Colinear 1: Clockwise 2: Counterclockwise
int orientation(Point& A, Point& B, Point& C) {
	ll x = crossProduct(C - B, B - A);
	return x ? 1 + (x < 0) : 0;
}

bool pointInsideSegment(Point& A, Point& B, Point& P) {
	if (P == A || P == B) { return true; }
	return crossProduct(A - P, B - P) == 0 && dotProduct(A - P, B - P) < 0;
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

int pointInsidePolygon(Polygon& P, Point& A) {
	bool boundary = false; int n = (int)P.size() - 1;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; Polygon P(n);
	for (auto& x : P) { cin >> x; }
	P.push_back(P.front());

	while (m--) {
		Point A; cin >> A; int x = pointInsidePolygon(P, A);
		if (x == 2) { cout << "BOUNDARY" << '\n'; continue; }
		cout << (x ? "INSIDE" : "OUTSIDE") << '\n';
	}
}