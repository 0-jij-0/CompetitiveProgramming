#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t;
	while (t--) {
		ll d, m; cin >> d >> m;
		int i = 0; ll res = 1;
		while ((1ll << i) <= d) {
			ll c = (min((1ll << (i + 1)) - 1, d) - (1ll << i) + 2);
			res *= c; res %= m; i++;
		}
		cout << (res - 1 + m) % m << endl;
	}
	cin.ignore(2); return 0;
}