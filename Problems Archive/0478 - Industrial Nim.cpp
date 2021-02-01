#include <iostream>
using namespace std;

typedef long long ll;

ll pref_xor(ll n) {
	if (n <= 0) { return 0; }
	int x = n % 4;
	if (x == 0) { return n; }
	if (x == 1) { return 1; }
	if (x == 2) { return n + 1; }
	return 0;
}

ll range_xor(ll a, ll b) {
	return pref_xor(b) ^ pref_xor(a - 1);
}

int main() {
	int n; cin >> n; ll res = 0;
	for (int i = 0; i < n; i++) {
		ll x, m; cin >> x >> m;
		res ^= range_xor(x, x + m - 1);
	}
	cout << (res ? "tolik" : "bolik") << endl;
	cin.ignore(2); return 0;
}