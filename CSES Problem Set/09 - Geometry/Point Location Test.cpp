#include <iostream>
using namespace std;
typedef long long ll;

struct Point {
	ll x, y; Point() {}
	Point(int _x, int _y) : x(_x), y(_y) {}
	Point operator - (const Point &rhs) const { return Point(x - rhs.x, y - rhs.y); }
	ll operator * (const Point &rhs) const { return x * rhs.y - y * rhs.x; }
};

istream& operator >> (istream &is, Point &p) { is >> p.x >> p.y; return is; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		Point OA, OB, OC;
		cin >> OA >> OB >> OC;
		Point AB = OB - OA, AC = OC - OA;
		ll crossProduct = AB * AC;
		if (crossProduct == 0) { cout << "TOUCH\n"; }
		else { cout << (crossProduct < 0 ? "RIGHT" : "LEFT") << '\n'; }
	}

	cin.ignore(2); return 0;
}