#include <iostream>
#include <vector>
using namespace std;

int dp[10001];
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k; v.resize(k);
	for (auto& x : v) cin >> x;

	dp[0] = 0; for (int i = 1; i <= n; i++) {
		dp[i] = 0; for (int j = 0; j < k && v[j] <= i; j++)
			dp[i] = max(dp[i], v[j] - dp[i - v[j]]);
	}

	cout << (n + dp[n]) / 2 << '\n';
}