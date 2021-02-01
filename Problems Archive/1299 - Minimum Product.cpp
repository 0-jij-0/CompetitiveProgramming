#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll check(ll a, ll x, ll b, ll y, ll n) {
	if (a - x >= n) { return (a - n) * b; }
	n -= a - x; return x * (b - n);
}

int main() {
	int t; cin >> t; while (t--) {
		ll a, b, x, y, n; cin >> a >> b >> x >> y >> n;
		ll dax = a - x, dby = b - y;

		if (dax + dby <= n) { cout << x * y << '\n'; continue; }

		ll res1 = check(a, x, b, y, n);
		ll res2 = check(b, y, a, x, n);
		cout << min(res1, res2) << '\n';
	}
	cin.ignore(2); return 0;
}