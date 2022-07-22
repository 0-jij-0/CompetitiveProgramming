#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Point {
	ll x = 0, y = 0;
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	Point operator - (const Point& rhs) const { return Point(x - rhs.x, y - rhs.y); }
};

istream& operator >> (istream& is, Point& p) { is >> p.x >> p.y; return is; }
ll dotProduct(Point A, Point B) { return A.x * B.x + A.y * B.y; }
ll crossProduct(Point A, Point B) { return A.x * B.y - A.y * B.x; }
Point normal(Point P) { return Point(-P.y, P.x); }

vector<Point> convexHull, normalVectors;

//Assumes lines are added in monotonic order of slope
void addLineCHT(ll k, ll b) { // Adding the line kx + b
	Point P(k, b); while (!normalVectors.empty()) {
		if (dotProduct(normalVectors.back(), P - convexHull.back()) > 0) break;
		normalVectors.pop_back(); convexHull.pop_back();
	}

	if (!convexHull.empty()) normalVectors.emplace_back(normal(P - convexHull.back()));
	convexHull.push_back(P);
}

//Assumes lines are stored in increasing order of slope (Change lambda to < in case decreasing)
ll getMinCHT(ll x) { // Finds minimum of k_i * x + b_i across all lines (k_i, b_i)
	Point query(x, 1);
	auto it = lower_bound(normalVectors.begin(), normalVectors.end(), query,
		[](Point A, Point B) { return crossProduct(A, B) > 0; });

	return dotProduct(query, convexHull[it - normalVectors.begin()]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}