#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll dp[3001][3002];
vector<int> a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; a.resize(n); b.resize(n);
	for (auto& x : a) { cin >> x; }
	for (auto& x : b) { cin >> x; }

	dp[0][0] = 1; for (int i = 0; i < n; i++) {
		for (int j = 0; j <= b[i]; j++) if (dp[i][j]) {
			int L = max(j, a[i]), R = b[i];
			dp[i + 1][L] = (dp[i + 1][L] + dp[i][j]) % mod;
			dp[i + 1][R + 1] = (dp[i + 1][R + 1] - dp[i][j] + mod) % mod;
		}
		for (int j = 1; j <= 3001; j++) { dp[i + 1][j] = (dp[i + 1][j] + dp[i + 1][j - 1]) % mod; }
	}

	ll res = 0;
	for (int i = a[n - 1]; i <= b[n - 1]; i++)
		res = (res + dp[n][i]) % mod;

	cout << res << '\n';
	cin.ignore(2); return 0;
}