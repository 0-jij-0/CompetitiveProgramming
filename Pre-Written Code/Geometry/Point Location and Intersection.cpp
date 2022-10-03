#include <bits/stdc++.h>
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
ostream& operator << (ostream& os, const Point& p) { os << p.x << ' ' << p.y; return os; }
ll dotProduct(Point A, Point B) { return A.x * B.x + A.y * B.y; }
ll crossProduct(Point A, Point B) { return A.x * B.y - A.y * B.x; }
ll dist2(Point A, Point B) { return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }
Point getNormal(Point P) { return Point(-P.y, P.x); }

//0: Colinear 1: Clockwise 2: Counterclockwise
inline int orientation(Point& A, Point& B, Point& C) {
	ll x = crossProduct(C - B, B - A);
	return x ? 1 + (x < 0) : 0;
}

//Checks if P belongs to (AB) in O(1)
inline bool pointInLine(Point& A, Point& B, Point& P) {
	return crossProduct(A - P, B - P) == 0;
}

//Checks if P belongs to [AB] in O(1)
inline bool pointInSegment(Point& A, Point& B, Point& P) {
	return pointInLine(A, B, P) && dotProduct(A - P, B - P) <= 0;
}

//Checks if (AB) and (CD) intersect in O(1)
inline bool intersectionLineLine(Point& A, Point& B, Point& C, Point& D) {
	return crossProduct(B - A, D - C) != 0 || pointInLine(A, B, C);
}

//Checks if [AB] and (CD) intersect in O(1)
inline bool intersectionSegmentLine(Point& A, Point& B, Point& C, Point& D) {
	if (!intersectionLineLine(A, B, C, D)) return false;
	if (pointInLine(C, D, A) || pointInLine(C, D, B)) return true;

	return orientation(C, D, A) != orientation(C, D, B);
}

//Checks if [AB] and [CD] intersect in O(1)
inline bool intersectionSegmentSegment(Point& A, Point& B, Point& C, Point& D) {
	if (!intersectionSegmentLine(A, B, C, D)) return false;
	if (!intersectionSegmentLine(C, D, A, B)) return false;
	if (crossProduct(B - A, D - C)) return true;

	return pointInSegment(A, B, C) || pointInSegment(A, B, D)
		|| pointInSegment(C, D, A) || pointInSegment(C, D, B);
}

//Checks if P is inside the closed triangle ABC in O(1)
inline bool pointInTriangle(Point& A, Point& B, Point& C, Point& P) {
	ll ABC = abs(crossProduct(B - A, C - A));
	ll PAB = abs(crossProduct(A - P, B - P));
	ll PAC = abs(crossProduct(A - P, C - P));
	ll PBC = abs(crossProduct(B - P, C - P));
	return ABC == PAB + PAC + PBC;
}

//Checks if A is inside the closed polygon P in O(N)
//0: Outside  1: Inside  2: Boundary
//Assumes first and last point in P are equal
int pointInPolygon(vector<Point>& P, Point& A) {
	int n = (int)P.size() - 1;
	for (int i = 0; i < n; i++)
		if (pointInSegment(P[i], P[i + 1], A)) 
			return 2;

	Point B(A.x + 1, INF);
	int cnt = 0; for (int i = 0; i < n; i++)
		cnt += intersectionSegmentSegment(P[i], P[i + 1], A, B);
	return cnt & 1;
}

//Checks if P is inside the closed convex polygon CH in O(logN)
//Assumes points are sorted CounterClockwise
bool pointInConvexPolygon(vector<Point>& CH, Point P) {
	if (pointInSegment(CH.front(), CH.back(), P)) { return true; }
	if (orientation(CH.front(), CH.back(), P) == 2) { return false; }

	int l = 0, r = (int)CH.size() - 1; while (l != r) {
		int mid = (l + r + 1) >> 1;
		bool b = orientation(CH[0], CH[mid], P) == 2;
		b ? l = mid : r = mid - 1;
	}
	return pointInTriangle(CH.front(), CH[l], CH[l + 1], P);
} 

//Finds Maximum Point of P in the direction of (OD) in O(logN)
//Assumes all angles of the polygon are stricly less than 180
Point convexPolygonMaximum(vector<Point>& CH, const Point& D) {
	int N = (int)CH.size();
	auto up = [&](Point& P) { return dotProduct(P, D) > 0; };
	auto same = [&](const Point& P) { return dotProduct(P, D) == 0; };
	auto above = [&](Point& A, Point& B) { return dotProduct(D, A - B) > 0; };
	auto isMaximum = [&](int i) {
		bool aboveL = above(CH[i], CH[(i + N - 1) % N]);
		bool aboveR = above(CH[i], CH[(i + 1) % N]);
		bool sameL = same(CH[i] - CH[(i + N - 1) % N]);
		bool sameR = same(CH[i] - CH[(i + 1) % N]);
		return sameL || sameR ? (sameL ? aboveR : aboveL) : aboveL && aboveR;
	};

	if (isMaximum(0)) return CH[0];

	int L = 0, R = N - 1;
	Point A = CH[1] - CH[0]; while (R - L > 1) {
		int M = (L + R) >> 1; Point C = CH[M + 1] - CH[M];
		if (isMaximum(M)) return CH[M];

		if (up(A)) (!up(C) || above(CH[L], CH[M])) ? R = M : L = M, A = C;
		else (!up(C) && above(CH[M], CH[L])) ? R = M : L = M, A = C;
	}

	return { INF, INF };
}

//Checks whether [AB] intersects with P in O(logN)
bool intersectionSegmentConvexPolygon(vector<Point>& CH, Point& A, Point& B) {
	bool Ain = pointInConvexPolygon(CH, A);
	bool Bin = pointInConvexPolygon(CH, B);
	if (Ain || Bin) { return Ain ^ Bin; }

	Point C = convexPolygonMaximum(CH, getNormal(B - A));
	Point D = convexPolygonMaximum(CH, getNormal(A - B));
	return intersectionSegmentSegment(A, B, C, D);
}


//Assumes the first point of the polygon has smallest x-coordinate
//Assumes the points are sorted counter-clockwise
//Assumes Polygons have at least 3 points each
vector<Point> minkowskiSumConvexPolygons(vector<Point>& CH1, vector<Point>& CH2) {
	// we must ensure cyclic indexing
	int N = (int)CH1.size(), M = (int)CH2.size();
	CH1.push_back(CH1[0]); CH1.push_back(CH1[1]);
	CH2.push_back(CH2[0]); CH2.push_back(CH2[1]);

	// main part
	vector<Point> res; int i = 0, j = 0;
	while (i < N || j < M) {
		res.push_back(CH1[i] + CH2[j]);
		ll cross = crossProduct(CH1[i + 1] - CH1[i], CH2[j + 1] - CH2[j]);
		i += cross >= 0; j += cross <= 0;
	}
	return res;
}

//Checks if CH1 and CH2 intersect in area in O(N)
//Assumes polygons have at least 3 points each
bool intersectionConvexPolygons(vector<Point> CH1, vector<Point> CH2) {
	for (Point& P : CH2) { P.x *= -1; P.y *= -1; }
	rotate(CH2.begin(), min_element(CH2.begin(), CH2.end()), CH2.end());

	vector<Point> minkowskiSum = minkowskiSumConvexPolygons(CH1, CH2);
	return pointInConvexPolygon(minkowskiSum, Point(0, 0));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}