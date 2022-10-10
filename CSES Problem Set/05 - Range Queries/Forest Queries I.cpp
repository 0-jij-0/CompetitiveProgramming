#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

int main() {
	int n, q; cin >> n >> q; v.resize(n, vector<int>(n));
	for (auto &x : v) for (auto &y : x) { char c; cin >> c; y = (c == '*'); }
	for (int j = 1; j < n; j++) { v[0][j] += v[0][j - 1]; }
	for (int i = 1; i < n; i++) { v[i][0] += v[i - 1][0]; }
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
	while (q--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int res = v[--x2][--y2]; x1--; y1--;
		if (x1) { res -= v[x1 - 1][y2]; }
		if (y1) { res -= v[x2][y1 - 1]; }
		if (x1 && y1) { res += v[x1 - 1][y1 - 1]; }
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}