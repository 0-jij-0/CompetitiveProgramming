#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> h;
int dp[100002];

int main() {
	int n; cin >> n; h.resize(n);
	for (auto &x : h) { cin >> x; }
	h.resize(n + 2, 1 << 30);
	fill(dp, dp + n + 2, 1 << 30);
	dp[0] = 0; for (int i = 0; i < n; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
		dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
	}
	cout << dp[n - 1] << '\n';
	cin.ignore(2); return 0;
}