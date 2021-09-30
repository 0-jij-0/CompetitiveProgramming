#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<pair<pair<int, int>, int>> res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); res.clear();
		for (auto& x : v) { cin >> x; }
		for (int i = 0; i < n; i++) {
			auto it = min_element(v.begin() + i, v.end());
			if (it == v.begin() + i) { continue; }
			int L = i, R = it - v.begin(), d = R - L;
			res.push_back({ { L + 1, R + 1 }, d });
			rotate(v.begin() + i, it, it + 1);
		}

		cout << res.size() << '\n';
		for (auto& x : res) cout << x.first.first << ' ' <<
			x.first.second << ' ' << x.second << '\n';
	}
	cin.ignore(2); return 0;
}