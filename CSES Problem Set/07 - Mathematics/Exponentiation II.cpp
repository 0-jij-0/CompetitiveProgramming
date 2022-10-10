#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll power(ll x, ll n, ll m = mod) {
	ll res = 1, a = x;
	for (; n; n >>= 1, a = (a * a) % m)
		if (n & 1) { res = (res * a) % m; }
	return res;
}

int main() {
	int n; cin >> n; while (n--) {
		int a, b, c; cin >> a >> b >> c;
		cout << power(a, power(b, c, mod - 1)) << endl;
	}
}