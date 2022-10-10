#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

struct Point {
	ll x, y; Point() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	bool operator == (const Point& rhs) const { return x == rhs.x && y == rhs.y; }
	Point operator - (const Point& rhs) const { return Point(x - rhs.x, y - rhs.y); }
	Point operator + (const Point& rhs) const { return Point(x + rhs.x, y + rhs.y); }
}; typedef vector<Point> Polygon;
istream& operator >> (istream& is, Point& p) { is >> p.x >> p.y; return is; }

ll polygonArea(Polygon &P) { //Assumes points have integer coordinates
	ll a = 0; int n = (int)P.size() - 1;
	for (int i = 0; i < n; i++)
		a += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
	return abs(a);
}

ll lineLatticePoints(Point& A, Point& B) {
	ll x = abs(A.x - B.x), y = abs(A.y - B.y);
	return gcd(x, y) + 1;
}

ll polygonBoundaryLattice(Polygon &P) { //Assumes points have integer coordinates
	ll B = 0; int n = (int)P.size() - 1;
	for (int i = 0; i < n; i++)
		B += lineLatticePoints(P[i], P[i + 1]) - 1;
	return B;
}

ll polygonInteriorLattice(Polygon &P) { //Pick theorem: A = I + B/2 - 1
	ll A = polygonArea(P), B = polygonBoundaryLattice(P);
	return (A - B + 2) >> 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; Polygon P(n);
	for (auto& x : P) { cin >> x; }
	P.push_back(P.front());

	cout << polygonInteriorLattice(P) << ' ';
	cout << polygonBoundaryLattice(P) << '\n';
}