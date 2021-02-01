#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<vector<int>> v;
vector<int> idx;
int dp[35][35];
int choice[35][35];
int k, n;

int maxNestLength(int i, int last) {
	if (i == k) { return 1; }
	if (dp[i][last] != -1) { return dp[i][last]; }

	int a = maxNestLength(i + 1, last), b = 1;
	for(int j = 0; j < n; j++)
		if (v[idx[i]][j] <= v[idx[last]][j]) { b = 0; break; }
	b = b ? 1 + maxNestLength(i + 1, i) : 0;
	choice[i][last] = (a > b) ? 0 : 1;
	return dp[i][last] = max(a, b);
}

bool compare (const int &x1, const int &x2) {
	return v[x1][0] < v[x2][0];
}

int main() {
	while (true) {
		cin >> k; if (cin.fail()) { break; }
		cin >> n; v.clear(); v.resize(k, vector<int>(n));
		if (k == 1) { cout << 1 << endl << 1 << endl; continue; }
		idx.resize(k); iota(idx.begin(), idx.end(), 0);
		memset(dp, -1, sizeof(dp)); memset(choice, -1, sizeof(choice));
		for (auto &x : v) {
			for (auto &y : x) cin >> y;
			sort(x.begin(), x.end());
		}
		sort(idx.begin(), idx.end(), compare); int res = 0;
		for (int i = 0; i < k; i++)
			res = max(res, maxNestLength(i + 1, i));

		cout << res << endl; int cur = 1, last = 0;
		while (dp[cur][last] != res) { cur++; last++; }
		cout << idx[last] + 1 << (res == 1 ? '\n' : ' '); res--;
		while (cur != k) {
			if (choice[cur][last] == 0) { cur++; continue; }
			cout << idx[cur] + 1 << (res == 1 ? '\n' : ' ');
			last = cur; cur++; res--;
		}
	}
	cin.ignore(2); return 0;
}