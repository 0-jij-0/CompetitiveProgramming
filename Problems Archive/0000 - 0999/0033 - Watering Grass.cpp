#include <iostream>
#include <cmath>
#include <map>
#include <fstream>
using namespace std;

map<double, double> segments;

void circle_to_segment(int x, int radius, int &w, double &a, double &b) {
	double r2 = (double) radius * radius;
	double w2 = (w / 2.0) * (w / 2.0);
	double c = sqrt(r2 - w2);
	a = x - c; b = x + c;
}

int min_coverage(double l) {

	if (segments.empty()) { return -1; }
	int count = 0;
	map<double, double>::iterator it = segments.begin();
	double left = 0, &right = l;
	for (; it != segments.end(); it++) {
		if (it->second <= left) { continue; }

		double max_right = 0.0;
		while (it != segments.end() && it->first <= left) {
			if (it->second > max_right) { max_right = it->second; }
			it++;
		}
		if (max_right == 0.0) { return -1; }

		left = max_right; count++;
		if (left >= right) { break; }
		if (it == segments.end()) { return -1; }
		it--;
	}
	return count;
}

void input(int &l, int &n, int &w) {
	
	int x, radius;
	double a, b;
	map<int, int> circles;
	for (int i = 0; i < n; i++) {
		cin >> x >> radius;
		if (x + radius <= 0 || x - radius >= l || radius <= (w + 0.0) / 2.0) { continue; }
		circles[x] = (circles[x] < radius) ? radius : circles[x];
	}

	map<int, int>::iterator it = circles.begin();
	for (; it != circles.end(); it++) {		
		circle_to_segment(it->first, it->second, w, a, b);
		if (a >= l || b <= 0) { continue; }
		segments[a] = (segments[a] < b) ? b : segments[a];
	}
}

int main() {

	while (true) {
		int n; cin >> n; if (cin.fail()) { break; }
		int l, w; cin >> l >> w; segments.clear();
		input(l, n, w);
		int res = min_coverage(l + 0.0);
		cout << res << endl;
	}
	cout << endl; cin.ignore(2); return 0;
}