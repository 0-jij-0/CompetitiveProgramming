#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		ll s; cin >> s; s <<= 1; ll res = 0;
		for (ll i = 1; i * i <= s; i++) {
			if (s % i) { continue; }
			res += ((s / i) - (i - 1)) % 2 == 0;
			if (s / i <= i) { continue; }
			res += ((s / (s / i)) - ((s / i) - 1)) % 2 == 0;
		}
		cout << "Case #" << t << ": " << res / 2 << '\n';
	}
	cin.ignore(2); return 0;
}