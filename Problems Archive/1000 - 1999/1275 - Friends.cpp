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

	int bfs(int u, vector<bool> &visited) {
		queue<int> q; q.push(u);
		visited[u] = true; int res = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop(); res++;
			for (edge &e : nodes[cur].edges) {
				if (visited[e.v]) { continue; }
				q.push(e.v); visited[e.v] = true;
			}
		}
		return res;
	}
};

int main() {
	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	vector<bool> vis(n, false); int res = 0;
	for (int i = 0; i < n; i++) if (!vis[i])
		res = max(res, g.bfs(i, vis));
	cout << res << '\n';
	cin.ignore(2); return 0;
}