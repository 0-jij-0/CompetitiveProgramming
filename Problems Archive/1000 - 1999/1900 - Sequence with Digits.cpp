#include <iostream>
using namespace std;
typedef long long ll;

void minMaxDigit(ll x, int& mi, int& ma) {
	mi = ma = x % 10; while (x) {
		if (mi > x % 10) { mi = x % 10; }
		if (ma < x % 10) { ma = x % 10; }
		x /= 10;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		ll a, k; cin >> a >> k;
		for (ll i = 1; i < k; i++) {
			int mi, ma; minMaxDigit(a, mi, ma);
			if (mi * ma == 0) { break; }
			a = a + mi * ma;
		}
		cout << a << '\n';
	}
	cin.ignore(2); return 0;
}