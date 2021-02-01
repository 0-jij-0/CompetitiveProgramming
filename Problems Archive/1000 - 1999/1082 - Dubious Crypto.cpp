#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		ll l, r, m; cin >> l >> r >> m;
		for (ll a = l; a <= r; a++) {
			ll x = m / a, y = x + 1;
			if (x && (m - x * a) <= r - l) {
				cout << a << ' ' << r << ' ' << r - (m - x * a) << '\n'; break;
			}
			else if ((y * a - m) <= r - l) {
				cout << a << ' ' << l << ' ' << l + (y * a - m) << '\n'; break;
			}
		}
	}
	cin.ignore(2); return 0;
}
