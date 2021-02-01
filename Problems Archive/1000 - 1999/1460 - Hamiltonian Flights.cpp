#include <iostream>
#include <vector>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;

vector<vector<int>> v; int n;
int dp[21][1 << 20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int m; cin >> n >> m; v.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[--a].emplace_back(--b);
	}
	dp[0][1] = 1;

	for (int mask = 1; mask < (1 << (n - 1)); mask++)
		for (int cur = 0; cur < n - 1; cur++) if(mask & (1 << cur))
			for (auto &e : v[cur]) if(!(mask & 1 << e))
				dp[e][mask | (1 << e)] = (dp[e][mask | (1 << e)] + dp[cur][mask]) % mod;
	
	cout << dp[n - 1][(1 << n) - 1] << '\n';
	cin.ignore(2); return 0;
}