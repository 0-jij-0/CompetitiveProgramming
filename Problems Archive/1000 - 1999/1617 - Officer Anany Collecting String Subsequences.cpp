#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n; string s;
vector<vector<int>> freq;

int findMin() {
	int res = n;
	for (auto& x : freq[0]) {
		int cur = x, i = 1; while (i != 26) {
			auto it = lower_bound(freq[i].begin(), freq[i].end(), cur);
			if (it == freq[i].end()) { return res; }
			cur = *it; i++;
		}
		res = min(res, cur - x + 1);
	}
	return res;
}

int main() {
	freopen("collectingofficer.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n >> s; freq.clear(); freq.resize(26);
		for (int i = 0; i < n; i++) freq[s[i] - 'A'].push_back(i);
		cout << findMin() << '\n';
	}
	cin.ignore(2); return 0;
}