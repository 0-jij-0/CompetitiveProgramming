#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Point {
	ll x, y; Point() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	bool operator == (const Point& rhs) const { return x == rhs.x && y == rhs.y; }
	Point operator - (const Point& rhs) const { return Point(x - rhs.x, y - rhs.y); }
	bool operator < (const Point& rhs) const {
		if (x != rhs.x) return x < rhs.x;
		return y < rhs.y;
	}
};

istream& operator >> (istream& is, Point& p) { is >> p.x >> p.y; return is; }
ll crossProduct(Point A, Point B) { return A.x * B.y - A.y * B.x; }

//0: Colinear 1: Clockwise 2: Counterclockwise
int orientation(Point A, Point B, Point C) {
	ll x = crossProduct(C - B, B - A);
	return x ? 1 + (x < 0) : 0;
}

vector<Point> convexHullGrahamScan(vector<Point> P) {
	sort(P.begin(), P.end());
	P.erase(unique(P.begin(), P.end()), P.end());
	int n = (int)P.size(); if (n < 3) { return move(P); }

	vector<Point> res;
	auto incorrect = [&](Point & A, Point & B, Point & C) {
		return orientation(A, B, C) == 2;
	};

	for (int i = 0; i < n; i++) {
		while (res.size() > 1 && incorrect(res.end()[-2], res.end()[-1], P[i])) { res.pop_back(); }
		res.push_back(P[i]);
	}

	int m = (int)res.size();
	for (int i = n - 2; i >= 0; i--) {
		if (P[i] == res.end()[-2]) { continue; }
		while (res.size() > m && incorrect(res.end()[-2], res.end()[-1], P[i])) { res.pop_back(); }
		res.push_back(P[i]);
	}

	res.pop_back(); return move(res);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; vector<Point> P(n);
	for (auto& x : P) { cin >> x; }

	vector<Point> res = convexHullGrahamScan(P);
	cout << res.size() << '\n'; for(auto &x : res)
		cout << x.x << ' ' << x.y << '\n';

	cin.ignore(2); return 0;
}