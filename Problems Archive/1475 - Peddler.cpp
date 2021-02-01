#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<int> a;

int main() {
	int n, m; cin >> n >> m; 
	v.resize(n); a.resize(n);
	for (auto& x : a) { cin >> x; }
	vector<int> dp = a;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[--a].emplace_back(--b);
	}

	int res = -(1 << 30);
	for (int i = n - 1; i >= 0; i--)
		for (auto& e : v[i]) { 
			res = max(res, dp[e] - a[i]);
			dp[i] = max(dp[i], dp[e]);
		}

	cout << res << '\n'; cin.ignore(2); return 0;
}