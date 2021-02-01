#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> a, b, c, dp(100001, 0);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; a.resize(n);
		b.resize(n); c.resize(n);
		fill(dp.begin(), dp.begin() + n, 0);
		for (auto& x : c) { cin >> x; }
		for (auto& x : a) { cin >> x; }
		for (auto& x : b) { cin >> x; }

		dp[0] = -(1ll << 40); for (int i = 1; i < n; i++) {
			if (a[i] == b[i]) { dp[i] = 2; continue; }
			ll x = min(a[i] - 1 + c[i - 1] - b[i], b[i] - 1 + c[i - 1] - a[i]);
			dp[i] = max(abs(a[i] - b[i]) + 2, dp[i - 1] + x + 2);
		}

		ll res = 0; for (int i = 1; i < n; i++)
			res = max(res, dp[i] + c[i] - 1);

		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}