#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes[2]; int n;
	vector<edge> edges;
	graph(int _n) : n(_n) { nodes[0].resize(n); nodes[1].resize(n); }

	void add_edge(int u, int v) {
		if (u == v) { return; }
		edge e1(u, v), e2(v, u);
		nodes[0][u].edges.push_back(e1);
		nodes[1][v].edges.push_back(e2);
		edges.push_back(e1);
	}

	void scc_dfs1(int v, vector<bool> &used, vector<int> &order) {
		used[v] = true;
		for (auto &x : nodes[0][v].edges)
			if (!used[x.v]) { scc_dfs1(x.v, used, order); }
		order.push_back(v);
	}

	void scc_dfs2(int v, vector<bool> &used, vector<int> &component) {
		used[v] = true;
		component.push_back(v);
		for (auto &x : nodes[1][v].edges)
			if (!used[x.v]) { scc_dfs2(x.v, used, component); }
	}

	vector<int> SCC(int &t) {
		vector<bool> used(n, false);
		vector<int> order, component, scc(n);
		for (int i = 0; i < n; i++)
			if (!used[i]) { scc_dfs1(i, used, order); }
		used.assign(n, false);
		for (int i = 0; i < n; i++) {
			int v = order[n - 1 - i];
			if (!used[v]) {
				scc_dfs2(v, used, component);
				for (auto &x : component) { scc[x] = t; }
				component.clear(); t++;
			}
		}
		return move(scc);
	}
};

vector<ll> c, C, lp;

ll longestPath(graph &g, int i) {
	if (lp[i]) { return lp[i]; }
	ll res = C[i]; for (edge &e : g.nodes[0][i].edges)
		res = max(res, C[i] + longestPath(g, e.v));
	return lp[i] = res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; 
	c.resize(n); graph g(n);
	for (auto &x : c) { cin >> x; }
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	int t = 0; vector<int> scc = g.SCC(t);
	graph G(t); C.resize(t); lp.resize(t, 0);
	for (edge &e : g.edges)	G.add_edge(scc[e.u], scc[e.v]);
	for (int i = 0; i < n; i++) C[scc[i]] += c[i];
	for (int i = 0; i < t; i++) longestPath(G, i);
	cout << *max_element(lp.begin(), lp.end()) << '\n';
}