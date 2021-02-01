#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point { int x, y, z; point() {} };

vector<point> p; int n;
vector<vector<int>> d;
vector<vector<int>> dp;

int minCostPath(int i, int mask) {
	if (mask == 0) { return d[i][0]; }
	if (dp[i][mask] != -1) { return dp[i][mask]; }
	
	int cost = 1 << 30;
	for (int j = 0; j < n; j++) if ((1 << j) & mask)
		cost = min(cost, d[i][j] + minCostPath(j, mask ^ (1 << j)));

	return dp[i][mask] = cost;
}

int main() {
	cin >> n; p.resize(n);
	d.resize(n, vector<int>(n));

	for (auto &x : p) { cin >> x.x >> x.y >> x.z; }

	for (int i = 0; i < n; i++)	for (int j = 0; j < n; j++)
		d[i][j] = abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y) + max(0, p[j].z - p[i].z);

	dp.resize(n, vector<int>(1 << n, -1));
	cout << minCostPath(0, (1 << n) - 2) << '\n';
	cin.ignore(2); return 0;
}