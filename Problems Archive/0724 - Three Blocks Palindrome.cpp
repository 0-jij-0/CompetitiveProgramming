#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> idx;

bool compare(const int &i, const int &j) { return i > j; }

int check(int i, int j) {
	if (idx[i].empty() || idx[j].empty()) { return 0; }
	int a = 0, b = (int)idx[i].size() - 1, res = 0;
	int n = (int)idx[i].size(), m = (int)idx[j].size();
	while (a < b) {
		int id1 = lower_bound(idx[j].begin(), idx[j].end(), idx[i][a]) - idx[j].begin();
		if (id1 == (int)idx[j].size()) { break; }
		int id2 = lower_bound(idx[j].rbegin(), idx[j].rend(), idx[i][b], compare) - idx[j].rbegin();

		while (((a + 1) < (b - 1)) && (idx[i][a + 1] < idx[j][id1]) && (idx[i][b - 1] > idx[j][m - id2 - 1])) { a++; b--; }
		int bCount = m - id2 - id1, aCount = 2 * (a + 1);
		res = max(res, aCount + bCount); a++; b--;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n; idx.clear();
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if ((int)idx.size() <= x) { idx.resize(x + 1); }
			idx[x].push_back(i);
		}
		int s = (int)idx.size() - 1;
		int res = 0;
		for (int i = 1; i <= s; i++) {
			for (int j = 1; j <= s; j++) {
				if (i == j) { res = max(res, (int)idx[i].size()); continue; }
				res = max(res, check(i, j));
			}
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}