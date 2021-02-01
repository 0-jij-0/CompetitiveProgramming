#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge {
	int u, v;
	edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };
vector<node> graph;
vector<int> visited, res;
int n, m, k;

int bfs(int u, int t) {
	queue <int> q; q.push(u);
	visited[u] = t; int count = 0;

	while (!q.empty()) {
		int f = q.front(); q.pop(); node &n = graph[f];
		if (n.edges.empty()) { count++; }
		for (auto &e: n.edges) {
			int dest = e.v; 
			if (visited[dest] == -1) { 
				q.push(dest); node &adj = graph[dest];
				if (!adj.edges.empty()) { visited[dest] = t; }
			}
		}
	}
	return count;
}

void add_edge(int u, int v) {
	edge e1(u, v); graph[u].edges.push_back(e1);
}

void input(int n, int m) {
	vector<vector<char>> grid; grid.resize(n); 
	for (int i = 0; i < n; i++) { grid[i].resize(m); }
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char c; cin >> c; grid[i][j] = c;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == '.') {
				if (i != 0) { add_edge(i * m + j, (i - 1) * m + j); }
				if (i + 1 != n) { add_edge(i * m + j, (i + 1) * m + j); }
				if (j != 0) { add_edge(i * m + j, i * m + j - 1); }
				if (j + 1 != m) { add_edge(i * m + j, i * m + j + 1); }
			}
	grid.clear();
}

int main() {
	cin >> n >> m >> k; graph.resize(n * m); 
	visited.resize(n * m, -1); input(n, m);
	int t = 0;
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		int idx = (x - 1) * m + y - 1;
		if (visited[idx] != -1) { 
			cout << res[visited[idx]] << endl; continue;
		}
		res.push_back(bfs(idx, t)); t++;
		cout << res.back() << endl;
	}
	cin.ignore(2); return 0;
}

