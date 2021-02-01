#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int coins[5] = { 50, 25, 10, 5, 1 };
ll dp[5][7500];

ll countWays(int i, int t) {
	if(t == 0) { return 1; }
	if (i == 5 || t < 0) { return 0; }
	if (dp[i][t] != -1) { return dp[i][t]; }

	return dp[i][t] = (countWays(i + 1, t) + countWays(i, t - coins[i]));
}

int main() {
	fill(dp[0], dp[0] + 5 * 7500, -1ll);
	while (true) {
		int n; cin >> n; if (cin.fail()) { break; }
		cout << countWays(0, n) << endl;
	}
	cin.ignore(2); return 0;
}