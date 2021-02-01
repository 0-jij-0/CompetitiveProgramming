#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;

struct Point {
	ld x, y; Point() {}
	Point(ll x1, ll y1, ll x2, ll y2) : x(x1 / y1), y(x2 / y2) {}
};

struct Line {
	Point A, B; Line() {}
	Line(Point _a, Point _b) : A(_a), B(_b) {}
	ld slope() {
		if (A.x == B.x) { return 1 << 30; }
		return (A.y - B.y) / (A.x - B.x);
	}
	ld yInt() { return A.y - (slope() * A.x); }

	ld distToPoint2(Point &p) {
		ld a = slope(), b(-1), c = yInt();
		ld num = a * p.x + b * p.y + c; num *= num;
		ld denum = a * a + b * b;
		return num / denum;
	}
};


struct pt {
	ll x, y;
	pt(ll xx = 0, ll yy = 0) :x(xx), y(yy) {}
	bool operator == (pt &a) { return (a.x - x == 0) && (a.y - y == 0); }
};
bool operator < (const pt &a, const pt &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
pt operator-(pt a, pt b) { return pt(a.x - b.x, a.y - b.y); }
ll vec(pt a, pt b) { return a.x*b.y - a.y*b.x; }
ll det(pt a, pt b, pt c) { return vec(b - a, c - a); }
bool right(pt X, pt Y, pt Z) { return (det(X, Y, Z) <= 0); }

vector<pt> convexhull(vector<pt> &ab) {
	sort(ab.begin(), ab.end());
	ab.erase(unique(ab.begin(), ab.end()), ab.end());
	int l = (int)ab.size(), i, j = 0, k;
	vector<pt> res(l + 1); if (l < 3) { return ab; }

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

vector<pt> pts;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, R; cin >> N >> R; pts.resize(N);
	for (auto &x : pts) { cin >> x.x >> x.y; }
	vector<pt> CH = convexhull(pts); vector<Point> CH2;
	for (auto &p : CH) { CH2.push_back(Point(p.x, 1, p.y, 1)); }
	CH2.push_back(CH2[0]);

	ld ans = 1e18;
	for (int i = 0; i < CH2.size() - 1; i++) {
		Line curSide = Line(CH2[i], CH2[i + 1]);

		int l = 0, r = i - 1;
		if (i == CH2.size() - 2) { l = 1; }
		ld dist = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			ld curD = curSide.distToPoint2(CH2[mid]);
			ld befD = curD, afterD = curD;
			if (mid > l) { befD = curSide.distToPoint2(CH2[mid - 1]); }
			if (mid < r) { afterD = curSide.distToPoint2(CH2[mid + 1]); }

			if (curD >= befD && curD >= afterD) { if (dist < curD) { dist = curD; } break; }
			curD >= befD ? l = mid + 1 : r = mid - 1;
		}

		l = i + 2; r = CH2.size() - 1;
		if (i == 0) { r--; }
		while (l <= r) {
			int mid = (l + r) / 2;
			ld curD = curSide.distToPoint2(CH2[mid]);
			ld befD = curD, afterD = curD;
			if (mid > l) { befD = curSide.distToPoint2(CH2[mid - 1]); }
			if (mid < r) { afterD = curSide.distToPoint2(CH2[mid + 1]); }

			if (curD >= befD && curD >= afterD) { if (dist < curD) { dist = curD; } break; }
			curD >= befD ? l = mid + 1 : r = mid - 1;
		}
		ans = min(ans, dist);
	}

	cout << setprecision(10) << sqrt(ans) << '\n';
}