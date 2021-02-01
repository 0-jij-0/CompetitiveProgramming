#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000001];
vector<int> v; int n;

int main() {
	int x; cin >> n >> x; v.resize(n);
	for (auto &y : v) { cin >> y; }
	fill(dp, dp + 1000001, 1 << 30);

	dp[0] = 0; for (int i = 1; i <= x; i++)
		for (int j = 0; j < n; j++)	if (v[j] <= i) 
			dp[i] = min(dp[i], 1 + dp[i - v[j]]);

	cout << (dp[x] < (1 << 30) ? dp[x] : -1) << '\n';
	cin.ignore(2); return 0;
}