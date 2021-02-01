#include <iostream>
#include <vector>
#include <algorithm>
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
		edges.emplace_back(u, v, w);
	}

	//Check if Cycle is reachable if given some destination (switch to vector)
	vector<int> bellman_ford(int src) { //returns negative weight cycle
		vector<ll> d(n, 1ll << 60); vector<int> parent(n, -1);
		int x; d[src] = 0;
		for (int i = 0; i < n; i++) {
			x = -1;	for (edge &e : edges)
				if (d[e.u] != 1ll << 60 && d[e.u] + e.w < d[e.v])
					d[x = e.v] = d[parent[e.v] = e.u] + e.w;
		}

		if (x == -1) { return vector<int>(); }

		vector<int> cycle;
		for (int i = 0; i < n; i++) x = parent[x];
		for (int v = x; ; v = parent[v]) {
			cycle.push_back(v);
			if (v == x && cycle.size() > 1) { break; }
		}
		reverse(cycle.begin(), cycle.end());
		return move(cycle);
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
	for (int i = 1; i < n; i++) g.add_edge(0, i, 1ll << 50);
	vector<int> cycle = g.bellman_ford(0);
	if (cycle.empty()) { cout << "NO" << '\n'; return 0; }
	cout << "YES" << endl;
	for (auto &x : cycle) cout << x + 1 << ' '; cout << '\n';
	cin.ignore(2); return 0;
}