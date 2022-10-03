#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
	ll x, y; Point() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	bool operator == (const Point& rhs) const { return x == rhs.x && y == rhs.y; }
	Point operator - (const Point& rhs) const { return Point(x - rhs.x, y - rhs.y); }
	bool operator < (const Point& rhs) const {
		return (x != rhs.x) ? x < rhs.x : y < rhs.y;
	}
};

istream& operator >> (istream& is, Point& p) { is >> p.x >> p.y; return is; }
ostream& operator << (ostream& os, const Point& p) { os << p.x << p.y; return os; }
ll crossProduct(Point A, Point B) { return A.x * B.y - A.y * B.x; }

//0: Colinear 1: Clockwise 2: Counterclockwise
int orientation(Point& A, Point& B, Point& C) {
	ll x = crossProduct(C - B, B - A);
	return x ? 1 + (x < 0) : 0;
}

//Returns Hull Sorted Counter-Clockwise
vector<Point> convexHullGrahamScan(vector<Point> P) {
	sort(P.begin(), P.end());
	P.erase(unique(P.begin(), P.end()), P.end());
	int n = (int)P.size(); if (n < 3) { return P; }

	vector<Point> res;
	auto incorrect = [&](Point& A, Point& B, Point& C) {
		//Change to == 1 to keep points on CH boundary
		//Chnage to (!= 1 / == 2) to sort Clockwise
		return orientation(A, B, C) != 2;
	};

	int m = 0; for (int i = 0; i < n; ++i) {
		while (m > 1 && incorrect(res[m - 2], res[m - 1], P[i])) { res.pop_back(); --m; }
		res.push_back(P[i]); ++m;
	}

	for (int i = n - 2, M = m; i >= 0; i--) {
		if (P[i] == res[m - 2]) { continue; }
		while (m > M && incorrect(res[m - 2], res[m - 1], P[i])) { res.pop_back(); --m; }
		res.push_back(P[i]); ++m;
	}

	res.pop_back(); return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}