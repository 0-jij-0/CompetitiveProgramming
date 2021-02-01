#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

ll query(ll a, ll b, ll l, ll r) {
	if (a == b) { return r - l + 1; }
	if (r < b) { return r - l + 1; }
	ll lcmab = lcm(a, b), res = 0;
	if (l < b) { res += b - l; l = b; }
	if (r < lcmab) { return res; }

	ll x = (l / lcmab)*lcmab;
	res += max(0ll, min(b - (l - x), r - l + 1));
	ll y = (r / lcmab)*lcmab;
	if (y != x) { res += min(b, r - y + 1); }

	x += lcmab; y -= lcmab;
	if (x > y) { return res; }
	res += (((y - x) / lcmab) + 1)*b;
	return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		ll a, b; int q; cin >> a >> b >> q;
		if (a > b) { swap(a, b); }
		while (q--) {
			ll l, r; cin >> l >> r;
			cout << r - l + 1 - query(a, b, l, r) << ' ';
		}
		cout << endl;
	}
	cin.ignore(2); return 0;
}