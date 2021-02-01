#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <set>
using namespace std;

vector<int> c, res;

struct DSU {
	vector<int> parent;
	vector<set<int>> colors;

	DSU(int n) : parent(n), colors(n) {
		iota(parent.begin(), parent.end(), 0);
		for (int i = 0; i < n; i++)	colors[i].insert(c[i]);
	}

	int find(const int &u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(int u) { return colors[find(u)].size(); }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (size(u) < size(v)) { swap(u, v); }
		for (auto &x : colors[v]) { colors[u].insert(x); }
		parent[v] = u; colors[v].clear(); return true;
	}
};

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
		nodes[v].edges.emplace_back(v, u);
	}

	void dfs(int cur, int p, DSU &dsu) {
		for (edge &e : nodes[cur].edges) {
			if (e.v == p) { continue; }
			dfs(e.v, cur, dsu); dsu.merge(cur, e.v);
		}
		res[cur] = dsu.size(cur);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n); 
	c.resize(n); res.resize(n);
	for (auto &x : c) { cin >> x; }
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	DSU dsu(n); g.dfs(0, -1, dsu);
	for (auto &x : res) cout << x << ' ';
	cout << '\n'; cin.ignore(2); return 0;
}