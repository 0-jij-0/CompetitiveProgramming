#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 1 << 20;

int dp[1 << 20][2];
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fill(dp[0], dp[0] + (1 << 21), 0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; dp[x][0]++; dp[x][1]++; }

	for (int i = 1; i < M; i <<= 1) {
		for (int mask = M - 1; mask > 0; mask--)
			if (mask & i) dp[mask][0] += dp[mask - i][0];
		
		for (int mask = 1; mask < M; mask++)
			if (!(mask & i)) dp[mask][1] += dp[mask + i][1];
	}

	for (auto& x : v)
		cout << dp[x][0] << ' ' << dp[x][1] << ' '
		<< n - dp[(M - 1) ^ x][0] << '\n';
}