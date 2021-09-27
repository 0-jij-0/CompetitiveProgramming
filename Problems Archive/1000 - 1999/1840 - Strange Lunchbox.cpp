#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[301][301][301];
vector<int> a, b; int X, Y;

int main() {
	int n; cin >> n >> X >> Y;
	a.resize(n); b.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	fill(dp[0][0], dp[0][0] + 301 * 301 * 301, 1 << 30);
	for (int i = 0; i < n; i++) dp[i][0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int A = 0; A <= X; A++) for (int B = 0; B <= Y; B++) {
			dp[i + 1][A][B] = min(dp[i + 1][A][B], dp[i][A][B]);
			dp[i + 1][min(X, A + a[i])][min(Y, B + b[i])] =
				min(dp[i + 1][min(X, A + a[i])][min(Y, B + b[i])], 1 + dp[i][A][B]);
		}

	cout << (dp[n][X][Y] == 1 << 30 ? -1 : dp[n][X][Y]) << '\n';
	cin.ignore(2); return 0;
}