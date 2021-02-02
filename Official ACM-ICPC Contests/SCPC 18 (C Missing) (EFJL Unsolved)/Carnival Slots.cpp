#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
 
int row, col;
vector<ll> b, s;
vector<string> grid;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	freopen("balls.in", "r", stdin);
 
	int t; cin >> t;
	while (t--) {
		cin >> row >> col;
		b.clear(); b.resize(col);
		for (auto& x : b) { cin >> x; }
		grid = vector<string>(row);
		for (auto& x : grid) { cin >> x; }
		s.clear(); s.resize(col);
		for (auto& x : s) { cin >> x; }
 
		vector<vector<ll>> dp(row + 1, vector<ll>(col + 1, 0));
		for (int j = 0; j < col; j++) { dp[row][j] = s[j]; }
		for (int i = row - 1; i >= 0; i--) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == '.') { dp[i][j] = dp[i + 1][j]; }
				else { dp[i][j] = max({ dp[i + 1][j], dp[i + 1][j + 1], dp[i + 1][max(0, j - 1)] }); }
			}
		}
		ll ans = 0;
		for (int j = 0; j < col; j++) {
			ans += b[j] * dp[0][j];
		}
		cout << ans << '\n';
	}
}