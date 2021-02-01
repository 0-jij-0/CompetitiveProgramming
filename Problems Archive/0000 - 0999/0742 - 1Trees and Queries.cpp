#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> depth;

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

	void dfs(int cur, int p) {
		for (auto &x : nodes[cur].edges) {
			if (x.v == p) { continue; }
			depth[x.v] = 1 + depth[cur];
			dfs(x.v, cur);
		}
	}
};

struct LCA {
	vector<int> pos, parent;
	vector<vector<int>> anc;
	int n, m;

	LCA(int root, graph &g) : n(g.n) {
		m = (int)ceil(log2(g.n + 0.0)) + 1;
		anc.resize(m + 1, vector<int>(n));
		parent.resize(n); pos.resize(n);

		queue<int> q; q.push(root);
		vector<bool> visited(g.n, false);
		visited[root] = true; parent[root] = root;
		pos[root] = 0;

		while (!q.empty()) {
			int f = q.front(); q.pop();
			node &cur = g.nodes[f];
			for (auto &e : cur.edges) {
				if (!visited[e.v]) {
					parent[e.v] = f; pos[e.v] = pos[f] + 1;
					q.push(e.v); visited[e.v] = true;
				}
			}
		}
		for (int i = 0; i < n; i++) { anc[0][i] = parent[i]; }
		for (int i = 1; i <= m; i++)
			for (int j = 0; j < n; j++)
				anc[i][j] = anc[i - 1][anc[i - 1][j]];
	}

	int find(int u, int v) {
		if (pos[u] < pos[v]) { swap(u, v); }
		int diff = pos[u] - pos[v], res = 0;

		for (int i = m; i >= 0; i--)
			if ((1 << i) <= diff) { u = anc[i][u]; diff -= 1 << i; }

		if (u == v) { return u; }
		for (int i = m; i >= 0; i--)
			if (anc[i][u] != anc[i][v]) { u = anc[i][u]; v = anc[i][v]; }

		int lca = parent[u]; return lca;
	}
};

int dist(int u, int v, int l) {
	return depth[u] + depth[v] - 2 * depth[l];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	depth.resize(n, 0); g.dfs(0, -1); LCA lca(0, g);
	int q; cin >> q;
	while (q--) {
		int x, y, a, b, k; cin >> x >> y >> a >> b >> k; x--; y--; a--; b--; 
		int distab = dist(a, b, lca.find(a, b));
		if (distab <= k && (k - distab) % 2 == 0) { cout << "YES" << '\n'; continue; }
		int distaxyb = dist(a, x, lca.find(a, x)) + 1 + dist(y, b, lca.find(y, b));
		if (distaxyb <= k && (k - distaxyb) % 2 == 0) { cout << "YES" << '\n'; continue; }
		int distayxb = dist(a, y, lca.find(a, y)) + 1 + dist(x, b, lca.find(x, b));
		if (distayxb <= k && (k - distayxb) % 2 == 0) { cout << "YES" << '\n'; continue; }
		cout << "NO" << '\n';
	}
	cin.ignore(2); return 0;
}