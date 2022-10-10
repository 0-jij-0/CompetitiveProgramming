#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;

int dp[100001][101];
vector<int> v; int n, m;

int count(int i, int x) {
	if (x < 1 || x > m) { return 0; }
	if (i == n) { return 1; }
	if (v[i] != 0) { return abs(v[i] - x) < 2 ? count(i + 1, v[i]) : 0; }
	if (dp[i][x] != -1) { return dp[i][x]; }

	int res = count(i + 1, x - 1);
	res = (res + count(i + 1, x)) % mod;
	res = (res + count(i + 1, x + 1)) % mod;
	return dp[i][x] = res;
}

int main() {
	cin >> n >> m; v.resize(n);
	for (auto &x : v) { cin >> x; }
	fill(dp[0], dp[0] + 100001 * 101, -1);
	int res = 0; if (v[0] != 0) { res = count(1, v[0]); }
	else for (int i = 1; i <= m; i++) { res = (res + count(1, i)) % mod; }
	cout << res << '\n';
}