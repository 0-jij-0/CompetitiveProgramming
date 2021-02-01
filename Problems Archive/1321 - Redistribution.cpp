#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;

int dp[2001];

int main() {
	int s; cin >> s; 
	dp[0] = dp[1] = dp[2] = 0;
	fill(dp + 3, dp + 2001, 1);
	for (int i = 3; i <= s; i++)
		for (int j = 3; j <= i - 3; j++)
			dp[i] = (dp[i] + dp[i - j]) % mod;

	cout << dp[s] << '\n';
	cin.ignore(2); return 0;
}