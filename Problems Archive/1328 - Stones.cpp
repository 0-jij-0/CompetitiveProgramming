#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dp[100001];
vector<int> v;

int main() {
	int n, k; cin >> n >> k; v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end()); fill(dp, dp + 100001, 0);
	for(int i = 1; i <= k; i++)
		for(int j = 0; j < n && v[j] <= i; j++)
			if (!dp[i - v[j]]) { dp[i] = 1; break; }
	cout << (dp[k] ? "First" : "Second") << '\n';
	cin.ignore(2); return 0;
}