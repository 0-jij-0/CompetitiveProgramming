#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) cin >> x.first;
		for (auto& x : v) cin >> x.second;
		sort(v.begin(), v.end());

		pair<int, int> cur(1, 1); ll res = 0;
		for (int i = 0; i < n; i++) {
			int dx = v[i].first - cur.first;
			int dy = v[i].second - cur.second;
			if (dx == 0 && dy == 0) { continue; }

			bool b = (cur.first + cur.second) & 1;
			if (b) { dx -= dy; res += (dx + 1) >> 1; }
			else if (dx == dy){	res += dx; }
			else { dx -= dy + 1; res += (dx + 1) >> 1; }
			cur = v[i];
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}