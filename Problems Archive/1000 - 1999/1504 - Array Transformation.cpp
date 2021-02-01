#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
using namespace std;
typedef long long ll;

ll dp[2001][2001];
vector<int> a, b, c;

int main() {
	freopen("transform.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		a.resize(n); b.resize(m); c.resize(n);
		for (auto& x : a) { cin >> x; }
		for (auto& x : b) { cin >> x; }
		for (auto& x : c) { cin >> x; }

		unordered_set<int> before;
		unordered_map<int, int> after;
		for (auto& x : b) { after[x]++; }

		fill(dp[0], dp[0] + 2001 * 2001, 1ll << 60);
		dp[0][0] = 0; for (int i = 0; i <= m; i++) {
			for (int j = i; j < n; j++) if (dp[i][j] != 1ll << 60) {
				if (i != m && a[j] == b[i]) { dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]); }
				if (!before.count(a[j])) { 
					dp[i][j + 1] = min(dp[i][j + 1], c[j] + dp[i][j]);
				}
				else if (!after.count(a[j]) || after[a[j]] == 0) { 
					dp[i][j + 1] = min(dp[i][j + 1], c[j] + dp[i][j]);
				}
			}
			if (i != m) { before.insert(b[i]); after[b[i]]--; }
		}
		ll res = dp[m][n];
		if (res == 1ll << 60) { cout << "No" << '\n'; continue; }
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}