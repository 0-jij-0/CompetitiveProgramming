#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[200001][2];
vector<int> a, b;
int n, c;

int min_time(int i, int s) {
	if (dp[i][s] != -1) { return dp[i][s]; }
	if (i == 0) { return dp[i][s] = s ? c : 0; }
	int t = s ? b[i - 1] : a[i - 1];
	int x = t + min_time(i - 1, 0);
	int y = t + min_time(i - 1, 1);
	if (s) { x += c; }
	return dp[i][s] = min(x, y);
}

int main() {
	cin >> n >> c; a.resize(n - 1); b.resize(n - 1);
	for (auto &x : a) { cin >> x; }
	for (auto &x : b) { cin >> x; }
	for (int i = 0; i <= n; i++)
		dp[i][0] = dp[i][1] = -1;
	min_time(n - 1, 0); min_time(n - 1, 1);
	for (int i = 0; i < n; i++) {
		cout << min(dp[i][0], dp[i][1]) << ' ';
	}
	cout << endl; cin.ignore(2); return 0;
}