#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll n; cin >> n;
	ll l = 1, r = 9, c = 9, d = 0, res = 0;
	while (r <= n) {
		res += (d / 3) * c;
		l *= 10; c *= 10; r = r * 10 + 9; d++;
	}
	if (l <= n) { res += (d / 3) * (n - l + 1); }
	cout << res << '\n';
	cin.ignore(2); return 0;
}