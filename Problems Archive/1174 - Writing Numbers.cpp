#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;

bool check(ll x, const ll &n) {
	ll res = 0, mult = 1, divi = 10, y = x;
	while (y) {
		res += (x / divi) * mult;
		ll m = (x % divi) / mult;
		if (m > 1) { res += mult; }
		else if (m) { res += 1 + x % mult; }
		mult *= 10; divi *= 10; y /= 10;
	}
	return res <= n;
}

ll findLast(const ll &n) {
	ll l = 0, r = 1ull << 63;
	while (l != r) {
		ll mid = (l + r + 1) >> 1;
		bool b = check(mid, n);
		b ? l = mid : r = mid - 1;
	}
	return l;
}

int main() {
	ll n; cin >> n;
	cout << findLast(n) << endl;
	cin.ignore(2); return 0;
}