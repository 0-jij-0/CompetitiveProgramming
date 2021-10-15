#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

string s;
ll dp[2][3002];

int main() {
	int n; cin >> n >> s;
	fill(dp[0], dp[0] + 6004, 0);

	dp[0][1] = 1; for (int i = 1; i < n; i++) {
		int cur = i & 1, prev = (i & 1) ^ 1;
		for (int j = 1; j <= i + 1; j++)
			dp[prev][j] = (dp[prev][j] + dp[prev][j - 1]) % mod;

		for (int j = 1; j <= i + 1; j++)
			dp[cur][j] = s[i - 1] == '<' ? dp[prev][j - 1] : (dp[prev][i + 1] - dp[prev][j - 1] + mod) % mod;
	}

	ll res = 0; for (int i = 1; i <= n; i++)
		res = (res + dp[(n & 1) ^ 1][i]) % mod;

	cout << res << '\n';
	cin.ignore(2); return 0;
}