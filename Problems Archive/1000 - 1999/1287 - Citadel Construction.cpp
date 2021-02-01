#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
typedef int ll;

struct pt {
	ll x, y;
	pt(ll xx = 0, ll yy = 0) :x(xx), y(yy) {}
	bool operator == (pt &a) { return (a.x - x == 0) && (a.y - y == 0); }
};

bool operator < (const pt &a, const pt &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

pt operator-(pt &a, pt &b) { return pt(a.x - b.x, a.y - b.y); }
ll vec(pt a, pt b) { return a.x*b.y - a.y*b.x; }
ll det(pt &a, pt &b, pt &c) { return vec(b - a, c - a); }

bool right(pt &X, pt &Y, pt &Z) { return (det(X, Y, Z) <= 0); }

vector<pt> convexhull(vector<pt> &ab) {
	sort(ab.begin(), ab.end());
	ab.erase(unique(ab.begin(), ab.end()), ab.end());
	int l = (int)ab.size(), i, j = 0, k;
	vector<pt> res(l + 1); if (l < 3) { return move(ab); }

	for (i = 0; i < l; i++) {
		while (j - 2 >= 0 && right(res[j - 2], res[j - 1], ab[i])) { j--; }
		res[j++] = ab[i];
	}
	k = j;
	for (i = l - 2; i >= 0; i--) {
		while (j - 1 >= k && right(res[j - 2], res[j - 1], ab[i])) { j--; }
		res[j++] = ab[i];
	}
	if (res[j - 1] == res[0]) { j--; }
	return move(vector<pt>(res.begin(), res.begin() + j));
}

//Polygon area
double area(vector<pt> &p, const int &n) {
	double a = 0;
	for (int i = 0; i < n; i++) {
		a += (p[i].x * p[(i + 1) % n].y - p[(i + 1) % n].x * p[i].y);
	}
	return abs(a) / 2.0;
}

ll dist(pt &p1, pt &p2, pt &P) {
	ll dy = p2.y - p1.y, dx = p2.x - p1.x;
	ll xy = p2.x * p1.y, yx = p2.y * p1.x;
	return abs(dy * P.x - dx * P.y + xy - yx);
}

vector<pt> points, hull;

ll findMax(int &i, int &j, int l, int r) {
	while (l < r) {
		int diff = (r - l) / 3;
		int mid1 = l + diff;
		int mid2 = l + (diff ? diff * 2 : 1);

		ll d1 = dist(hull[i], hull[j], hull[mid1]);
		ll d2 = dist(hull[i], hull[j], hull[mid2]);
		if (d1 > d2) { r = mid2 - 1; }
		else { l = mid1 + 1; }
	}
	return dist(hull[i], hull[j], hull[l]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; points.resize(n);
		for (int i = 0; i < n; i++)
			cin >> points[i].x >> points[i].y;

		hull = convexhull(points); n = (int)hull.size();
		if (n <= 4) { cout << (double)area(hull, n) << '\n'; continue; }

		ll ans = 0; hull.insert(hull.begin(), hull.begin(), hull.end());

		for (int i = 0; i < n; i++) {
			for (int j = i + 2; j < n; j++) {
				ll d1 = findMax(i, j, i + 1, j - 1);
				ll d2 = findMax(i, j, j + 1, n + i - 1);
				ans = max(ans, d1 + d2);
			}
		}
		if (ans % 2) { cout << fixed << setprecision(1) << ans / 2.0 << '\n'; }
		else cout << (ans >> 1) << '\n';
	}
	cin.ignore(2); return 0;
}