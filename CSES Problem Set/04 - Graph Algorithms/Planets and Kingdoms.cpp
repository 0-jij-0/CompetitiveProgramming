#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes[2]; int n;
	graph(int _n) : n(_n) { nodes[0].resize(n); nodes[1].resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v), e2(v, u);
		nodes[0][u].edges.push_back(e1);
		nodes[1][v].edges.push_back(e2);
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

	bool dfs(int cur, int p, int dst, vector<bool> &vis) {
		vis[cur] = true; for (edge &e : nodes[0][cur].edges) {
			if (e.v == p || vis[e.v]) { continue; }
			if (e.v == dst) { return true; }
			if (dfs(e.v, cur, dst, vis)) { return true; }
		}
		return false;
	}

	vector<int> SCC(int &t) {
		vector<bool> used(n, false);
		vector<int> order, component, res(n);
		for (int i = 0; i < n; i++)
			if (!used[i]) { scc_dfs1(i, used, order); }
		used.assign(n, false);
		for (int i = 0; i < n; i++) {
			int v = order[n - 1 - i];
			if (!used[v]) {
				scc_dfs2(v, used, component);
				for (auto &x : component) { res[x] = t; }
				component.clear(); t++;
			}
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	int t = 1; vector<int> res = g.SCC(t);
	cout << t - 1 << '\n';
	for (auto &x : res) cout << x << ' '; cout << '\n'; 
}