#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DP[11][101];
vector<vector<int>> v;
int n, m;
const int inf = 1 << 30;

int minimumCost(int row, int col) {
	if (col == m - 1) { return DP[row][col] = v[row][col]; }
	if (DP[row][col] != inf + 1) { return DP[row][col]; }

	int cost = v[row][col];
	int up = minimumCost((row - 1 + n) % n, col + 1);
	int straight = minimumCost(row, col + 1);
	int down = minimumCost((row + 1) % n, col + 1);

	return DP[row][col] = cost + min({ up, straight, down });
}

void uni_TSP(int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			DP[i][j] = inf + 1;

	int res = 1 << 30; res++;
	for (int i = 0; i < n; i++)
		res = min(res, minimumCost(i, 0));

	int cur = res; int col = 0; int row = 0;
	while (row < n && DP[row][0] != res) { row++; }

	while (col < m) {
		cur -= v[row][col]; col++; cout << row + 1; 
		if (col != m) { cout << ' '; }
		else { cout << '\n' << res << '\n'; break; }

		int up = (row - 1 + n) % n, straight = row, down = (row + 1) % n;
		int first = up, second = straight, third = down;
		if (first > second) { swap(first, second); }
		if (first > third) { swap(first, third); }
		if (second > third) { swap(second, third); }

		if (DP[first][col] == cur) { row = first; continue; }
		if (DP[second][col] == cur) { row = second; continue; }
		if (DP[third][col] == cur) { row = third; continue; }
	}
}

int main() {
	while (true) {
		cin >> n; if (cin.fail()) { break; }
		cin >> m; v.clear(); v.resize(n, vector<int>(m));
		for (auto &x : v) for (auto &y : x) cin >> y;
		uni_TSP(n, m);
	}
	cin.ignore(2); return 0;
}