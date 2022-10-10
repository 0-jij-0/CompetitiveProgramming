#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
	ll x, y; Point() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	Point operator - (const Point& rhs) const { return Point(x - rhs.x, y - rhs.y); }
	ll operator * (const Point& rhs) const { return x * rhs.y - y * rhs.x; }
};

istream& operator >> (istream& is, Point& p) { is >> p.x >> p.y; return is; }


struct Polygon {
	vector<Point> points; int n; Polygon(int _n) : n(_n) { points.resize(n); }

	ll area() {
		ll a = 0; for (int i = 0; i < n - 1; i++)
			a += points[i] * points[i + 1];
		return abs(a);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; Polygon P(n + 1);
	for (int i = 0; i < n; i++)
		cin >> P.points[i];

	P.points.back() = P.points.front();
	cout << P.area() << '\n';
}