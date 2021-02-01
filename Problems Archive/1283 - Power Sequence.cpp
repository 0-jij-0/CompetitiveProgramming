#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
typedef long long ll;
const ll INF = (ll)1e14;

vector<ll> v;

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x *= x)
		if (n & 1) res *= x;
	return res;
}

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end());
	ll res = accumulate(v.begin(), v.end(), 0ll);

	int lim = (int)pow(INF, 1.0 / n) + 5;

	int c = 1; while (c <= lim) {
		ll ans = 0; for (int i = 0; i < n; i++) {
			ans += abs(power(c, i) - v[i]);
			if (ans > INF) { break; }
		}
		if (ans > INF) { break; }
		res = min(res, ans); c++;
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}