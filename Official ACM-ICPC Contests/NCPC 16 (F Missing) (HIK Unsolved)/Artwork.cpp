#include <iostream>
#include <vector>
#include <numeric>
#include <set>
using namespace std;

struct DSU {
	vector<vector<int>> rank;
	vector<vector<pair<int, int>>> parent;
	int comp = 0;

	DSU(int n, int m) {
		rank.resize(n, vector<int>(m, 1)); parent.resize(n, vector<pair<int, int>>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				parent[i][j] = { i, j };
	}

	pair<int, int> find(const int &u, const int &v) {
		if (parent[u][v].first == u && parent[u][v].second == v) {
			return { u, v };
		}
		return parent[u][v] = find(parent[u][v].first, parent[u][v].second);
	}
	int size(const int &u, const int &v) { return rank[find(u, v).first][find(u, v).second]; }

	bool merge(int u1, int u2, int v1, int v2) {
		pair<int, int> u = find(u1, u2), v = find(v1, v2);
		if (u == v) { return false; }
		if (rank[u.first][u.second] < rank[v.first][v.second]) { swap(u, v); }
		rank[u.first][u.second] += rank[v.first][v.second];
		parent[v.first][v.second] = u; comp--;
		return true;
	}
};

vector<int> res;
vector<set<pair<int, int>>> queries;
vector<vector<int>> grid;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, q; cin >> n >> m >> q; DSU dsu(n, m);
	grid.resize(n, vector<int>(m, 1));
	queries.resize(q); res.resize(q);
	for (int i = 0; i < q; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		if (x1 == x2) {
			for (int y = y1; y <= y2; y++) {
				if (grid[x1][y] == 0) { continue; }
				queries[i].insert({ x1, y });
				grid[x1][y] = 0;
			}
		}
		else {
			for (int x = x1; x <= x2; x++) {
				if (grid[x][y1] == 0) { continue; }
				queries[i].insert({ x, y1 });
				grid[x][y1] = 0;
			}
		}
	}

	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0) { continue; }
			dsu.comp++;
			if (i != 0 && grid[i - 1][j]) { dsu.merge(i - 1, j, i, j); }
			if (i != n - 1 && grid[i + 1][j]) { dsu.merge(i + 1, j, i, j); }
			if (j != 0 && grid[i][j - 1]) { dsu.merge(i, j - 1, i, j); }
			if (j != m - 1 && grid[i][j + 1]) { dsu.merge(i, j + 1, i, j); }
		}

	for (int idx = q - 1; idx >= 0; idx--) {
		res[idx] = dsu.comp;
		for (auto &x : queries[idx]) {
			int i = x.first, j = x.second;
			grid[i][j] = 1; dsu.comp++;
			if (i != 0 && grid[i - 1][j]) { dsu.merge(i - 1, j, i, j); }
			if (i != n - 1 && grid[i + 1][j]) { dsu.merge(i + 1, j, i, j); }
			if (j != 0 && grid[i][j - 1]) { dsu.merge(i, j - 1, i, j); }
			if (j != m - 1 && grid[i][j + 1]) { dsu.merge(i, j + 1, i, j); }
		}
	}
	for (auto &x : res) { cout << x << endl; }

	cin.ignore(2); return 0;
}