#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k; v.resize(n);
		for (auto& x : v) { cin >> x; }

		ll N = n;
		ll res = N * (N - 1) - k * (v[n - 1] | v[n - 2]);
		for(ll i = n - 1; i > 0; i--)
			for (ll j = i - 1; j >= 0; j--) {
				if ((i + 1) * (j + 1) <= res) { break; }
				ll cur = (i + 1) * (j + 1) - k * (v[(int)i] | v[(int)j]);
				res = max(res, cur);
			}

		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}