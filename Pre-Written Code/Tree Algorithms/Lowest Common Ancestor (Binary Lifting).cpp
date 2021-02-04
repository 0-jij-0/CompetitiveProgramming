#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, ll w) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
	}
};

struct LCA {
	vector<int> pos; int n, m;
	vector<vector<int>> anc;
	vector<vector<ll>> heavy;

	LCA(int root, graph &g) : n(g.n), pos(g.n) {
		m = (int)ceil(log2(g.n + 0.0)) + 1;
		anc.resize(m + 1, vector<int>(n));
		heavy.resize(m + 1, vector<ll>(n));

		queue<int> q; q.push(root);
		vector<bool> visited(g.n, false);
		visited[root] = true; pos[root] = 0;
		anc[0][root] = root; heavy[0][root] = -1;

		while (!q.empty()) {
			int f = q.front(); q.pop();
			for (auto &e : g.nodes[f].edges) 
				if (!visited[e.v]) {
					anc[0][e.v] = f; heavy[0][e.v] = e.w;
					pos[e.v] = pos[f] + 1; q.push(e.v);
					visited[e.v] = true;
				}
		}
		for (int i = 1; i <= m; i++)
			for (int j = 0; j < n; j++) {
				anc[i][j] = anc[i - 1][anc[i - 1][j]];
				heavy[i][j] = max(heavy[i - 1][j], heavy[i - 1][anc[i - 1][j]]);
			}
	}

	pair<int, ll> find(int u, int v) {
		if (pos[u] < pos[v]) { swap(u, v); }
		int diff = pos[u] - pos[v]; ll res = 0;

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
		int lca = anc[0][u];
		ll w = max(res, max(heavy[0][u], heavy[0][v]));
		return { lca, w };
	}
	int dist(int i, int j) { return pos[i] + pos[j] - 2 * pos[find(i, j).first]; }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin.ignore(2); return 0;
}