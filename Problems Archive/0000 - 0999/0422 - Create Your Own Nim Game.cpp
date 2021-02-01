#include <iostream>
using namespace std;

long long dp[101][129];
const long long mod = 1000 * 1000 * 1000 + 7;

long long count(int i, int xs) {
	if (dp[i][xs] != -1) { return dp[i][xs]; }
	if (i == 0) { return xs != 0; }
	long long res = 0;
	for (int j = 1; j <= i; j++) {
		res += count(i - j, xs ^ j);
		res %= mod;
	}
	return dp[i][xs] = res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j < 129; j++)
				dp[i][j] = -1;
		cout << count(n, 0) << endl;
	}
	cin.ignore(2); return 0;
}
