#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
int dp[6] = { 1, 0, 0, 0, 0, 0 };

int main() {
	int n; cin >> n; int sum = 1;

	for (int i = 1; i < 6; i++) {
		for (int j = 1; j <= i; j++) dp[i] += dp[i - j];
		sum += dp[i];
	}

	for (int i = 6; i <= n; i++) {
		int t = dp[i % 6]; dp[i % 6] = sum;
		t = (dp[i % 6] - t + mod) % mod;
		sum = (sum + t) % mod;
	}
	cout << dp[n % 6] << '\n';
	cin.ignore(2); return 0;
}