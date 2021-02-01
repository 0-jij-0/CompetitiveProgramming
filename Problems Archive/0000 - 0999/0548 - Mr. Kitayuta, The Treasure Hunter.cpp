#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> g; int d, a;
int dp[30001][501];
int offset[501];

int max_gems(int i, int off) {
	if (i > a) { return 0; }
	if (dp[i][off] != -1) { return dp[i][off]; }

	int a = (d + offset[off - 1] > 0) ? max_gems(i + d + offset[off - 1], off - 1) : 0;
	int b = max_gems(i + d + offset[off], off);
	int c = max_gems(i + d + offset[off + 1], off + 1);

	int x = max(a, max(b, c));
	return dp[i][off] = g[i] + x;
}

int main() {
	int n; cin >> n >> d;
	g.resize(30001, 0);
	for (int i = 0; i < n; i++) {
		cin >> a; g[a]++;
	}

	int off = -250;
	for (int i = 0; i < 501; i++) {
		offset[i] = off; off++;
	}
	for (int i = 0; i < 30001; i++)
		for (int j = 0; j < 501; j++)
			dp[i][j] = -1;

	cout << max_gems(d, 250) << endl;
	cin.ignore(2); return 0;
}