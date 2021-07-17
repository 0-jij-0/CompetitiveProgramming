#include <iostream>
using namespace std;
typedef long long ll;

bool isPrime(ll n) {
	if (n < 4) { return n > 1; }
	if (n % 6 != 1 && n % 6 != 5) { return false; }

	for (ll i = 3; i * i <= n; i++)
		if (n % i == 0) return false;

	return true;
}

int main() {
	freopen("dprime.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		ll d, l, r; cin >> d >> l >> r;
		if (!isPrime(d)) { cout << 0 << '\n'; continue; }
		cout << (d * d <= r && d * d >= l) << '\n';
	}

	cin.ignore(2); return 0;
}