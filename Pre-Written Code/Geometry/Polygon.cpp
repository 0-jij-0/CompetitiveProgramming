#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1 << 30;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

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
		ll A = area(), B = boundaryLatticeCount();
		return (A - B + 2) >> 1;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}