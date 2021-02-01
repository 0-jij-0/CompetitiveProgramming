#include <iostream>
#include <vector>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes[2]; 
	vector<edge> edges;
	int n, m;

	graph(int _n) : n(_n) { nodes[0].resize(n); nodes[1].resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v), e2(v, u);
		nodes[0][u].edges.push_back(e1);
		nodes[1][v].edges.push_back(e2);
		edges.push_back(e1);
	}

	void scc_dfs1(int v, vector<bool> &used, vector<int> &order) {
		used[v] = true;
		for (auto &x: nodes[0][v].edges)
			if (!used[x.v]) { scc_dfs1(x.v, used, order); }
		order.push_back(v);
	}

	void scc_dfs2(int v, vector<bool> &used, vector<int> &component) {
		used[v] = true;
		component.push_back(v);
		for (auto &x:nodes[1][v].edges)
			if (!used[x.v]) { scc_dfs2(x.v, used, component); }
	}

	vector<vector<int>> SCC() {
		vector<bool> used(n, false);
		vector<int> order, component;
		vector<vector<int>> scc;
		for (int i = 0; i < n; i++)
			if (!used[i]) { scc_dfs1(i, used, order); }
		used.assign(n, false);
		for (int i = 0; i < n; i++) {
			int v = order[n - 1 - i];
			if (!used[v]) {
				scc_dfs2(v, used, component);
				scc.push_back(component);
				component.clear();
			}
		}
		return move(scc);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, s; cin >> n >> m >> s;
	graph g(n); s--;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	vector<vector<int>> v = g.SCC(); int res = 0;
	vector<int> in(v.size(), 0), idx(n);
	for (int i = 0; i < (int)v.size(); i++) {
		for (auto &x : v[i]) { idx[x] = i; }
	}
	for (auto &x : g.edges) { 
		if (idx[x.u] != idx[x.v]) { in[idx[x.v]]++; }
	}
	for (auto &x : in) { if (!x) { res++; } }
	cout << res - (in[idx[s]] == 0) << endl;
	cin.ignore(2); return 0;
}