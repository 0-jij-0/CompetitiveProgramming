#include <iostream>
using namespace std;

struct Point {
	int x, y; Point() {}
	Point(int _x, int _y) : x(_x), y(_y) {}
	Point operator - (const Point& rhs) const { return Point(x - rhs.x, y - rhs.y); }
};

istream& operator >> (istream& is, Point& p) { is >> p.x >> p.y; return is; }
int crossProduct(Point A, Point B) { return A.x * B.y - A.y * B.x; }

//0: Colinear 1: Clockwise 2: Counterclockwise
int orientation(Point& A, Point& B, Point& C) {
	int x = crossProduct(C - B, B - A);
	return x ? 1 + (x < 0) : 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Point P[4]; for (int i = 0; i < 4; i++) cin >> P[i];
	bool ok = true; for (int i = 0; i < 4 && ok; i++)
		if (orientation(P[i], P[(i + 1) % 4], P[(i + 2) % 4]) != 2) ok = false;

	cout << (ok ? "Yes" : "No") << '\n';
}