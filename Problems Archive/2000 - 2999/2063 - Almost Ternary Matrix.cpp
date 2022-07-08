#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; res.clear();
		res.resize(n, vector<int>(m));

		for (int i = 0; i < n; i += 2) {
			bool b = (i >> 1) & 1;
			for (int j = 0; j < m; j += 2, b ^= 1) {
				res[i][j] = res[i + 1][j + 1] = b;
				res[i + 1][j] = res[i][j + 1] = !b;
			}
		}

		for (auto& x : res) { for (auto& y : x) cout << y << ' '; cout << '\n'; }
	}
}