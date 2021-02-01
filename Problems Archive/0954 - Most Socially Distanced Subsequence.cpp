#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }

		vector<int> res; res.push_back(v.front());
		int i = 0, j = 1; bool b = (v[0] < v[1]);
		while (j < n) {
			if (b && v[j] >= v[j - 1]) { j++; continue; }
			if (!b && v[j] <= v[j - 1]) { j++; continue; }
			res.push_back(v[j - 1]); i = j++; b = !b;
		}
		res.push_back(v.back());
		cout << res.size() << '\n';
		for (auto &x : res) { cout << x << ' '; }
		cout << '\n';
	}
	cin.ignore(2); return 0;
}