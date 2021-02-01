#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll s; cin >> s; s <<= 1; int res = 0;
	for (ll i = 1; i * i <= s; i++) {
		if (s % i) { continue; }
		res += ((s / i) - (i - 1)) % 2 == 0;
		if (s / i <= i) { continue; }
		res += ((s / (s / i)) - ((s / i) - 1)) % 2 == 0;
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}