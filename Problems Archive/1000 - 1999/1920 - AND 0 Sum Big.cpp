#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

int main() {
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k;
		ll res = 1, x = n;
		for (; k; k >>= 1, x = (x * x) % mod)
			if (k & 1) res = (res * x) % mod;

		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}