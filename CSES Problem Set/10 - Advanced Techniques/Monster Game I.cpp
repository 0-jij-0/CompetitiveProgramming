#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
	ll x = 0, y = 0;
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	Point operator - (const Point& rhs) const { return Point(x - rhs.x, y - rhs.y); }
};

ll dotProduct(Point A, Point B) { return A.x * B.x + A.y * B.y; }
ll crossProduct(Point A, Point B) { return A.x * B.y - A.y * B.x; }
Point normal(Point P) { return Point(-P.y, P.x); }

deque<Point> convexHull, normalVectors;

void addLineCHT(ll k, ll b) { // Adding the line kx + b
	Point P(k, b); while (!normalVectors.empty()) {
		if (dotProduct(normalVectors.back(), P - convexHull.back()) > 0) break;
		normalVectors.pop_back(); convexHull.pop_back();
	}

	if (!convexHull.empty()) normalVectors.emplace_back(normal(convexHull.back() - P));
	convexHull.push_back(P);
}

vector<ll> dp, s, f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x;
	s.resize(n); for (auto& x : s) cin >> x;
	f.resize(n); for (auto& x : f) cin >> x;
	dp.resize(n, 0); addLineCHT(x, 0);

	for (int i = 0; i < n; i++) {
		Point P(s[i], 1); while (!normalVectors.empty()) {
			if (crossProduct(normalVectors.front(), P) >= 0) break;
			normalVectors.pop_front(); convexHull.pop_front();
		}
		dp[i] = dotProduct(P, convexHull.front());
		addLineCHT(f[i], dp[i]);
	}

	cout << dp[n - 1] << '\n';
}