#include <iostream>
#include <algorithm>
using namespace std;

int mex[16][16];

int dfs(int x, int y) {
	if (mex[x][y] != -1) { return mex[x][y]; }
	int res[5] = { 0, 0, 0, 0, 0 };
	if (x > 2 && y < 15) { res[dfs(x - 2, y + 1)] = 1; }
	if (x > 2 && y > 1) { res[dfs(x - 2, y - 1)] = 1; }
	if (x < 15 && y > 2) { res[dfs(x + 1, y - 2)] = 1; }
	if (x > 1 && y > 2) { res[dfs(x - 1, y - 2)] = 1; }

	return mex[x][y] = find(res, res + 5, 0) - res;
}

int main() {
	fill(mex[0], mex[0] + 16 * 16, -1);
	for (int i = 1; i < 16; i++)
		for (int j = 1; j < 16; j++)
			dfs(i, j);

	int t; cin >> t; while (t--) {
		int k, x, y; cin >> k; int res = 0;
		while (k--) { cin >> x >> y; res ^= mex[x][y]; }
		cout << (res ? "First" : "Second") << '\n';
	}
	cin.ignore(2); return 0;
}