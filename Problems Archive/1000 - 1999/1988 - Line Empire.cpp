#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> v, pref;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, a, b; cin >> n >> a >> b;
		v.resize(n, 0); pref.resize(n);
		for (auto& x : v) cin >> x;
		partial_sum(v.begin(), v.end(), pref.begin());

		ll res = b * pref.back();
		for (int i = 0; i < n; i++) {
			ll moveCost = (a + b) * v[i], remKingdoms = (n - i - 1);
			ll conquerCost = b * (pref.back() - pref[i] - v[i] * remKingdoms);
			res = min(res, moveCost + conquerCost);
		}

		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}