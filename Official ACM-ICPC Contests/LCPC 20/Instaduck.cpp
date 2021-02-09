#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge& rhs) const {
		return w < rhs.w;
	}
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

	//Check if Cycle is reachable if given some destination (switch to vector)
	ll bellman_ford(int src, int dst) { //returns negative weight cycle
		vector<ll> d(n, 1ll << 50);
		int x; d[src] = 0;
		for (int i = 0; i < n; i++) {
			x = -1;	for (edge& e : edges)
				if (d[e.u] != 1ll << 50 && d[e.u] + e.w < d[e.v])
					d[x = e.v] = d[e.u] + e.w;
		}

		return (x != -1) ? 1ll << 60 : d[dst];
	}
};

int main() {
	freopen("insta.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; graph g(n + 2);
		for (int i = 0; i < m; i++) {
			int u, v, c; cin >> u >> v >> c;
			u--; v--; g.add_edge(u, v, c);
		}
		for (int i = 0; i < n; i++) {
			g.add_edge(n, i, 0);
			g.add_edge(i, n + 1, 0);
		}
		ll x = g.bellman_ford(n, n + 1);
		if (x == 0) { 
			x = 1 << 30; for (auto& e : g.edges)
				if(e.u != n && e.v != n + 1) 
					x = min(x, e.w);
		}
		if (x == 1ll << 60) { cout << "broken heart" << '\n'; }
		else { cout << x << '\n'; }
	}

	cin.ignore(2); return 0;
}