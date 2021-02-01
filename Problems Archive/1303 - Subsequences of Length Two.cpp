#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

string s, t; int n;
vector<int> A, B;
int dp[201][201][201];

int maxSubseqCount(int i, int k, int a) {
	if (i == n) { return 0; }
	if (dp[i][k][a] != -1) { return dp[i][k][a]; }
	if (k == 0) {
		int res = maxSubseqCount(i + 1, 0, a + (s[i] == t[0]));
		return dp[i][k][a] = res + (s[i] == t[1] ? a : 0);
	}
	if (s[i] == t[0]) {
		int x = maxSubseqCount(i + 1, k, a + 1);
		int y = a + maxSubseqCount(i + 1, k - 1, a);
		return dp[i][k][a] = max(x, y);
	}
	if (s[i] == t[1]) {
		int x = maxSubseqCount(i + 1, k - 1, a + 1);
		int y = a + maxSubseqCount(i + 1, k, a);
		return dp[i][k][a] = max(x, y);
	}
	int x = maxSubseqCount(i + 1, k - 1, a + 1);
	int y = a + maxSubseqCount(i + 1, k - 1, a);
	int z = maxSubseqCount(i + 1, k, a);
	return dp[i][k][a] = max({ x, y, z });
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k; cin >> n >> k >> s >> t;

	if (t[0] == t[1]) {
		int c = count(s.begin(), s.end(), t[0]);
		int res = min(n, c + k);
		cout << res * (res - 1) / 2 << '\n';
		cin.ignore(2); return 0;
	}

	fill(dp[0][0], dp[0][0] + 201 * 201 * 201, -1);
	cout << maxSubseqCount(0, k, 0) << '\n';
	cin.ignore(2); return 0;
}