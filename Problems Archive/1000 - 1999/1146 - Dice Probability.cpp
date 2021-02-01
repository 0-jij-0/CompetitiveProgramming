#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef double ld;

ld dp[101][601][601];

ld prob(int n, int a, int b) {
	if (b < 0) { return 0.0; }
	if (!n) { return (a == 0) + 0.0; }
	if (dp[n][a][b] > -0.1) { return dp[n][a][b]; }
	ld res = 0.0; for (int i = 1; i <= 6; i++)
		res += (1.0 / 6.0) * prob(n - 1, max(0, a - i), b - i);
	return dp[n][a][b] = res;
}

int main() {
	int n, a, b; cin >> n >> a >> b;
	fill(dp[0][0], dp[0][0] + 101 * 601 * 601, -1.0);
	cout << fixed << setprecision(6) << prob(n, a, b) << endl;
	cin.ignore(2); return 0;
}