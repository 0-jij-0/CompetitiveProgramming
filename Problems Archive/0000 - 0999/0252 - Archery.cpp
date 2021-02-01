#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

typedef pair<int, int> point;
typedef pair<point, point> segment;
vector<segment> v;
const double pi = 3.14159265359;


double exp() {
	double res = 0.0;
	for (auto &s : v) {
		point &p1 = s.first, &p2 = s.second;
		double dot = p1.first*p2.first + p1.second*p2.second;
		double det = p1.first*p2.second - p2.first*p1.second;
		double range = abs(atan2(det, dot));
		if (range > pi) { range -= pi; }
		res += range / (2.0 * pi);
	}
	return res;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n; v.clear();
		for (int j = 0; j < n; j++) {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			point p1(x1, y1); point p2(x2, y2); segment s(p1, p2);
			v.push_back(s);
		}
		cout << fixed << setprecision(5) << exp() << endl;
	}
	cin.ignore(2); return 0;
}