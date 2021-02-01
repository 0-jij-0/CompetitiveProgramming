#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll c1, c2, c3, c4, c5, c6;

ll minCostPath(ll x, ll y) {
	if (x == 0 && y == 0) { return 0; }

	if (x == 0) {
		if (y > 0) { return (c2 < c1 + c3 ? c2 : c1 + c3) * y; }
		return (c5 < c4 + c6 ? c5 : c4 + c6) * (-y);
	}
	if (y == 0) {
		if (x > 0) { return (c6 < c1 + c5 ? c6 : c1 + c5) * x; }
		return (c3 < c2 + c4 ? c3 : c2 + c4) * (-x);
	}

	if (x == y) {
		if (x > 0) { return (c1 < c6 + c2 ? c1 : c6 + c2) * x; }
		return (c4 < c3 + c5 ? c4 : c3 + c5) * (-x);
	}
	if (x == -y) {
		if (x > 0) { return c6 * x + c5 * (-y); }
		return c3 * (-x) + c2 * y;
	}
}

int main() {
	int t; cin >> t; while (t--) {
		ll x, y; cin >> x >> y;
		cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;

		ll Xy = minCostPath(x, x) + minCostPath(0, y - x);
		ll xY = minCostPath(x, -x) + minCostPath(0, y + x);
		ll Yx = minCostPath(y, y) + minCostPath(x - y, 0);
		ll yX = minCostPath(-y, y) + minCostPath(x + y, 0);

		cout << min({ Xy, xY, Yx, yX }) << '\n';
	}
	cin.ignore(2); return 0;
}