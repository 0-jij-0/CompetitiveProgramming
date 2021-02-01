#include <iostream>
using namespace std;
typedef long long ll;

ll power(ll x, ll n) {
	if (n == 0) { return 1; }
	ll ans = power(x, n >> 1);
	if (n & 1) { return ans * ans * x; }
	return ans * ans;
}

int main() {
	ll m; cin >> m; int dim = 3; bool found = false;
	if (m == 1) { cout << 3 << ' ' << 1 << endl; return 0; }
	while ((1ll << (dim - 1)) < m) {
		ll x = 1, pref = 0;
		while (pref < m) { 
			pref += power(x, dim - 1);
			if (pref == m) { found = true; break; }
			x++;
		}
		if (found) { cout << dim << ' ' << x << endl; break; }
		dim++;
	}
	if (!found) { cout << "impossible" << endl; }
	cin.ignore(2); return 0;
}