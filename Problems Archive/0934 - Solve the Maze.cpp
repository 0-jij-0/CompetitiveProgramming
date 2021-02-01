#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<string> v; int n, m;

bool bfs(int x, int y, int t, vector<vector<int>> &visited) {
	if (visited[x][y] > t) { return true; }

	queue<pair<int, int>> q; q.push({ x, y });
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second; q.pop();
		if (i != 0 && visited[i - 1][j] > t) { return true; }
		if (i != 0 && !visited[i - 1][j] && (v[i - 1][j] == '.' || v[i - 1][j] == 'G')) { visited[i - 1][j] = t; q.push({ i - 1, j }); }
		if (i != n - 1 && visited[i + 1][j] > t) { return true; }
		if (i != n - 1 && !visited[i + 1][j] && (v[i + 1][j] == '.' || v[i + 1][j] == 'G')) { visited[i + 1][j] = t; q.push({ i + 1, j }); }
		if (j != 0 && visited[i][j - 1] > t) { return true; }
		if (j != 0 && !visited[i][j - 1] && (v[i][j - 1] == '.' || v[i][j - 1] == 'G')) { visited[i][j - 1] = t; q.push({ i, j - 1 }); }
		if (j != m - 1 && visited[i][j + 1] > t) { return true; }
		if (j != m - 1 && !visited[i][j + 1] && (v[i][j + 1] == '.' || v[i][j + 1] == 'G')) { visited[i][j + 1] = t; q.push({ i, j + 1 }); }
	}
	return false;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> m; v.resize(n);
		bool ok = true; int g = 0;
		for (auto &x : v) { cin >> x; g += count(x.begin(), x.end(), 'G'); }
		if (g == 0) { cout << "Yes" << endl; continue; }
		for(int i = 0; (i < n) && ok; i++)
			for (int j = 0; j < m; j++) {
				if (v[i][j] != 'B') { continue; }
				if (i != 0 && v[i - 1][j] == 'G') { ok = false; break; }
				else if (i != 0 && v[i - 1][j] == '.') { v[i - 1][j] = '#'; }
				if (i != n - 1 && v[i + 1][j] == 'G') { ok = false; break; }
				else if (i != n - 1 && v[i + 1][j] == '.') { v[i + 1][j] = '#'; }
				if (j != 0 && v[i][j - 1] == 'G') { ok = false; break; }
				else if (j != 0 && v[i][j - 1] == '.') { v[i][j - 1] = '#'; }
				if (j != m - 1 && v[i][j + 1] == 'G') { ok = false; break; }
				else if (j != m - 1 && v[i][j + 1] == '.') { v[i][j + 1] = '#'; }
			}

		//for (auto &x : v) { cout << x << '\n'; } cout << '\n';
		if (v.back().back() == '#') { ok = false; }
		if (!ok) { cout << "No" << endl; continue; }
		vector<vector<int>> visited(n, vector<int>(m, 0)); 
		int t = n * m + 10; visited.back().back() = t + 10;
		for(int i = 0; (i < n) && ok; i++)
			for(int j = 0; j < m; j++)
				if (v[i][j] == 'G' && !bfs(i, j, t--, visited)) { ok = false; break; }
		cout << (ok ? "Yes" : "No") << endl;
	}
	cin.ignore(2); return 0;
}