#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> point;

map<point, int> ids;

struct edge {
	int u, v; bool match = 0; edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node { vector<edge> edges; node() {} };

struct bipartiteGraph {
	vector<node> nodes; int n, m;
	vector<bool> Z, vis;
	vector<int> unMatched, match;

	bipartiteGraph(int _n, int _m) : n(_n), m(_m) {
		nodes.resize(n + m); Z.resize(n + m, 0);
		match.resize(n + m, -1); vis.resize(n + m, 0);
	}

	void add_edge(int u, int v) {
		nodes[u].edges.push_back(edge(u, v));
		nodes[v].edges.push_back(edge(v, u));
	}

	bool augment(int v) {
		if (v == -1) { return 1; }
		if (vis[v]) { return 0; }
		vis[v] = 1;
		for (auto &e : nodes[v].edges)
			if (augment(match[e.v])) {
				match[e.v] = v; match[v] = e.v;
				return 1;
			}
		return 0;
	}

	int maxMatching() { 
		int w = 0;
		for (int x = 0; x < n; x++) {
			if (match[x] != -1) { continue; }
			for (auto &e : nodes[x].edges)
				if (match[e.v] == -1) {
					match[e.v] = x; match[x] = e.v;
					w++; break;
				}
		}
		for (int i = 0; i < n; i++) {
			if (match[i] != -1) { continue; }
			for (int j = 0; j < n; j++) { vis[j] = 0; }
			w += augment(i);
		}
		return w;
	}
};

vector<vector<int>> col;
vector<string> v; int n, m;

void bfs(int x, int y, vector<bool> &visited) {
	queue<pair<int, int>> q; q.push({ x, y });
	visited[x * m + y] = true;

	while (!q.empty()) {
		int i = q.front().first, j = q.front().second; q.pop();
		if (v[i][j] != 'L') { v[i][j] = 'W'; continue; }
		if (i != 0 && !visited[(i - 1) * m + j]) { visited[(i - 1) * m + j] = true; q.push({ i - 1, j }); }
		if (i != n - 1 && !visited[(i + 1) * m + j]) { visited[(i + 1) * m + j] = true; q.push({ i + 1, j }); }
		if (j != 0 && !visited[i * m + j - 1]) { visited[i * m + j - 1] = true; q.push({ i, j - 1 }); }
		if (j != m - 1 && !visited[i * m + j + 1]) { visited[i * m + j + 1] = true; q.push({ i, j + 1 }); }
	}
}

point idx(int i, int j) { 
	if (i < 0 || j < 0) { return { -1, -1 }; }
	if (i >= n || j >= m) { return { -1, -1 }; }
	return { col[i][j], i * m + j };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m; v.resize(n);
	col.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			col[i][j] = (i % 2) ^ (j % 2);

	for (auto &x : v) { cin >> x; }
	vector<bool> visited(n * m, false);
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visited[i * m + j] && v[i][j] == 'L') {
				bfs(i, j, visited); res++;
			}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (v[i][j] == 'C')
				ids[idx(i, j)] = 0;

	int id = 0, N = 0, M = 0;
	for (auto &x : ids) { 
		x.second = id++;
		(x.first.first ? M : N)++;
	}
	bipartiteGraph g(N, M);
	for (auto &x : ids) {
		if (x.first.first) { break; }
		int i = x.first.second / m, j = x.first.second % m;
		if (ids.count(idx(i - 1, j))) { g.add_edge(x.second, ids[idx(i - 1, j)]); }
		if (ids.count(idx(i + 1, j))) { g.add_edge(x.second, ids[idx(i + 1, j)]); }
		if (ids.count(idx(i, j - 1))) { g.add_edge(x.second, ids[idx(i, j - 1)]); }
		if (ids.count(idx(i, j + 1))) { g.add_edge(x.second, ids[idx(i, j + 1)]); }
	}
	res += (N + M) - g.maxMatching(); cout << res << '\n';
	cin.ignore(2); return 0;
}