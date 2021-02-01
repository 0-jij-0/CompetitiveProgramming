#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int choice[1001][1001];
string a, b; int n, m;

int LCS(int i, int j) {
	if (i == n || j == m) { return 0; }
	if (dp[i][j] != -1) { return dp[i][j]; }

	int A = (a[i] == b[j]) ? 1 + LCS(i + 1, j + 1) : 0;
	int B = LCS(i + 1, j), C = LCS(i, j + 1);

	if (A >= max(B, C)) { choice[i][j] = 1; }
	else if (B >= max(A, C)) { choice[i][j] = 2; }
	else { choice[i][j] = 3; }

	return dp[i][j] = max({ A, B, C });
}

void printLCS(int len) {
	int i = 0, j = 0;
	while (len) {
		if (choice[i][j] == 2) { i++; continue; }
		if (choice[i][j] == 3) { j++; continue; }
		cout << a[i]; len--; i++; j++;
	}
	cout << '\n';
}

int main() {
	while (true) {
		getline(cin, a); if (a.empty()) { break; }
		getline(cin, b); n = (int)a.size(), m = (int)b.size();
		fill(dp[0], dp[0] + 1001 * 1001, -1); int res = LCS(0, 0);
		cout << res << '\n';// << "LCS: "; printLCS(res);
	}
	cin.ignore(2); return 0;
}