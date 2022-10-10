#include <bits/stdc++.h>
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
	vector<edge> edges; int m;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, ll w) {
		nodes[u].edges.emplace_back(u, v, w);
		edges.emplace_back(u, v, w);
	}

	ll bellman_ford(int src) {
		vector<ll> d(n, 1ll << 40); d[src] = 0ll;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			v.clear(); for (edge &e : edges)
				if (d[e.u] != (1ll << 40) && d[e.u] + e.w < d[e.v]) {
					v.push_back(e.v); d[e.v] = d[e.u] + e.w;
				}
		}
		vector<int> vis(n, false);
		for (auto &x : v) { vis[x] = true; }
		if (vis.back()) { return -1; }
		while (!v.empty()) {
			int cur = v.back(); v.pop_back();
			for (edge &e : nodes[cur].edges) {
				if (vis[e.v]) { continue; }
				if (e.v == n - 1) { vis[n - 1] = true; v.clear(); break; }
				v[e.v] = true; v.push_back(e.v);
			}
		}
		return vis[n - 1] ? -1ll : -d[n - 1];
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--; g.add_edge(u, v, -w);
	}
	cout << g.bellman_ford(0) << '\n';
}