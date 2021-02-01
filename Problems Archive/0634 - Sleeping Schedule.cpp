#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int l, r, h, n;
int dp[2005][2001];
vector<int> v;

bool range(int x) { return x >= l && x <= r; }

int goodTimes(int i, int w) {
	if (i == n) { return 0; }
	if (dp[i][w] != -1) { return dp[i][w]; }

	int next1 = (w + v[i]) % h, next2 = (w + v[i] - 1 + h) % h;
	int a = goodTimes(i + 1, next1), b = goodTimes(i + 1, next2);

	return dp[i][w] = max(a + range(next1), b + range(next2));
}

int main() {
	cin >> n >> h >> l >> r; v.resize(n);
	for (auto &x : v) { cin >> x; }
	memset(dp, -1, sizeof(dp));
	cout << goodTimes(0, 0) << endl;
	cin.ignore(2); return 0;
}