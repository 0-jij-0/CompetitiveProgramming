#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		ll l, r; cin >> l >> r;	ll l2 = 2 * l;
		if (l2 > r) { cout << 0 << '\n'; continue; }
		ll dif = r - l2;
		cout << (r - l2 + 1) * (dif + 1) - (dif * (dif + 1)) / 2 << '\n';
	}
	cin.ignore(2); return 0;
}