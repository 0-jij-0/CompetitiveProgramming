#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll power(ll x, ll n) {
	ll res = 1, a = x;
	for(; n; n >>= 1, a = (a * a) % mod)
		if (n & 1) { res = (res * a) % mod; }
	return res;
}

int main() {
	int n; cin >> n; while (n--) {
		int a, b; cin >> a >> b;
		cout << power(a, b) << endl;
	}
	cin.ignore(2); return 0;
}