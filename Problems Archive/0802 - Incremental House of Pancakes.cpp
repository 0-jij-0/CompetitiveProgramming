#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll findNum(ll x) {
	ll l = 0, r = 1ll << 31;
	while (l != r) {
		ll mid = (l + r) >> 1;
		bool b = ((mid*(mid + 1)) / 2) >= x;
		b ? r = mid : l = mid + 1;
	}
	return l;
}

ll findNextNum(ll t, ll x, int p) {
	ll l = 0, r = 1ll << 31;
	while (l != r) {
		ll mid = (l + r + 1) >> 1;
		ll y = p ? mid * (x + mid) : mid * (x + mid + 1);
		y <= t ? l = mid : r = mid - 1;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		ll l, r; cin >> l >> r;
		ll x = findNum(abs(l - r));
		((l < r) ? r : l) -= (x*(x + 1)) / 2;
		if (l < 0) { l += x; x--; }
		if (r < 0) { r += x; x--; }
		ll res = x;
		if (l < r) {
			ll numL = findNextNum(l, x, 0);
			ll numR = findNextNum(r, x, 1);
			ll num = min(numL, numR);
			l -= num * (x + num + 1);
			r -= num * (x + num);
			res += 2 * num;
			if (l >= r && l >= res + 1) { l -= res + 1; res++; }
			else if (r > l && r >= res + 1) { r -= res + 1; res++; }
			cout << "Case #" << t << ": " << res << ' ' << l << ' ' << r << '\n';
		}
		else {
			ll numL = findNextNum(l, x, 1);
			ll numR = findNextNum(r, x, 0);
			ll num = min(numL, numR);
			l -= num * (x + num);
			r -= num * (x + num + 1);
			res += 2 * num;
			if (l >= r && l >= res + 1) { l -= res + 1; res++; }
			else if (r > l && r >= res + 1) { r -= res + 1; res++; }
			cout << "Case #" << t << ": " << res << ' ' << l << ' ' << r << '\n';
		}
	}
	cin.ignore(2); return 0;
}