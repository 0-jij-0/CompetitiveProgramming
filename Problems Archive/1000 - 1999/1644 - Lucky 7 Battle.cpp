#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;

string s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n >> s >> t;
	vector<array<int, 7>> dp(n + 1);
	for (int i = 0; i < 7; i++) dp[n][i] = (i != 0);
	for(int i = n - 1; i >= 0; i--)
		for (int j = 0; j < 7; j++) {
			if (t[i] == 'A') {
				if (dp[i + 1][(j * 10) % 7]) { dp[i][j] = 1; continue; }
				if (dp[i + 1][(j * 10 + s[i] - '0') % 7]) { dp[i][j] = 1; continue; }
				dp[i][j] = 0;
			}
			else {
				if (!dp[i + 1][(j * 10) % 7]) { dp[i][j] = 0; continue; }
				if (!dp[i + 1][(j * 10 + s[i] - '0') % 7]) { dp[i][j] = 0; continue; }
				dp[i][j] = 1;
			}
		}
	cout << (dp[0][0] ? "Aoki" : "Takahashi") << '\n';
	cin.ignore(2); return 0;
}