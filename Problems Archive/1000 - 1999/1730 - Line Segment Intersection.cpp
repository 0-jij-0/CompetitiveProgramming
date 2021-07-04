#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double ld;

struct Point {
	ll x, y; Point() {}
	Point(int _x, int _y) : x(_x), y(_y) {}
	Point operator - (const Point &rhs) const { return Point(x - rhs.x, y - rhs.y); }
	ll operator * (const Point &rhs) const { return x * rhs.y - y * rhs.x; }
};

istream& operator >> (istream &is, Point &p) { is >> p.x >> p.y; return is; }
ll dot(Point &p1, Point &p2) { return p1.x * p2.x + p1.y * p2.y; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		Point OA, OB, OC, OD;
		cin >> OA >> OB >> OC >> OD;

		Point AB = OB - OA, CD = OD - OC, AC = OC - OA;
		ll ABxCD = AB * CD, ACxAB = AC * AB, ACxCD = AC * CD;
		
		if (ABxCD != 0) { 
			if (ACxAB && ((ABxCD < 0) ^ (ACxAB < 0))) { cout << "NO\n"; continue; }
			if (ACxCD && ((ABxCD < 0) ^ (ACxCD < 0))) { cout << "NO\n"; continue; }
			cout << (abs(ABxCD) >= max(abs(ACxAB), abs(ACxCD)) ? "YES" : "NO") << '\n';
		}
		else if (ACxCD != 0) { cout << "NO" << '\n'; }
		else {
			ld t0 = (dot(AC, AB) + 0.0) / (dot(AB, AB) + 0.0);
			ld t1 = t0 + (dot(CD, AB) + 0.0) / (dot(AB, AB) + 0.0);
			if (t0 > t1) { swap(t0, t1); }
			cout << (t0 > 1.0 || t1 < 0.0 ? "NO" : "YES") << '\n';
		}

	}

	cin.ignore(2); return 0;
}