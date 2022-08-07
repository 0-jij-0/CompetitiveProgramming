#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int xL = 0, xR = 0, yL = 0, yR = 0;
		int n; cin >> n; while (n--) {
			int x, y; cin >> x >> y;
			xL = min(xL, x); xR = max(xR, x);
			yL = min(yL, y); yR = max(yR, y);
		}

		cout << 2 * (yR - yL + xR - xL) << '\n';
	}
}