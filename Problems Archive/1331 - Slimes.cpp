#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

ll dp[400][400]; vector<ll> v;

inline ll query(int i, int j) { return i ? v[j] - v[i - 1] : v[j]; }

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	partial_sum(v.begin(), v.end(), v.begin());
	fill(dp[0], dp[0] + 400 * 400, 1ll << 60);
	for (int i = 0; i < n; i++) dp[i][i] = 0;
	for (int l = 1; l < n; l++)	
		for (int i = 0; i < n - l; i++) {
			dp[i][i + l] = query(i, i + l); ll res = 1ll << 60;
			for (int j = i; j < i + l; j++)
				res = min(res, dp[i][j] + dp[j + 1][i + l]);
			dp[i][i + l] += res;
		}

	cout << dp[0][n - 1] << '\n';
	cin.ignore(2); return 0;
}