#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> point;
vector<pair<point, int>> v;
const double pi = 3.1415926535897932384626433;

long double angle(const point &p) {
	long double b = (long double) atan2(p.second, p.first);
	if (b < 0) { b += 2 * pi; }
	return b;
}

bool operator < (const point &p1, const point & p2) {
	return angle(p1) < angle(p2);
}

bool compare(const pair<point, int> &p1, const pair<point, int> &p2) {
	return p1.first < p2.first;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y; point p(x, y);
		pair<point, int> pp(p, i); v.push_back(pp);
	}
	sort(v.begin(), v.end(), compare);
	long double dif = 360.0; int id1 = -1, id2 = -1;
	for (int i = 1; i < n; i++) {
		long double d = angle(v[i].first) - angle(v[i - 1].first);
		if (d < dif) { dif = d; id1 = v[i].second; id2 = v[i - 1].second; }
	}
	long double d = angle(v[0].first) - angle(v[n - 1].first); d += 2 * pi;
	if (d < dif) { id1 = v[0].second; id2 = v[n - 1].second; }
	if (id1 > id2) { swap(id1, id2); }
	cout << id1 + 1 << ' ' << id2 + 1 << endl;
	cin.ignore(2); return 0;
}