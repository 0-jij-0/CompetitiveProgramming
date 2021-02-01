#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

map<string, int> coins = { {"Zulian", 0}, {"Razzashi", 1}, {"Hakkari", 2}, {"Sandfury", 3}, {"Skullsplitter", 4}, {"Bloodscalp", 5},
						{"Gurubashi", 6}, {"Vilebranch", 7}, {"Witherbark", 8} };

vector<pair<int, ll>> v[9];
ll dp[9][1002];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s; int k, p; cin >> s >> k >> p;
		v[coins[s]].push_back({ k, p });
	}

	fill(dp[0], dp[0] + 9 * 1002, 1ll << 60);
	for (int c = 0; c < 9; c++) {
		dp[c][0] = 0; for (int i = 0; i < (int) v[c].size(); i++)
			for (int j = n; j > 0; j--) {
				dp[c][j] = min(dp[c][j], dp[c][j + 1]);
				dp[c][j] = min(dp[c][j], dp[c][max(0, j - v[c][i].first)] + v[c][i].second);
			}
	}

	ll res = 1ll << 60;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; i + j <= n; j++) {
			int k = n - i - j;
			if (max({ dp[0][i], dp[1][i], dp[2][i] }) == 1ll << 60) { continue; }
			if (max({ dp[3][j], dp[4][j], dp[5][j] }) == 1ll << 60) { continue; }
			if (max({ dp[6][k], dp[7][k], dp[8][k] }) == 1ll << 60) { continue; }
			ll s = 0; int a[3] = { i, j, k };
			for (int c = 0; c < 9; c++) s += dp[c][a[c / 3]];
			res = min(res, s);
		}
	}
	if (res == 1ll << 60) { cout << "impossible" << '\n'; }
	else { cout << res << '\n'; }
	cin.ignore(2); return 0;
}