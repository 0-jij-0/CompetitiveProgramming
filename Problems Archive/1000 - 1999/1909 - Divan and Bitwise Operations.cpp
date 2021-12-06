#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; ll orSum = 0;
		for (int i = 0; i < m; i++) {
			int l, r; ll x; cin >> l >> r >> x;
			orSum |= x;
		}
		cout << (orSum * power(2, n - 1)) % mod << '\n';
	}

	cin.ignore(2); return 0;
}