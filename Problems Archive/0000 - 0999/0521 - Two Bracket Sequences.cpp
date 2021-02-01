#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t; int n, m;
int dp[201][201][201];
int choice[201][201][201];

int min_length(int i, int j, int ps) {
	if (i == n && j == m) { choice[i][j][ps] = 3; return ps; }
	if (dp[i][j][ps] != -1) { return dp[i][j][ps]; }

	bool bi = (i < n && s[i] == '('), bj = (j < m && t[j] == '(');
	int a = (bi || bj || !ps) ? 1 + min_length(i + bi, j + bj, ps + 1) : 2 * (n + m + 1);
	if (!ps) { choice[i][j][ps] = 1; return dp[i][j][ps] = a; }
	bi = (i < n && s[i] == ')'), bj = (j < m && t[j] == ')');
	int b = (bi || bj) ? 1 + min_length(i + bi, j + bj, ps - 1) : 2 * (n + m + 1);
	choice[i][j][ps] = (a < b) ? 1 : 2;
	return dp[i][j][ps] = min(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> s >> t;
	n = (int) s.size();
	m = (int) t.size();

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int ps = 0; ps < min(m + n + 1, 200); ps++)
				dp[i][j][ps] = -1;

	int x = min_length(0, 0, 0); int i = 0, j = 0, ps = 0;
	while (true) {
		if (choice[i][j][ps] == 1) {
			bool bi = (i < n && s[i] == '('), bj = (j < m && t[j] == '(');
			cout << '('; i += bi; j += bj; ps++;
		}
		else if (choice[i][j][ps] == 2) {
			bool bi = (i < n && s[i] == ')'), bj = (j < m && t[j] == ')');
			cout << ')'; i += bi; j += bj; ps--;
		}
		else {
			while (ps--) { cout << ')'; }
			break;
		}
	}
	cout << endl; cin.ignore(2); return 0;
}