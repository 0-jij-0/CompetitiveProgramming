#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
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

	void dfs(int u) {
		vector<bool> visited(n, false);
		stack<int> s; s.push(u);
		visited[u] = true; depth[u] = 0;
		while (!s.empty()) {
			int f = s.top(); s.pop();
			node& n = nodes[f];
			for (auto &x : n.edges) {
				int dest = x.v;
				if (visited[dest] == false) {
					s.push(dest); visited[dest] = true;
					depth[dest] = depth[x.u] + 1;
				}
			}
		}
	}
};

struct LCA {
	vector<int> pos;
	vector<int> parent;
	vector<vector<int>> anc;
	int n, m;

	LCA(int root, graph &g) : n(g.n) {
		m = (int)ceil(log2(g.n + 0.0)) + 1;
		anc.resize(m + 1, vector<int>(n));
		parent.resize(n); pos.resize(n);

		queue<int> q; q.push(root);
		vector<bool> visited(g.n, false);
		visited[root] = true; parent[root] = { root };
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
			if ((1 << i) <= diff) {	u = anc[i][u]; diff -= 1 << i; }

		if (u == v) { return u; }
		for (int i = m; i >= 0; i--)
			if (anc[i][u] != anc[i][v]) {u = anc[i][u]; v = anc[i][v]; }
		int lca = parent[u];
		return lca;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}

	LCA lca(0, g); depth.resize(n); g.dfs(0);
	while(m--) {
		int k; cin >> k;
		int idx = 0, d = -1;
		vector<int> v;
		for (int i = 0; i < k; i++) {
			int u; cin >> u; u--; v.push_back(u);
			if (depth[u] > d) { idx = u; d = depth[u]; }
		}
		bool check = true;
		for (int i = 0; i < k; i++) {
			if (v[i] == idx) { continue; }
			int l = lca.find(v[i], idx);
			if (l == v[i] || lca.parent[v[i]] == l) { continue; }
			check = false; break;
		}
		cout << (check ? "YES" : "NO") << endl;
	}

	cin.ignore(2); return 0;
}