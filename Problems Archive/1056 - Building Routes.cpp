#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
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

	bool bfs(int u, vector<int> &visited) {
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	vector<int> vis(n, 0), res;
	for (int i = 0; i < n; i++) if (g.bfs(i, vis)) res.push_back(i);
	cout << res.size() - 1 << '\n';
	for (int i = 1; i < (int)res.size(); i++)
		cout << res[i - 1] + 1 << ' ' << res[i] + 1 << '\n';
	cin.ignore(2); return 0;
}