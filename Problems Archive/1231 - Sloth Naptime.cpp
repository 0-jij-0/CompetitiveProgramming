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

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
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
			if ((1 << i) <= diff) {
				u = anc[i][u]; diff -= 1 << i;
			}

		if (u == v) { return u; }
		for (int i = m; i >= 0; i--)
			if (anc[i][u] != anc[i][v]) {
				u = anc[i][u]; v = anc[i][v];
			}
		int lca = anc[0][u]; return lca;
	}
	int dist(int i, int j) { return pos[i] + pos[j] - 2 * pos[find(i, j)]; }

	int kthParent(int u, int k) {
		for (int i = m; i >= 0; i--)
			if ((1 << i) & k) u = anc[i][u];
		return u;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	int q; cin >> q; LCA lca(0, g);
	while (q--) {
		int a, b, c; cin >> a >> b >> c;
		int l = lca.find(--a, --b), dla = lca.dist(a, l);
		if (c <= dla) { cout << lca.kthParent(a, c) + 1 << '\n'; continue; }
		int dlb = lca.dist(b, l); c -= dla;
		if (c < dlb) { cout << lca.kthParent(b, dlb - c) + 1 << '\n'; continue; }
		cout << b + 1 << '\n';
	}

	cin.ignore(2); return 0;
}