#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll power(ll x, int n, ll m = mod) {
	if (!n) { return 1; }
	ll res = power(x, n >> 1, m);
	res = (res * res) % m;
	if (n & 1) { return (res * x) % m; }
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, p; cin >> n >> p; vector<int> v(n);
		for (auto &x : v) { cin >> x; }
		if (p == 1) { cout << n % 2 << '\n'; continue; }
		sort(v.begin(), v.end()); int thresh = 1; 
		int m = 1 << 20; while (m) { thresh++; m /= p; }

		ll res = 0, dif = 0; ll cur = v.back();
		for (int i = n - 1; i >= 0; i--) {
			if (dif == -1) { res = (res - power(p, v[i]) + mod) % mod; continue; }
			if (v[i] != cur) {
				ll d = cur - v[i]; cur = v[i];
				if (d >= thresh && dif) { dif = -1; i++; continue; }
				if (dif) { dif *= power(p, d, 1ll << 60); }
				if (dif > n) { dif = -1; i++; continue; }
			}
			if (dif != 0) { res = (res - power(p, v[i]) + mod) % mod; dif--; continue; }
			res = (res + power(p, v[i])) % mod; dif++;
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}