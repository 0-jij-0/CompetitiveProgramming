#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;

int dp[2097152];
vector<vector<int>> v;

int bitCount(int x) {
	int res = 0;
	while (x) { x = x & (x - 1); res++; }
	return res;
}

int main() {
	int n; cin >> n; v.resize(n, vector<int>(n));
	for (auto &x : v) for (auto &y : x) cin >> y;
	fill(dp, dp + (1 << 21), 0); dp[0] = 1;
	for (int mask = 1; mask < (1 << n); mask++) {
		int boy = bitCount(mask) - 1;
		for (int i = 0; i < n; i++)
			if ((mask & (1 << i)) && v[boy][i])
				dp[mask] = (dp[mask] + dp[mask ^ (1 << i)]) % mod;
	}
	cout << dp[(1 << n) - 1] << '\n';
	cin.ignore(2); return 0;
}