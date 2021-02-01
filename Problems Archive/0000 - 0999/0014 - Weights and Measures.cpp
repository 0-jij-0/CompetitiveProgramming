#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int dp[5610];
vector<pair<int, int>> v;

int main() {
	while (true) {
		int w; cin >> w; if (cin.fail()) break;
		int s; cin >> s; v.emplace_back(s - w, w);
	}
	auto comp = [&](pair<int, int> &p1, pair<int, int> &p2) {
		return p2.first + p2.second > p1.first + p1.second;
	};
	sort(v.begin(), v.end(), comp); int n = (int)v.size(); 
	fill(dp, dp + 5610, 1 << 30); dp[0] = 0;
	
	for (int i = 0; i < n; i++)
		for (int j = i; j >= 0; j--)
			if (dp[j] <= v[i].first)
				dp[j + 1] = min(dp[j + 1], dp[j] + v[i].second);

	int idx = lower_bound(dp, dp + 5610, 1 << 30) - dp;
	cout << idx - 1 << '\n'; cin.ignore(2); return 0;
}