#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { int s = 0; vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	int dfs(int cur, int p) {
		for (edge &e : nodes[cur].edges) if(e.v != p)
			nodes[cur].s += dfs(e.v, cur);
		return nodes[cur].s;
	}
};

struct LCA {
	vector<int> pos; int n, m;
	vector<vector<int>> anc;

	LCA(int root, graph &g) : n(g.n), pos(g.n) {
		m = (int)ceil(log2(g.n + 0.0)) + 1;
		anc.resize(m + 1, vector<int>(n));

		queue<int> q; q.push(root);
		vector<bool> visited(g.n, false);
		visited[root] = true; pos[root] = 0;
		anc[0][root] = root;

		while (!q.empty()) {
			int f = q.front(); q.pop();
			for (auto &e : g.nodes[f].edges)
				if (!visited[e.v]) {
					anc[0][e.v] = f; pos[e.v] = pos[f] + 1; 
					q.push(e.v); visited[e.v] = true;
				}
		}
		for (int i = 1; i <= m; i++)
			for (int j = 0; j < n; j++) 
				anc[i][j] = anc[i - 1][anc[i - 1][j]];
	}

	int find(int u, int v) {
		if (pos[u] < pos[v]) { swap(u, v); }
		int diff = pos[u] - pos[v];

		for (int i = m; i >= 0; i--)
			if ((1 << i) <= diff) { u = anc[i][u]; diff -= 1 << i; }

		if (u == v) { return u; }
		for (int i = m; i >= 0; i--)
			if (anc[i][u] != anc[i][v]) { u = anc[i][u]; v = anc[i][v]; }
		int lca = anc[0][u]; return lca;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	LCA lca(0, g); while (m--) {
		int a, b, l; cin >> a >> b; l = lca.find(--a, --b);
		g.nodes[a].s++; g.nodes[b].s++; g.nodes[l].s--; 
		if(l != 0) g.nodes[lca.anc[0][l]].s--;
	} g.dfs(0, -1);
	for (int i = 0; i < n; i++)
		cout << g.nodes[i].s << ' ';

	cout << '\n'; cin.ignore(2); return 0;
}