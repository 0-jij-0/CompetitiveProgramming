#include <iostream>
using namespace std;
typedef long long ll;

ll h, c, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) {
		cin >> h >> c >> t;
		if (t == h) { cout << 1 << endl; continue; }
		if (2 * t <= h + c) { cout << 2 << endl; continue; }
		ll b = 2*t - (h + c), a = h - t;
		ll x = a / b, y = (a + b - 1) / b;
		ll dif1 = (2 * y + 1)*(c * x + h * (x + 1) - t * (2 * x + 1));
		ll dif2 = (2 * x + 1)*(-c * y - h * (y + 1) + t * (2 * y + 1));
		cout << (dif1 <= dif2 ? 2 * x + 1 : 2 * y + 1) << endl;
	}
	cin.ignore(2); return 0;
}