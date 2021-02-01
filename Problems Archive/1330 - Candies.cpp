#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<ll> dp[2];
vector<int> v;

int main() {
	int n, k; cin >> n >> k; v.resize(n);
	dp[0].resize(k + 1, 0); dp[1].resize(k + 1);
	dp[0][0] = 1; for (auto &x : v) { cin >> x; }

	for (int i = 1; i <= n; i++) {
		int prev = (i ^ 1) & 1;
		partial_sum(dp[prev].begin(), dp[prev].end(), dp[prev].begin());
		for (int j = 0; j <= k; j++) {
			if (v[i - 1] >= j) { dp[i & 1][j] = dp[prev][j] % mod; continue; }
			dp[i & 1][j] = (dp[prev][j] - dp[prev][j - v[i - 1] - 1]) % mod;
		}
	}
	cout << dp[n & 1][k] << '\n';
	cin.ignore(2); return 0;
}