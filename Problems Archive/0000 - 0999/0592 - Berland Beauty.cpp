#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

struct edge {
	int idx, u, v; edge() {}
	edge(int _idx, int _u, int _v) :
		idx(_idx), u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int idx, int u, int v) {
		edge e1(idx, u, v), e2(idx, v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}
};

vector<int> res;
vector<pair<int, int>> p;
vector<pair<int, pair<int, int>>> queries;

void dfs(graph &g, int r, vector<bool> &visited) {
	for(auto &e : g.nodes[r].edges)
		if (!visited[e.v]) {
			visited[e.v] = true;
			p[e.v] = { r, e.idx };
			dfs(g, e.v, visited);
		}			
}

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
		for (int i = 0; i < n; i++)
			anc[0][i] = parent[i];
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
		int lca = parent[u]; return lca;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n; graph g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(i, u, v);
	}
	vector<bool> visited(n, false); visited[0] = true;
	LCA lca(0, g); p.resize(n); dfs(g, 0, visited);
	res.resize(n - 1, 1);
	int m; cin >> m; bool check = true;
	for (int i = 0; i < m; i++) {
		int a, b, g; cin >> a >> b >> g;
		queries.push_back({ g, {a - 1, b - 1} });
	}
	sort(queries.rbegin(), queries.rend());
	for (int i = 0; i < m; i++) {
		int a = queries[i].second.first;
		int b = queries[i].second.second;
		int g = queries[i].first;
		int l = lca.find(a, b);	bool c = false;
		while (a != l) {
			if (g < res[p[a].second]) { a = p[a].first; continue; }
			res[p[a].second] = g; a = p[a].first; c = true;
		}
		while (b != l) {
			if (g < res[p[b].second]) { b = p[b].first; continue; }
			res[p[b].second] = g; b = p[b].first; c = true;
		}
		if (!c) { check = false; break; }
	}
	if (!check) { cout << -1 << endl; cin.ignore(2); return 0; }
	for (auto &x : res) { cout << x << ' '; }
	cout << endl; cin.ignore(2); return 0;
}