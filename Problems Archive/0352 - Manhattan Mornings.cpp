#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef pair<int, int> pt;
vector<pt> p;

int LIS(vector<pt> &v) {
	vector<int> res(v.size() + 1, INT_MAX);
	res[0] = INT_MIN;
	for (int i = 0; i < (int)v.size(); i++) {
		int idx = upper_bound(res.begin(), res.end(), v[i].second) - res.begin();
		res[idx] = v[i].second;
	}
	for (int i = 0; i < (int)res.size(); i++) {
		if (res[i] == INT_MAX) { return i - 1; }
	}
	return (int)v.size();
}

int main() {
	int n; cin >> n; pt h, w; 
	cin >> h.first >> h.second >> w.first >> w.second;
	pt x_range = { min(h.first, w.first), max(h.first, w.first) };
	pt y_range = { min(h.second, w.second), max(h.second, w.second) };
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		if (x < x_range.first || x > x_range.second) { continue; }
		if (y < y_range.first || y > y_range.second) { continue; }
		p.push_back({ x, y });
	}
	for (auto &x : p) {
		x.first -= h.first; x.second -= h.second;
		x.first = abs(x.first); x.second = abs(x.second);
	}
	sort(p.begin(), p.end());
	cout << LIS(p) << endl;
	cin.ignore(2); return 0;
}