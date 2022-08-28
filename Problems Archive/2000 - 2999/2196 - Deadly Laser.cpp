#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m, sx, sy, d; cin >> n >> m >> sx >> sy >> d; --sx; --sy;
		int w = sx - d <= 0, x = sx + d >= n - 1, y = sy - d <= 0, z = sy + d >= m - 1;
		if (w + x + y + z < 2) { cout << n + m - 2 << '\n'; continue; }
		if (w + x + y + z > 2) { cout << -1 << '\n'; continue; }
		cout << ((w && z) || (x && y) ? n + m - 2 : -1) << '\n';
	}
}