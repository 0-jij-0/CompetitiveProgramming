#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

unordered_map<string, ll> dp2;
vector<ll> dp1, pref;
vector<string> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		dp1.clear(); dp2.clear(); pref.clear();
		int n, k; cin >> n >> k; v.resize(n);
		for (auto& x : v) { cin >> x; }

		dp1.resize(n, 0); pref.resize(n, 0);
		for (int i = 0; i <= k; i++) {
			dp1[i] = (dp2[v[i]] == 0); dp2[v[i]] |= dp1[i];
			pref[i] = i ? pref[i - 1] + dp1[i] : dp1[i];
		}

		for (int i = k + 1; i < n; i++) {
			dp1[i] = (pref[i - k - 1] - (dp2[v[i]] - 1) + mod) % mod;
			pref[i] = (dp1[i] + pref[i - 1]) % mod;
			dp2[v[i]] = (dp2[v[i]] + dp1[i]) % mod;
		}

		ll res = 0; for (auto& x : dp1) res = (res + x) % mod;
		cout << res << '\n';
	}
	cin.ignore(2);
}