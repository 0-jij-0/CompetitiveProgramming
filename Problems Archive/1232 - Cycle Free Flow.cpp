#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, int w) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
	}
};

struct LCA {
	vector<int> pos; int n, m;
	vector<vector<int>> anc;
	vector<vector<int>> light;

	LCA(int root, graph &g) : n(g.n), pos(g.n) {
		m = (int)ceil(log2(g.n + 0.0)) + 1;
		anc.resize(m + 1, vector<int>(n));
		light.resize(m + 1, vector<int>(n));

		queue<int> q; q.push(root);
		vector<bool> visited(g.n, false);
		visited[root] = true; pos[root] = 0;
		anc[0][root] = root; light[0][root] = 1 << 30;

		while (!q.empty()) {
			int f = q.front(); q.pop();
			for (auto &e : g.nodes[f].edges)
				if (!visited[e.v]) {
					anc[0][e.v] = f; light[0][e.v] = e.w;
					pos[e.v] = pos[f] + 1; q.push(e.v);
					visited[e.v] = true;
				}
		}
		for (int i = 1; i <= m; i++)
			for (int j = 0; j < n; j++) {
				anc[i][j] = anc[i - 1][anc[i - 1][j]];
				light[i][j] = min(light[i - 1][j], light[i - 1][anc[i - 1][j]]);
			}
	}

	int find(int u, int v) {
		if (pos[u] < pos[v]) { swap(u, v); }
		int diff = pos[u] - pos[v]; int res = 1 << 30;

		for (int i = m; i >= 0; i--)
			if ((1 << i) <= diff) {
				res = min(res, light[i][u]);
				u = anc[i][u]; diff -= 1 << i;
			}

		if (u == v) { return res; }
		for (int i = m; i >= 0; i--)
			if (anc[i][u] != anc[i][v]) {
				res = min(res, min(light[i][u], light[i][v]));
				u = anc[i][u]; v = anc[i][v];
			}
		int w = min(res, min(light[0][u], light[0][v]));
		return w;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--; g.add_edge(u, v, w);
	}
	int q; cin >> q; LCA lca(0, g);
	while (q--) {
		int u, v; cin >> u >> v;
		cout << lca.find(--u, --v) << '\n';
	}
	cin.ignore(2); return 0;
}