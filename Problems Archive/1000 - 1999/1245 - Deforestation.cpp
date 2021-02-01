#include <iostream>
#include <vector>
#include <queue>
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

	bool bfs() {
		queue<int> q; q.push(0); vector<bool> visited(n, false);
		vector<int> order, par(n), val(n, 0); visited[0] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop(); order.push_back(cur);
			for (edge &e : nodes[cur].edges) {
				if (visited[e.v]) { continue; }
				par[e.v] = cur; q.push(e.v); visited[e.v] = true;
			}
		}
		for (int i = n - 1; i > 0; i--) {
			int res = 0; for (edge &e : nodes[order[i]].edges)
				if (e.v != par[order[i]]) res ^= val[e.v];
			val[order[i]] = 1 + res;
		}
		int res = 0; 
		for (edge &e : nodes[0].edges) res ^= val[e.v];
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; graph g(n);
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			u--; v--; g.add_edge(u, v);
		}
		cout << (g.bfs() ? "Alice" : "Bob") << '\n';
	}

	cin.ignore(2); return 0;
}