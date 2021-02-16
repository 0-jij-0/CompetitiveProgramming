#include <iostream>
using namespace std;
typedef long long ll;

bool check(ll n) {
	if (n == 0) { return false; }
	ll l = 0, r = 10000;
	while (l != r) {
		ll mid = (l + r + 1) >> 1;
		bool b = mid * mid * mid <= n;
		b ? l = mid : r = mid - 1;
	}
	return (l * l * l) == n;
}

int main() {
	int t; cin >> t; while (t--) {
		ll n; cin >> n; bool ok = false;
		for (ll i = 1; i * i * i <= n; i++) {
			if (check(n - i * i * i)) { ok = true; break; }
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}