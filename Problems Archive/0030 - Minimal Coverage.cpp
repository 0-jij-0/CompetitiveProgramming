#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Segment {
	int a, b;
	Segment() {}
	Segment(int ax, int ay) :
		a(ax), b(ay) {}

	bool operator < (const Segment &rhs) const {
		return a < rhs.a;
	}
};



int min_coverage(map<int, int> &segments, vector<Segment> &results, int M) {

	map<int, int>::iterator it = segments.begin();
	int left = 0, &right = M;
	int max_range = 0; map<int, int>::iterator max_idx = segments.begin();
	for (; it != segments.end(); it++) {
		if (it->second <= left) { continue; }

		while (it != segments.end() && it->first <= left) {
			int range = it->second - left;
			if (range > max_range) {
				max_range = range;
				max_idx = it;
			}
			it++;
		}

		if (max_range == 0) { return 0; }

		left += max_range;
		if (left >= right) {
			Segment max(max_idx->first, max_idx->second);
			results.push_back(max);
			break;
		}

		if (it == segments.end()) { return 0; }

		Segment max(max_idx->first, max_idx->second);
		results.push_back(max);

		max_range = 0; it--; continue;
	}

	return results.size();
}

void input(map<int, int> &segments, int &M) {
	int x, y;
	cin >> x >> y;
	while (x != 0 || y != 0) {
		if (x < M && y > 0) {
			if (segments.find(x) == segments.end()) {
				segments[x] = y;
			}
			else {
				segments[x] = (segments[x] < y) ? y : segments[x];
			}
		}
		cin >> x >> y;
	}
}

int main() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int M; cin >> M;
		map<int, int> segments;
		input(segments, M);
		vector<Segment> results;
		int res = min_coverage(segments, results, M);
		cout << res << endl;
		for (int j = 0; j < res; j++) {
			cout << results[j].a << " " << results[j].b << endl;
		}
		if (i + 1 != n) { cout << endl; }
	}
	cout << endl; cin.ignore(2); return 0;
}