#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
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
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	bool dfs(int cur, vector<int> &vis, vector<int> &col) {
		int newCol = (col[cur] + 1) & 1;
		for (edge &e : nodes[cur].edges) {
			if (vis[e.v] && col[cur] == col[e.v]) { return false; }
			if (vis[e.v]) { continue; }
			col[e.v] = newCol; vis[e.v] = true;
			if (!dfs(e.v, vis, col)) { return false; }
		}
		return true;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	vector<int> team(n, 0), vis(n, 0); bool ok = true;
	for (int i = 0; i < n; i++) if (!vis[i] && !g.dfs(i, vis, team)) { ok = false; break; }
	if (!ok) { cout << "IMPOSSIBLE" << '\n'; return 0; }
	for (auto &x : team) { cout << 1 + x << ' '; }
	cout << '\n'; cin.ignore(2); return 0;
}