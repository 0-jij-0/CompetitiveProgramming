#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int query(ll k) {
	ll l = 1, r = 9, d = 1;
	while (k > (r - l + 1) * d) {
		k -= (r - l + 1) * d;
		l *= 10; r = 10 * r + 9; d++;
	}
	l += k / d; k %= d;
	return to_string(l)[k] - '0';
}

int main() {
	int q; cin >> q; while (q--) {
		ll k; cin >> k; cout << query(--k) << '\n';
	}
	cin.ignore(2); return 0;
}