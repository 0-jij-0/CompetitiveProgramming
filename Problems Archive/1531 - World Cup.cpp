#include <iostream>
using namespace std;
typedef long long ll;

ll dp[66][66];

int main() {
	freopen("wcup.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 66; i++)
		dp[i][i] = dp[i][0] = 1;

	for (int i = 2; i < 66; i++) for (int j = 1; j < i; j++)
		dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];

	int x, y; cin >> x >> y;
	while (x >= 0 && y >= 0) {
		cout << dp[x + y][x] << '\n';
		cin >> x >> y;
	}
	cin.ignore(2); return 0;
}