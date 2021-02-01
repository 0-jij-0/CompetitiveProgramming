#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[2][5001];
string a, b; int n, m;

int main() {
	cin >> a >> b; n = (int)a.size(); m = (int)b.size();
	for (int i = 0; i < 5001; i++) dp[0][i] = i;
	for (int i = 1; i <= n; i++) {
		dp[i & 1][0] = i; for (int j = 1; j <= m; j++) {
			int I = i & 1, pI = (i & 1) ^ 1; dp[I][j] = 1 << 30;
			if (a[i - 1] == b[j - 1]) { dp[I][j] = min(dp[I][j], dp[pI][j - 1]); }
			dp[I][j] = min({ dp[I][j], 1 + dp[pI][j - 1], 1 + dp[I][j - 1], 1 + dp[pI][j] });
		}
	}
	cout << dp[n & 1][m] << endl;
	cin.ignore(2); return 0;
}