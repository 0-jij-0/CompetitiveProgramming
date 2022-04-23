#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

ll keepZero(int k) {
	ll res = 0, last = 0; int n = (int)v.size();
	for (int i = k - 1; i >= 0; i--) {
		ll cur = (last / v[i]) + 1;
		last = cur * v[i]; res += cur;
	}
	last = 0; for (int i = k + 1; i < n; i++) {
		ll cur = (last / v[i]) + 1;
		last = cur * v[i]; res += cur;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) cin >> x;

	ll res = 1ll << 60;
	for (int i = 0; i < n; i++)
		res = min(res, keepZero(i));

	cout << res << '\n';
	cin.ignore(2); return 0;
}