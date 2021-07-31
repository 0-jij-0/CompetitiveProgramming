#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int W, H; cin >> W >> H;
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int w, h; cin >> w >> h;

		int res = 1 << 30;
		if (x2 - x1 + w <= W) {
			res = min(res, max(0, w - x1));
			res = min(res, max(0, x2 - (W - w)));
		}
		if (y2 - y1 + h <= H) {
			res = min(res, max(0, h - y1));
			res = min(res, max(0, y2 - (H - h)));
		}

		cout << (res == 1 << 30 ? -1 : res) << '\n';
	}
	cin.ignore(2); return 0;
}