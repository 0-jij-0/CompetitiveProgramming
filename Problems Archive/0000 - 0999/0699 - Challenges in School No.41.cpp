#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string s;
vector<vector<int>> res, ans;

bool check() {
	int n = (int)s.size();
	for(int i = 1; i < n; i++)
		if (s[i] == 'L' && s[i - 1] == 'R') { return true; }
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k >> s; int step = 0;
	while (check()) {
		for (int i = 1; i < n; i++) {
			if (s[i] == 'L' && s[i - 1] == 'R') {
				while ((int)res.size() <= step) { res.push_back(vector<int>()); }
				res[step].push_back(i - 1); s[i] = 'R'; s[i - 1] = 'L';
				i++; continue;
			}
		}
		step++;
	}
	if (step > k) { cout << -1 << '\n'; return 0; }
	int idx = 0, sum = step, num = 0;
	while (idx < step && sum - 1 + (int)res[idx].size() < k) { 
		sum = sum - 1 + res[idx].size(); idx++;
	}
	if (idx == step) { cout << -1 << '\n'; return 0; }
	num = sum - 1 + res[idx].size() - k - 1;
	for (int i = 0; i < step; i++) {
		if (i < idx) { 
			for (auto &x : res[i]) { ans.push_back({ x }); } 
			k -= (int) res[i].size(); continue;
		}
		if (i > idx) { ans.push_back(res[i]); continue; }
		k -= (step - idx - 1); int j = 0;
		while (k != 1) { ans.push_back({ res[i][j] }); k--; j++; }
		vector<int> rest; while (j < (int)res[i].size()) { rest.push_back(res[i][j]); j++; }
		ans.push_back(rest);
	}

	for (auto &x : ans) {
		cout << x.size() << ' ';
		for (auto &y : x) { cout << y + 1 << ' '; }
		cout << '\n';
	}
	cin.ignore(2); return 0;
}