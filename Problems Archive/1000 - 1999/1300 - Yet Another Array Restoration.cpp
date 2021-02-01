#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, x, y; cin >> n >> x >> y;
		int d = y - x; int r = 1;
		for (; r <= d; r++) {
			if (d % r) { continue; }
			if (d / r >= n) { continue; }
			break;
		}
		for (int i = x; i <= y; i += r, n--) cout << i << ' ';
		for (int i = x - r; i > 0 && n; i -= r, n--) { cout << i << ' '; }
		for (int i = y + r; n; i += r, n--) { cout << i << ' '; }
		cout << '\n';
	}
	cin.ignore(2); return 0;
}