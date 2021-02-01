#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

struct DSU {
	vector<int> rank, parent;
	DSU(int n) {
		rank.resize(n, 1); parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}
	int find(const int u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge &rhs) const { return w < rhs.w; }
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n = 0;
	vector<edge> edges; int m = 0;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, int w) {
		edge e1(u, v, w), e2(v, u, w);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
		edges.push_back(e1); m++;
	}

	graph KruskalMST() {
		sort(edges.begin(), edges.end());
		DSU dsu(n); graph g(n); int i = 0;
		while (i < m && g.edges.size() != n - 1) {
			edge &e = edges[i];
			if (!dsu.merge(e.u, e.v)) { i++; continue; }
			g.add_edge(e.u, e.v, e.w); i++;
		}
		return move(g);
	}
};

struct LCA {
	vector<int> pos;
	vector<pair<int, int>> parent;
	vector<vector<int>> anc, heavy;
	int n, m;

	LCA(int root, graph &g) : n(g.n) {
		m = (int)ceil(log2(g.n + 0.0)) + 1;
		anc.resize(m + 1, vector<int>(n));
		heavy.resize(m + 1, vector<int>(n));
		parent.resize(n); pos.resize(n);

		queue<int> q; q.push(root);
		vector<bool> visited(g.n, false);
		visited[root] = true; parent[root] = { root, -1 };
		pos[root] = 0;

		while (!q.empty()) {
			int f = q.front(); q.pop();
			node &cur = g.nodes[f];
			for (auto &e : cur.edges) {
				if (!visited[e.v]) {
					parent[e.v] = { f, e.w }; pos[e.v] = pos[f] + 1;
					q.push(e.v); visited[e.v] = true;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			anc[0][i] = parent[i].first;
			heavy[0][i] = parent[i].second;
		}
		for (int i = 1; i <= m; i++)
			for (int j = 0; j < n; j++) {
				anc[i][j] = anc[i - 1][anc[i - 1][j]];
				heavy[i][j] = max(heavy[i - 1][j], heavy[i - 1][anc[i - 1][j]]);
			}
	}

	pair<int, int> find(int u, int v) {
		if (pos[u] < pos[v]) { swap(u, v); }
		int diff = pos[u] - pos[v], res = 0;

		for (int i = m; i >= 0; i--)
			if ((1 << i) <= diff) {
				res = max(res, heavy[i][u]);
				u = anc[i][u]; diff -= 1 << i;
			}

		if (u == v) { return { u, res }; }
		for (int i = m; i >= 0; i--)
			if (anc[i][u] != anc[i][v]) {
				res = max(res, max(heavy[i][u], heavy[i][v]));
				u = anc[i][u]; v = anc[i][v];
			}
		int lca = parent[u].first;
		int w = max(res, max(parent[u].second, parent[v].second));
		return { lca, w };
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
	vector<edge> v = g.edges;
	g = g.KruskalMST(); LCA lca(0, g);

	for (auto &e : v) {
		int x = lca.find(e.u, e.v).second;
		if (x != e.w) { cout << x << endl; }
	}
	cin.ignore(2); return 0;
}