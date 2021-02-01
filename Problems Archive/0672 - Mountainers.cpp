#include <iostream>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<vector<int>> g; int m, n, c;
vector<vector<bool>> on;
vector<vector<pair<int, int>>> history;
vector<pair<int, int>> v;

int idx(const int &i, const int &j) { return i * n + j; }
bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
	return g[p1.first][p1.second] < g[p2.first][p2.second];
}

struct DSU {
	vector<int> parent;
	vector<set<int>> children;

	DSU(int n) {
		parent.resize(n); children.resize(n);
		iota(parent.begin(), parent.end(), 0);
		for (int i = 0; i < n; i++) { children[i].insert(i); }
	}

	int size(const int &u) { return (int)children[parent[u]].size(); }

	bool merge(int u, int v, const int &w) {
		u = parent[u]; v = parent[v]; if (u == v) { return false; }
		set<int> &min = (size(u) < size(v)) ? children[u] : children[v];
		set<int> &max = (size(u) < size(v)) ? children[v] : children[u];
		int newParent = (size(u) < size(v)) ? v : u;
		for (auto &x : min) { 
			history[x].push_back({ c, w });
			parent[x] = newParent; max.insert(x);
		}
		c++; min.clear(); return true;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q; cin >> m >> n >> q; 
	history.resize(n*m); DSU dsu(n*m);
	g.resize(m, vector<int>(n));
	on.resize(m, vector<bool>(n, false));
	for(int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			v.push_back({ i, j });
			cin >> g[i][j];
		}
	sort(v.begin(), v.end(), compare);

	for (int k = 0; k < n*m; k++) {
		const int &i = v[k].first, &j = v[k].second; on[i][j] = true;
		if (i != 0 && on[i - 1][j]) { dsu.merge(idx(i, j), idx(i - 1, j), g[i][j]); }
		if (i != m - 1 && on[i + 1][j]) { dsu.merge(idx(i, j), idx(i + 1, j), g[i][j]); }
		if (j != 0 && on[i][j - 1]) { dsu.merge(idx(i, j), idx(i, j - 1), g[i][j]); }
		if (j != n - 1 && on[i][j + 1]) { dsu.merge(idx(i, j), idx(i, j + 1), g[i][j]); }
	}

	while (q--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--; int u = idx(x1, y1), v = idx(x2, y2);
		if (u == v) { cout << g[x1][y1] << endl; continue; }
		if (history[u].empty()) { cout << history[v].back().second << endl; continue; }
		if (history[v].empty()) { cout << history[u].back().second << endl; continue; }

		int sillyCheck = max(g[x1][y1], g[x2][y2]);
		int i = (int)history[u].size() - 1, j = (int)history[v].size() - 1;
		while (i >= 0 && j >= 0 && history[u][i].first == history[v][j].first) { i--; j--; }
		if (i == -1) { cout << max(history[v][j].second, sillyCheck) << endl; continue; }
		if (j == -1) { cout << max(history[u][i].second, sillyCheck) << endl; continue; }
		cout << max(history[u][i].second, history[v][j].second) << endl;
	}
	cin.ignore(2); return 0;
}