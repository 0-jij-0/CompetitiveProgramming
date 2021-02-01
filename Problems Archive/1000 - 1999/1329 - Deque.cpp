#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dp[3001][3001]; vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	for (int i = 0; i < n; i++) dp[i][i] = v[i];

	for (int i = 1; i < n; i++) for (int j = 0; j < n - i; j++)
		dp[j][j + i] = max(v[j] - dp[j + 1][j + i], v[j + i] - dp[j][j + i - 1]);

	cout << dp[0][n - 1] << '\n'; cin.ignore(2); return 0;
}