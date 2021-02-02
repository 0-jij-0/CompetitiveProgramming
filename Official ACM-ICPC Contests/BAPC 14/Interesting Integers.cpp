#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> fib(50);

ll extGcd(int a, int b, ll& x, ll& y) {
	if (!b) { x = 1; y = 0;	return a; }
	ll x1, y1, d = extGcd(b, a % b, x1, y1);
	x = y1;	y = x1 - y1 * (a / b); return d;
}

pair<ll, ll> dioph(ll a, ll b, ll c) {
	ll x0, y0, g = extGcd(a, b, x0, y0);
	x0 *= c; y0 *= c;

	if (x0 < y0) {
		ll l = 0, r = 1 + (y0 - x0 + a - 1) / a;
		while (l != r) {
			ll mid = (l + r + 1) >> 1;
			ll x = x0 + mid * b, y = y0 - mid * a;
			x <= y ? l = mid : r = mid - 1;
		}
		x0 = x0 + l * b; y0 = y0 - l * a;
		if (x0 > 0) { return { x0, y0 }; }
		return { c, c };
	}
	ll l = 0, r = 1 + (x0 - y0 + a - 1) / a;
	while (l != r) {
		ll mid = (l + r) >> 1;
		ll x = x0 - mid * b, y = y0 + mid * a;
		x <= y ? r = mid : l = mid + 1;
	}
	x0 = x0 - l * b; y0 = y0 + l * a;
	if (x0 > 0) { return { x0, y0 }; }
	return { c, c };
}

int main() {
	int t; cin >> t; fib[1] = fib[2] = 1;
	for (int i = 3; i < 50; i++) fib[i] = fib[i - 1] + fib[i - 2];

	while (t--) {
		ll n; cin >> n;
		ll a = n >> 1, b = (n + 1) >> 1;
		for (int i = 3; i < 50; i++) {
			pair<ll, ll> p = dioph(fib[i - 2], fib[i - 1], n);
			if (p.second < b) { a = p.first; b = p.second; }
			else if (p.second == b) { a = min(a, p.first); }
		}
		cout << a << ' ' << b << '\n';
	}
	cin.ignore(2); return 0;
}