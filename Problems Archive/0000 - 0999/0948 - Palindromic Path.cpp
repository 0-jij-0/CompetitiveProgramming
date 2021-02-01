#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m; 
		vector<vector<int>> v(n, vector<int>(m));
		for (auto &x : v) for (auto &y : x) cin >> y;
		int res = 0;
		if (n <= m) {
			for (int k = 0; k < (n + m - 1) / 2; k++) {
				int i = 0, j = k, a = n - 1, b = m - 1 - k;
				int z = 0, o = 0;
				while (i < n && j >= 0) {
					(v[i++][j--] ? o : z)++;
					(v[a--][b++] ? o : z)++;
				}
				res += min(z, o);
			}
		}
		else {
			for (int k = 0; k < (n + m - 1) / 2; k++) {
				int i = k, j = 0, a = n - 1 - k, b = m - 1;
				int z = 0, o = 0;
				while (i >= 0 && j < m) {
					(v[i--][j++] ? o : z)++;
					(v[a++][b--] ? o : z)++;
				}
				res += min(z, o);
			}
		}
		cout << res << endl;
	}

	cin.ignore(2); return 0;
}