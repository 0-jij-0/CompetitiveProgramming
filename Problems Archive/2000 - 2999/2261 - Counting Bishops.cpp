#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 1000 * 1000 * 1000 + 7;

int diagonalSize(int i) { return ((i >> 2) << 1) + 1 + (i & 1); }

ll DP[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	if (n == 1) { cout << (k < 2) << '\n'; return 0; }
	if (k > (n << 1) - 1) { cout << "0\n"; return 0; }
	int N = (n << 1) - 1;

	fill(DP[0], DP[0] + 1001 * 1001, 0);
	for (int i = 0; i < N; i++) DP[i][0] = 1;
	DP[0][1] = 1; DP[1][1] = 2;

	for (int i = 2; i < N; i++) for (int j = 1; j <= k; j++)
		DP[i][j] = (DP[i - 2][j] + DP[i - 2][j - 1] * (diagonalSize(i) - j + 1)) % mod;

	int res = 0; for (int i = 0; i <= k; i++)
		res = (res + DP[N - 1][i] * DP[N - 2][k - i]) % mod;

	cout << res << '\n';
}