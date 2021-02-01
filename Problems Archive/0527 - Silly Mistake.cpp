#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> v, res;
set<int> day, used;

bool fill_res() {
	int n = (int)v.size(); int prev = -1;
	for (int i = 0; i < n; i++) {
		if (v[i] < 0 && !day.count(-v[i])) { return false; }
		if (v[i] < 0) { 
			!day.erase(-v[i]);
			if (day.empty()) { 
				res.push_back(i - prev); 
				used.clear(); prev = i;
			}
		}
		else {
			if (used.count(v[i])) { return false; }
			used.insert(v[i]); day.insert(v[i]);
		}
	}
	return day.empty();
}

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }

	bool b = fill_res();
	if (!b) { cout << -1 << endl; }
	else {
		cout << res.size() << endl;
		for (auto &x : res) { cout << x << ' '; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}