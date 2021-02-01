#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

long long dp[200001][2];
int n; long long a, b;
string s;

long long min_cost_road(int i, int f) {
	if (dp[i][f] != -1) { return dp[i][f]; }
	if (i == n - 1) { return (1 + f)*a + (2 + f)*b; }
	if (f == (s[i] - '0')) { dp[i][f] = (1 + f) * b + a + min_cost_road(i + 1, f); return dp[i][f]; }
	if (f < (s[i] - '0')) { dp[i][f] = 2 * b + 2 * a + min_cost_road(i + 1, 1); return dp[i][f]; }
	long long res = 2 * b + a + min_cost_road(i + 1, 1);
	res = min(res, 2 * b + 2 * a + min_cost_road(i + 1, 0));
	dp[i][f] = res; return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < 200001; i++)
			dp[i][0] = dp[i][1] = -1;
		cin >> n >> a >> b >> s;
		cout << min_cost_road(0, 0) << endl;
	}
	cin.ignore(2); return 0;
}

