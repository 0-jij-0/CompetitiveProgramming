#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

struct Point {
	int x, y;
	int count;

	Point() {}
	Point(int ax, int ay) :
		x(ax), y(ay), count(1) {}

	bool operator ==(const Point &rhs) const {
		return (x == rhs.x) && (y == rhs.y);
	}
};

double slope(Point a, Point b) {
	if (a.x == b.x) { return INT_MAX; }
	int deltaX = a.x - b.x;
	int deltaY = a.y - b.y;
	return (deltaY + 0.0) / (deltaX + 0.0);
}

void removeDuplicates(vector<Point> &points) {
	for (unsigned int i = 0; i < points.size(); i++) {
		for (unsigned int j = i + 1; j < points.size(); j++) {
			if (points[i] == points[j]) {
				points[i].count++;
				points.erase(points.begin() + j);
				j--;
			}
		}
	}
}

int max(map<double, int> &slope_count) {
	map<double, int>::iterator it = slope_count.begin();
	int max_res = it->second;
	for (; it != slope_count.end(); it++) {
		if (it->second > max_res) {
			max_res = it->second;
		}
	}
	return max_res;
}

int liningUp(vector<Point> &points) {
	removeDuplicates(points);

	double **slopes = new double* [points.size()];
	for (unsigned int i = 0; i < points.size(); i++) {
		slopes[i] = new double[points.size()];
	}

	for (unsigned int i = 0; i < points.size(); i++) {
		slopes[i][i] = INT_MAX;
		for (unsigned int j = 0; j < i; j++) {
			double s = slope(points[i], points[j]);
			slopes[i][j] = s;
			slopes[j][i] = s;
		}
	}

	vector<int> max_slopes;
	for (unsigned int i = 0; i < points.size(); i++) {
		map<double, int> slope_count;
		for (unsigned int j = 0; j < points.size(); j++) {
			if (i != j) {
				slope_count[slopes[i][j]] += points[j].count;
			}
		}
		int max_count = max(slope_count);
		max_slopes.push_back(max_count);
	}

	for (unsigned int i = 0; i < max_slopes.size(); i++) {
		max_slopes[i] += points[i].count;
	}

	int res = 0;
	for (unsigned int i = 0; i < max_slopes.size(); i++) {
		if (max_slopes[i] > res) {
			res = max_slopes[i];
		}
	}
	return res;
}

int main() {
	int n; cin >> n;
	string s;
	getline(cin, s);
	getline(cin, s);

	for (int i = 0; i < n; i++) {
		vector<Point> points;
		while (getline(cin, s) && !s.empty()) {
			string int1 = "";
			string int2 = "";
			unsigned int i = 0;
			while (s[i] != ' ') {
				int1.push_back(s[i]);
				i++;
			}
			i++;
			while (i < s.size()) {
				int2.push_back(s[i]);
				i++;
			}
			int x = stoi(int1);
			int y = stoi(int2);
			Point p(x, y);
			points.push_back(p);

		}
		cout << liningUp(points) << endl;
		if (i + 1 != n) { cout << endl; }
	}

	cout << endl; cin.ignore(2); return 0;
}