#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
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

	int dfs(int cur, int p, vector<int> &col, vector<int> &par) {
		col[cur] = 1;
		for (edge &e : nodes[cur].edges) {
			if (e.v == cur || col[e.v] == 2) { continue; }
			if (col[e.v] == 1) { return par[e.v] = cur; }
			par[e.v] = cur; int x = dfs(e.v, cur, col, par);
			if (x != -1) { return x; }
		}
		col[cur] = 2; return -1;
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
	vector<int> col(n, 0), par(n, -1); int x = -1;
	for (int i = 0; i < n; i++) if (!col[i])
		if (x = g.dfs(i, -1, col, par), x != -1) { break; }

	if (x == -1) { cout << "IMPOSSIBLE" << '\n'; return 0; }
	vector<int> res(1, x); int y = par[x];
	while (y != x) { res.push_back(y); y = par[y]; }
	res.push_back(x); cout << res.size() << endl;
	reverse(res.begin(), res.end());
	for (auto &x : res) { cout << x + 1 << ' '; }
	cout << '\n'; cin.ignore(2); return 0;
}