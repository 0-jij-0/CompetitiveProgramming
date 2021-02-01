#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long double ld;

ld EPS = 1e-12;

struct PT {
	ld x, y;
	PT() {}
	PT(ld x, ld y) : x(x), y(y) {}
	PT(const PT &p) : x(p.x), y(p.y) {}
	PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
	PT operator * (ld c) const { return PT(x*c, y*c); }
	PT operator / (ld c) const { return PT(x / c, y / c); }
};
ld dot(PT p, PT q) { return p.x*q.x + p.y*q.y; }
ld dist2(PT p, PT q) { return dot(p - q, p - q); }

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p) { return PT(-p.y, p.x); }

// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<PT> CircleLineIntersection(PT a, PT b, PT c, ld r) {
	vector<PT> ret;
	b = b - a;
	a = a - c;
	ld A = dot(b, b);
	ld B = dot(a, b);
	ld C = dot(a, a) - r * r;
	ld D = B * B - A * C;
	if (D < -EPS) return ret;
	ret.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
	if (D > EPS)
		ret.push_back(c + a + b * (-B - sqrt(D)) / A);
	return ret;
}
// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
vector<PT> CircleCircleIntersection(PT a, PT b, ld r, ld R) {
	vector<PT> ret;
	ld d = sqrt(dist2(a, b));
	if (d > r + R || d + min(r, R) < max(r, R)) return ret;
	ld x = (d*d - R * R + r * r) / (2 * d);
	ld y = sqrt(r*r - x * x);
	PT v = (b - a) / d;
	ret.push_back(a + v * x + RotateCCW90(v)*y);
	if (y > 0)
		ret.push_back(a + v * x - RotateCCW90(v)*y);
	return ret;
}

vector<PT> res; PT O;
vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	cin >> O.x >> O.y; PT cur(0.0, 0.0);
	if (O.x == 0 && O.y == 0) { res.push_back(cur = PT(v[0], 0)); v.erase(v.begin()); n--; }

	cout << fixed << setprecision(10);
	int s = accumulate(v.begin(), v.end(), 0);
	for (int i = 0; i < n; i++) {
		s -= v[i]; ld d = dist2(cur, O);
		if (s + v[i] < sqrt(d)) {
			for (int j = i; j < n; j++) {
				vector<PT> pts = CircleLineIntersection(cur, O, cur, v[j]);
				if (dist2(pts[0], O) > dist2(pts[1], O)) { swap(pts[0], pts[1]); }
				res.push_back(cur = pts[0]);
			}
			break;
		}
		if (abs(s - v[i]) > sqrt(d)) {
			vector<PT> pts = CircleLineIntersection(cur, O, cur, v[i]);
			if (dist2(pts[0], O) < dist2(pts[1], O)) { swap(pts[0], pts[1]); }
			if (v[i] > s) { swap(pts[0], pts[1]); }
			res.push_back(cur = pts[0]); continue;
		}
		vector<PT> p = CircleCircleIntersection(cur, O, v[i], s);
		res.push_back(cur = p[0]);
		for (int j = i + 1; j < n; j++) {
			vector<PT> pts = CircleLineIntersection(cur, O, cur, v[j]);
			if (dist2(pts[0], O) > dist2(pts[1], O)) { swap(pts[0], pts[1]); }
			res.push_back(cur = pts[0]); 
		}
		break;
	}
	for (auto &x : res) cout << x.x << ' ' << x.y << '\n';
	cin.ignore(2); return 0;
}