#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
vector<int> s;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		s.clear(); v.clear(); s.resize(n, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++) {
				int a; cin >> a; v.push_back({ a, i });
			}
		sort(v.begin(), v.end());
		int res = 0;
		for (int i = 0; i < 3 * n; i++) {
			if (s[v[i].second] == 2) { continue; }
			if (k == 0) { break; }
			res += v[i].first; s[v[i].second]++; k--;
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}