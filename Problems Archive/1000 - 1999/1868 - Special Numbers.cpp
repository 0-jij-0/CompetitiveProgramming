#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll kthSpecial(ll n, ll k) {
	ll res = 0, cur = 1;
	while (k) {
		if (k & 1) { res = (res + cur) % mod;; }
		k >>= 1; cur = (cur * n) % mod;
	}
	return res;
}

int main() {
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k;
		cout << kthSpecial(n, k) << '\n';
	}
	cin.ignore(2); return 0;
}