#include <iostream>
using namespace std;
typedef long long ll;

bool parity(ll x) {
	bool res = 0;
	while (x) { res ^= 1; x &= (x - 1); }
	return res;
}

int main() {
	int t; cin >> t; while (t--) {
		ll n; cin >> n; n--;
		cout << (parity(n) ? "Blue" : "Red") << '\n';
	}
	cin.ignore(2); return 0;
}