#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int dp[10][1100];
int choice[10][1100];
int n, m;
vector<string> v;

int getMask(int j, char c, int mask) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (((1 << i) & mask) == 0) { continue; }
		if (v[i][j] != c) { res |= 1 << i; }
	}
	return res;
}

int can(int i, int mask) {
	if (i == m) { return 1; }
	if (dp[i][mask] != -1) { return dp[i][mask]; }

	int j = 0; char c = '0';
	while (j < n) {
		if ((1 << j) & mask) { j++; continue; }
		if (c == '0') { c = v[j][i]; j++; continue; }
		if (v[j][i] != c) { return dp[i][mask] = 0; }
		j++;

	}
	if (c != '0') { 
		choice[i][mask] = c;
		return dp[i][mask] = can(i + 1, mask ^ getMask(i, c, mask));
	}
	for (int j = 0; j < n; j++)
		if (can(i + 1, mask ^ getMask(i, v[j][i], mask))) {
			choice[i][mask] = v[j][i];
			return dp[i][mask] = 1;
		}
	return dp[i][mask] = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		cin >> n >> m; v.resize(n);
		for (auto &x : v) { cin >> x; }
		if (!can(0, (1 << n) - 1)) { cout << -1 << '\n'; continue; }
		int idx = 0, mask = (1 << n) - 1;
		while(idx != m) {
			cout << (char)choice[idx][mask];
			mask ^= getMask(idx, choice[idx][mask], mask);
			idx++;
		}
		cout << '\n';
	}
	cin.ignore(2); return 0;
}