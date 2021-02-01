#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<pair<int, int>> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v)
			cin >> x.first >> x.second;
		sort(v.begin(), v.end());
		bool b = true;
		for (int i = 1; i < n && b; i++)
			if (v[i].second < v[i - 1].second)
				b = false;
		if (!b) { cout << "NO" << endl; continue; }
		cout << "YES" << endl;
		string res = ""; int x = 0, y = 0;
		for (int i = 0; i < n; i++) {
			int dx = v[i].first - x, dy = v[i].second - y;
			string r(dx, 'R'), u(dy, 'U');
			res += r + u; x = v[i].first; y = v[i].second;
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}