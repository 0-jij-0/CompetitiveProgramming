#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> h;

int main() {
	int n, k; cin >> n >> k; h.resize(n);
	for (auto &x : h) { cin >> x; }
	h.resize(n + k + 1, 1 << 30);
	vector<int> dp(k + 1, 1 << 30); dp[0] = 0;
	for (int i = 0; i < n; i++) {
		dp[(i + k) % (k + 1)] =  1 << 30;
		for (int j = 1; j <= k; j++)
			dp[(i + j) % (k + 1)] = min(dp[(i + j) % (k + 1)], dp[i % (k + 1)] + abs(h[i + j] - h[i]));
	}

	cout << dp[(n - 1) % (k + 1)] << '\n';
	cin.ignore(2); return 0;
}