#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; }

	ll res = 1 << 30; 
	for (int i = 0; i < (1 << (n - 1)); i++) {
		ll x = 0; ll cur = 0;
		for (int j = 0; j < n; j++) {
			cur |= v[j]; if (i & (1 << j)) { x ^= cur; cur = 0; }
		}
		res = min(x ^ cur, res);
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}