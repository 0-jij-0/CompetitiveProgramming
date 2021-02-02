#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int f; cin >> f;
	bool OK = true;
	while (f--) {
		int t, n; cin >> t >> n;
		vector<pair<int, int>> intervals(n);
		for (int i = 0; i < n; i++) { cin >> intervals[i].first >> intervals[i].second; }
		
		vector<vector<bool>> dp(n + 1, vector<bool>(t + 1, 0));
		for (int j = 0; j <= t; j++) { dp[0][j] = true; }
 
		for (int i = 0; i < n; i++) {
			int len = intervals[i].second - intervals[i].first;
			for (int j = 0; j <= t; j++) {
				if (!dp[i][j]) { continue; }
				int nxtL = j - len, nxtR = j + len;
				if (nxtL >= 0) { dp[i + 1][nxtL] = 1; }
				if (nxtR <= t) { dp[i + 1][nxtR] = 1; }
			}
		}
 
		bool found = false;
		for (int j = 0; j <= t; j++) {
			if (dp[n][j]) { found = true; break; }
		}
		OK = OK & found;
	}
 
	cout << (OK ? "possible" : "impossible") << '\n';
}