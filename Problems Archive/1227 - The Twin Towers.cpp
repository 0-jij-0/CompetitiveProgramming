#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[101][101];
vector<int> a, b;
int n, m;

int LCS(int i, int j) {
	if (i == n || j == m) { return 0; }
	if (dp[i][j] != -1) { return dp[i][j]; }

	int A = (a[i] == b[j]) ? 1 + LCS(i + 1, j + 1) : 0;
	int B = LCS(i + 1, j), C = LCS(i, j + 1);
	return dp[i][j] = max({ A, B, C });
}

int main() {
	int t = 1; while (true) {
		cin >> n >> m; if (n + m == 0) break;
		a.resize(n); b.resize(m);
		for (auto &x : a) { cin >> x; }
		for (auto &x : b) { cin >> x; }
		fill(dp[0], dp[0] + 101 * 101, -1); 
		cout << "Twin Towers #" << t++ << '\n';
		cout << "Number of Tiles : " << LCS(0, 0) << '\n' << '\n';
	}
	cin.ignore(2); return 0;
}