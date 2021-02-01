#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> t, dp, pref;
vector<pair<int, int>> v;

int main() {
	int r, n; cin >> r >> n;
	v.resize(n); t.resize(n); 
	dp.resize(n); pref.resize(n);
	for (int i = 0; i < n; i++)
		cin >> t[i] >> v[i].first >> v[i].second;

	dp[0] = pref[0] = (v[0].first + v[0].second - 2) <= t[0];
	for (int i = 1; i < n; i++) {
		dp[i] = (v[i].first + v[i].second - 2) <= t[i];
		if (!dp[i]) { pref[i] = pref[i - 1]; continue; }
		int k = i - 2 * r, j = max(0, i - 2 * r + 1);
		if (k >= 0) { dp[i] = 1 + pref[k]; }
		for(; j < i; j++) {
			int dx = abs(v[i].first - v[j].first);
			int dy = abs(v[i].second - v[j].second);
			if (dx + dy <= t[i] - t[j]) dp[i] = max(dp[i], 1 + dp[j]);
		}
		pref[i] = max(pref[i - 1], dp[i]);
	}
	cout << pref[n - 1] << '\n';
	cin.ignore(2); return 0;
}