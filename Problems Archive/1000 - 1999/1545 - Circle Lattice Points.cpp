#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double ld;

ll lattice(ll L, ll R) {
	L < 0 ? L = L / 10000 : L = (L + 9999) / 10000;
	R < 0 ? R = (R - 9999) / 10000 : R = R / 10000;
	return R - L + 1;
}

ll doubleToLL(string s) {
	int n = (int)s.size(); auto it = find(s.begin(), s.end(), '.');
	if (it == s.end()) { return 10000 * stoll(s); }

	int idx = it - s.begin(), d = n - idx - 1;
	s.erase(it); return stoll(s + string(4 - d, '0'));
}

int main() {
	string X, Y, R; cin >> X >> Y >> R;
	ll x = doubleToLL(X);
	ll y = doubleToLL(Y);
	ll r = doubleToLL(R);

	ll res = 0;
	for (ll i = x - r; i <= x + r; i += 10000) {
		if (abs(i) % 10000) { i -= 9999; continue; }

		ll dx = x - i, c = r * r - dx * dx;

		ll L1 = y - r, L2 = y; while (L1 != L2) {
			ll mid = (L1 + L2) >> 1, dy = y - mid;
			dy * dy <= c ? L2 = mid : L1 = mid + 1;
		}
		ll R1 = y, R2 = y + r; while (R1 != R2) {
			ll mid = (R1 + R2 + 1) >> 1, dy = mid - y;
			dy * dy <= c ? R1 = mid : R2 = mid - 1;
		}
		res += lattice(L1, R1);
	}

	cout << res << '\n';
	cin.ignore(2); return 0;
}