#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

int s1, s2;

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll count(ll k, int x, int y) {
	if (x < 0) { return 0; }
	ll res = 0;
	for (int i = 39; i >= 0; i--) {
		if (i == x && !(k & (1ll << x))) { break; }
		if (i == x) { continue; }
		if (!(k & (1ll << i))) { continue; }

		int cnt = i - 2 + (i <= y) + (y < 0) + (x > i);
		res = (res + max(1ll, (1ll << cnt))) % mod;
		if (i == y && (k & (1ll << y))) { break; }
	}
	bool c = (k & (1ll << x)) && ((k & (1ll << y)) == 0);
	return res + c;
}

ll solve(ll k) {
	ll res = 0;
	for (int i = 0; i < 60; i++) {
		int x = i - s1, y = i - s2;
		ll OZ = ((1ll << x) <= k) ? count(k, x, y) : 0;
		ll ZO = ((1ll << y) <= k) ? count(k, y, x) : 0;
		ll w = (1ll << i) % mod;
		ll cur = (((OZ + ZO) % mod) * w) % mod;
		res = (res + cur) % mod;
	}
	return res;
}

int main() {
	freopen("geometry.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int x, y; ll l, r; cin >> x >> y >> l >> r;
		if (x == y) { cout << 0 << '\n'; continue; }
		s1 = 0; while (x != 1) { s1++; x >>= 1; }
		s2 = 0; while (y != 1) { s2++; y >>= 1; }
		ll R = solve(r), L = solve(l - 1);
		cout << (R - L + mod) % mod << '\n';
	}
	cin.ignore(2); return 0;
}