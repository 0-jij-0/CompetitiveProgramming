#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll dp[100002][9];
string s, t = "chokudai";

int main() {
	cin >> s; int n = (int)s.size();
	fill(dp[0], dp[0] + 800008, 0);

	dp[0][0] = 1; for (int i = 1; i <= n; i++) {
		dp[i][0] = 1; for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
			if (s[i - 1] == t[j - 1]) { dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod; }
		}
	}

	cout << dp[n][8] << '\n';
	cin.ignore(2); return 0;
}