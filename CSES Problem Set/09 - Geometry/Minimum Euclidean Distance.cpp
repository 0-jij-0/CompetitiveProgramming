#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
	ll x, y; Point() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	bool operator < (const Point& rhs) const { return x < rhs.x; }
};
istream& operator >> (istream& is, Point& p) { is >> p.x >> p.y; return is; }
ll dist2(Point A, Point B) { return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }

vector<Point> points;

bool yCoord(const Point& lhs, const Point& rhs) { return lhs.y < rhs.y; }

ll closestPair(vector<Point>& P) {
	if (P.size() < 2) { return (ll)8e18; }

	int n = (int)P.size(), mid = n >> 1; ll Xmid = P[mid].x;
	vector<Point> L(P.begin(), P.begin() + mid);
	vector<Point> R(P.begin() + mid, P.end());
	ll miL = closestPair(L), miR = closestPair(R);
	merge(L.begin(), L.end(), R.begin(), R.end(), P.begin(), yCoord);

	ll res = min(miL, miR);
	vector<Point> B; for (auto& p : P) {
		ll dx = p.x - Xmid;
		if (dx * dx < res) B.push_back(p);
	}

	int m = (int)B.size();
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++) {
			ll dy = B[j].y - B[i].y;
			if (dy * dy >= res) { break; }
			res = min(res, dist2(B[i], B[j]));
		}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; points.resize(n);
	for (auto& x : points) cin >> x;
	sort(points.begin(), points.end());

	cout << closestPair(points) << '\n';
}