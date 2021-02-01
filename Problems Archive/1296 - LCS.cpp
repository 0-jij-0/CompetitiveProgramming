#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int n, m; string a, b;
vector<vector<int>> dp;

int main() {
	cin >> a >> b; n = (int)a.size(); m = (int)b.size();
	dp.resize(n + 1, vector<int>(m + 1, 0));
	for(int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			dp[i][j] = max(i ? dp[i - 1][j] : 0, j ? dp[i][j - 1] : 0);
			if (a[i] == b[j]) { dp[i][j] = max(dp[i][j], 1 + (i && j ? dp[i - 1][j - 1] : 0)); }
		}
	stack<char> s; int i = n - 1, j = m - 1;
	while (i >= 0 && j >= 0 && dp[i][j] != 0) {
		if (a[i] == b[j]) { s.push(a[i]); i--; j--; }
		else (i && (dp[i][j] == dp[i - 1][j])) ? i-- : j--;
	}
	while (!s.empty()) { cout << s.top(); s.pop(); }
	cout << '\n'; cin.ignore(2); return 0;
}
