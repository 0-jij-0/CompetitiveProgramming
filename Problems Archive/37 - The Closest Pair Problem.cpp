#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;

struct point {
	double x, y;

	point() {}
	point(double _x, double _y) :
		x(_x), y(_y) {}

	bool operator < (const point &rhs) const {
		bool a = this->x < rhs.x;
		bool b = this->x == rhs.x;
		bool c = this->y < rhs.y;
		return a || (b && c);
	}
};

double distance(point &a, point &b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	double dx2 = dx * dx;
	double dy2 = dy * dy;
	return sqrt(dx2 + dy2);
}

vector<point> points;

double bf_closest_pair(int start, int end) {
	double min = INT_MAX + 0.0;
	for (int i = start; i <= end; i++) {
		for (int j = i + 1; j <= end; j++) {
			double dis = distance(points[i], points[j]);
			min = (dis < min) ? dis : min;
		}
	}
	return min;
}

double closest_pair(int start, int end) {
	if (end - start < 3) { return bf_closest_pair(start, end); }

	int mid = (start + end) / 2;
	double min1 = closest_pair(start, mid);
	double min2 = closest_pair(mid + 1, end);
	double min = (min1 < min2) ? min1 : min2;
	
	for (int i = mid; i >= start; i--) {
		double dxi = points[mid].x - points[i].x;
		if (dxi > min) { break; }
		for (int j = mid + 1; j <= end; j++) {
			double dxj = points[j].x - points[mid].x;
			if (dxj > min) { break; }
			double dy = abs(points[j].y - points[i].y);
			if (dy > min) { continue; }
			double min3 = distance(points[i], points[j]);
			min = (min3 < min) ? min3 : min;
		}
	}
	return min;
}

int main() {
	int n; cin >> n;
	while (n != 0) {
		points.clear();
		for (int i = 0; i < n; i++) {
			double x; cin >> x;
			double y; cin >> y;
			point p(x, y);
			points.push_back(p);
		}
		sort(points.begin(), points.end());
		double min_dis = closest_pair(0, n-1);
		if (min_dis >= 10000.0) { cout << "INFINITY" << endl; }
		else { cout << fixed << setprecision(4) << min_dis << endl; }
		cin >> n;
	}

	cout << endl; cin.ignore(2); return 0;
}