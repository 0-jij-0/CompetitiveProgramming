#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grid;
vector<bool> teams;

int main() {
	int n, m; cin >> n >> m;
	grid.resize(n, vector<int>(m));
	teams.resize(102, false);
	for (auto &x : grid)
		for (auto &y : x)
			cin >> y;

	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (teams[grid[i][j] + 1]) { continue; }
			if (i != 0 && j != 0 && grid[i][j] == grid[i - 1][j - 1]) { teams[grid[i][j] + 1] = true; }
			if (i != 0 && grid[i][j] == grid[i - 1][j]) { teams[grid[i][j] + 1] = true; }
			if (i != 0 && j != n - 1 && grid[i][j] == grid[i - 1][j + 1]) { teams[grid[i][j] + 1] = true; }
			if (j != 0 && grid[i][j] == grid[i][j - 1]) { teams[grid[i][j] + 1] = true; }
			if (j != n - 1 && grid[i][j] == grid[i][j + 1]) { teams[grid[i][j] + 1] = true; }
			if (i != n - 1 && j != 0 && grid[i][j] == grid[i + 1][j - 1]) { teams[grid[i][j] + 1] = true; }
			if (i != n - 1 && grid[i][j] == grid[i + 1][j]) { teams[grid[i][j] + 1] = true; }
			if (i != n - 1 && j != n - 1 && grid[i][j] == grid[i + 1][j + 1]) { teams[grid[i][j] + 1] = true; }
		}

	int res = 0;
	for (int i = 1; i < 102; i++) { res += teams[i]; }
	cout << res << endl;
	cin.ignore(2); return 0;
}