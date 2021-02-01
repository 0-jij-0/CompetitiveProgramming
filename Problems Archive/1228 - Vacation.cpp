#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[101][101];
string a, b; int n, m;

int LCS(int i, int j) {
	if (i == n || j == m) { return 0; }
	if (dp[i][j] != -1) { return dp[i][j]; }

	int A = (a[i] == b[j]) ? 1 + LCS(i + 1, j + 1) : 0;
	int B = LCS(i + 1, j), C = LCS(i, j + 1);
	return dp[i][j] = max({ A, B, C });
}

int main() {
	int t = 1; while (true) {
		getline(cin, a); if (a[0] == '#') { break; }
		getline(cin, b); n = (int)a.size(); m = (int)b.size();
		fill(dp[0], dp[0] + 101 * 101, -1);
		cout << "Case #" << t++ << ": you can visit at most ";
		cout << LCS(0, 0) << " cities." << '\n';
	}
	cin.ignore(2); return 0;
}