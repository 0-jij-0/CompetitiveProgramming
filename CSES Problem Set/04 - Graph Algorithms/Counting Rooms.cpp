#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v), e2(v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	bool bfs(int u, vector<bool> &visited) {
		if (visited[u]) { return false; }
		queue<int> q; q.push(u); visited[u] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (edge &e : nodes[cur].edges) {
				if (visited[e.v]) { continue; }
				q.push(e.v); visited[e.v] = true;
			}
		}
		return true;
	}
};

vector<string> v; int n, m;
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

void connect(graph &g, int i, int j, int u, int v) {
	if (u < 0 || u > n - 1) { return; }
	if (v < 0 || v > m - 1) { return; }
	g.add_edge(i * m + j, u * m + v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m; v.resize(n); graph g(n * m);
	for (auto &x : v) { cin >> x; }
	vector<bool> visited(n * m, false);
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '#') { visited[i * m + j] = true; continue; }
			for (int k = 0; k < 2; k++) connect(g, i, j, i + dx[k], j + dy[k]);
		}
	int res = 0; for (int i = 0; i < n * m; i++) { res += g.bfs(i, visited); }
	cout << res << '\n';
}