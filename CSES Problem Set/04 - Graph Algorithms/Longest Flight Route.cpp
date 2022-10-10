#include <bits/stdc++.h>
using namespace std;

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
		nodes[u].edges.emplace_back(u, v);
	}

	int longestPath(int cur, vector<int> &lp) {
		if (lp[cur]) return lp[cur];
		int res = -(1 << 20); for (edge &e : nodes[cur].edges)
			res = max(res, 1 + longestPath(e.v, lp));
		return lp[cur] = res;
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
	vector<int> lp(n, 0); lp.back() = 1;
	for (int i = 0; i < n; i++) g.longestPath(i, lp);
	if (lp[0] < 0) { cout << "IMPOSSIBLE\n"; return 0; }
	int i = 0; cout << lp[0] << '\n';
	while (lp[i] != 1) {
		cout << i + 1 << ' ';
		for (edge &e : g.nodes[i].edges)
			if (lp[e.v] == lp[i] - 1) { i = e.v; break; }
	}
	cout << i + 1 << '\n';
}