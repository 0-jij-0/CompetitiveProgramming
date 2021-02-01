#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Frac {
	ll num, denum; Frac() {}
	ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
	Frac(ll _n, ll _d) {
		ll g = gcd(abs(_n), abs(_d));
		num = abs(_n) / g; denum = abs(_d) / g;
		if ((_n < 0) ^ (_d < 0)) { num = -num; }
	}
	Frac(ll x) : num(x), denum(1) {}
	Frac operator *(const Frac &rhs) { return Frac(num * rhs.num, denum * rhs.denum); }
	Frac operator +(const Frac &rhs) { return Frac(num * rhs.denum + denum * rhs.num, denum * rhs.denum); }
	Frac operator -(const Frac &rhs) { return Frac(num * rhs.denum - denum * rhs.num, denum * rhs.denum); }
	Frac operator /(const Frac &rhs) { return Frac(num * rhs.denum, denum * rhs.num); }
	bool operator ==(const Frac &rhs) const { return num == rhs.num && denum == rhs.denum; }
	bool operator <(const Frac &rhs) const { return num * rhs.denum < denum * rhs.num; }
};

struct Point {
	Frac x, y; Point() {}
	Point(Frac _x, Frac _y) : x(_x), y(_y) {}
	Point(ll _x, ll _y) : x(Frac(_x)), y(Frac(_y)) {}
};

Frac dist2(Point p1, const Point p2) {
	Frac dx = p1.x - p2.x, dy = p1.y - p2.y;
	return (dx * dx) + (dy * dy);
}

Frac findCircle(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll x12 = x1 - x2, x13 = x1 - x3, x31 = x3 - x1, x21 = x2 - x1;
	ll y12 = y1 - y2, y13 = y1 - y3, y31 = y3 - y1, y21 = y2 - y1;

	ll sx13 = x1 * x1 - x3 * x3, sx21 = x2 * x2 - x1 * x1;
	ll sy13 = y1 * y1 - y3 * y3, sy21 = y2 * y2 - y1 * y1;

	Frac f(-((sx13) * (x12) + (sy13) * (x12) + (sx21) * (x13) + (sy21) * (x13)), (2 * ((y31) * (x12) - (y21) * (x13))));
	Frac g(-((sx13) * (y12) + (sy13) * (y12) + (sx21) * (y13) + (sy21) * (y13)), (2 * ((x31) * (y12) - (x21) * (y13))));
	//int c = -x1 * x1 - y1 * y1 - 2 * g * x1 - 2 * f * y1;

	//int cx = -g, cy = -f, r2 = f * f + g * g - c;
	return dist2(Point(g, f), Point(x1, y1));
}

map<Frac, int> m;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		m[findCircle(x1, y1, x2, y2, x3, y3)]++;
	}
	int res = 0;
	for (auto &x : m) { res = max(res, x.second); }
	cout << res << endl; cin.ignore(2); return 0;
}