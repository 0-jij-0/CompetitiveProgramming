#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m; bool ok = true;
		v.clear(); v.resize(n, vector<int>(m));
		for (auto &x : v) for (auto &y : x) cin >> y;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if (v[i][j] > 4 - (i == 0 || i == n - 1) - (j == 0 || j == m - 1)) {
					ok = false; break;
				}
				else { v[i][j] = 4 - (i == 0 || i == n - 1) - (j == 0 || j == m - 1); }
		if (!ok) { cout << "NO" << '\n'; continue; }
		cout << "YES" << '\n';
		for (auto &x : v) { for (auto &y : x)cout << y << ' '; cout << '\n'; }
	}
	cin.ignore(2); return 0;
}