#include <iostream>
#include <algorithm>
using namespace std;

int dp[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int main() {
	int n; cin >> n;
	for (int i = 10; i <= n; i++) {
		int x = i; dp[i % 10] = i; while (x) {
			if (x % 10) dp[i % 10] = min(dp[i % 10], 1 + dp[(i - (x % 10)) % 10]);
			x /= 10;
		}
	}
	cout << dp[n % 10] << '\n';
	cin.ignore(2); return 0;
}