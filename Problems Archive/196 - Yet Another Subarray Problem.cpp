#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;
int n, m, k;
long long dp[300001][12][2];

long long max_cost(int i, int j, bool s) {
	if (dp[i][j][s] != -1) { return dp[i][j][s]; }
	if (i == n) { return 0; }
	long long a, b;
	b = v[i] + max_cost(i + 1, (j + 1) % m, 1);
	a = (s == 0) ? max_cost(i + 1, 0, 0) : 0;
	if (j == 0) { b -= k; }
	long long max = (a > b) ? a : b;
	dp[i][j][s] = (max > 0) ? max : 0;
	return dp[i][j][s];
}

int main() {
	cin >> n >> m >> k; v.resize(n);
	for (int i = 0; i < 300001; i++) {
		for (int j = 0; j < 12; j++) {
			dp[i][j][1] = -1;
			dp[i][j][0] = -1;
		}
	}
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	long long res = max_cost(0, 0, 0);
	cout << res << endl;
	cin.ignore(2); return 0;
}