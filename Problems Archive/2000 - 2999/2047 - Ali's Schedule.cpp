#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int convertToInt(string &t, string &ampm) {
	string h_t = t.substr(0, 2); int h = stoi(h_t);
	string m_t = t.substr(3, 2); int m = stoi(m_t);
	string s_t = t.substr(6, 2); int s = stoi(s_t);
	if (ampm == "AM" && h == 12) { h = 0; }
	if (ampm == "PM" && h != 12) { h += 12; }
	return h * 3600 + m * 60 + s;
}

int main() {
	freopen("schedule.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			int id; string time, ampm; 
			cin >> id >> time >> ampm;
			v[i] = { convertToInt(time, ampm), id };
		}
		sort(v.begin(), v.end());

		for (auto &x : v) cout << x.second << ' '; cout << '\n';
	}
}