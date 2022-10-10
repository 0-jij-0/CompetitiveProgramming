#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU {
	vector<int> rank, parent;
	DSU(int n) : rank(n, 1), parent(n) { iota(parent.begin(), parent.end(), 0); }
	int find(const int &u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) : u(_u), v(_v), w(_w) {}
	bool operator < (const edge &rhs) const { return w < rhs.w; }
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n = 0;
	vector<edge> edges; int m = 0;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, ll w) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
		edges.emplace_back(u, v, w); m++;
	}

	vector<edge> KruskalMST() {
		DSU dsu(n); vector<edge> res; sort(edges.begin(), edges.end());
		for (edge &e : edges) if (dsu.merge(e.u, e.v)) res.push_back(e);
		return ((int)res.size() == n - 1) ? move(res) : vector<edge>();
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		u--; v--; g.add_edge(u, v, c);
	}
	vector<edge> v = g.KruskalMST(); ll res = 0;
	for (auto &x : v) { res += x.w; }
	cout << (v.empty() ? "IMPOSSIBLE" : to_string(res)) << '\n'; 
}