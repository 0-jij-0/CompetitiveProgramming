#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[21][10][2][2][2]; string A, B;

ll count(int i, int d, bool x, bool y, bool z) {
	if (i == 20) { return 1; }
	if (dp[i][d][x][y][z] != -1) { return dp[i][d][x][y][z]; }

	int l = x ? A[i] : '0', r = y ? B[i] : '9'; ll res = 0;
	for (int k = l; k <= r; k++) if (z || k - '0' != d)
		res += count(i + 1, k - '0', x && k == A[i], y && k == B[i], z && k == '0');

	return dp[i][d][x][y][z] = res;
}

int main() {
	ll a, b; cin >> a >> b;
	A = to_string(a); B = to_string(b);
	A = string(20 - A.size(), '0') + A;
	B = string(20 - B.size(), '0') + B;
	fill(dp[0][0][0][0], dp[0][0][0][0] + 21 * 10 * 2 * 2 * 2, -1);
	cout << count(0, 0, 1, 1, 1) << '\n';
}