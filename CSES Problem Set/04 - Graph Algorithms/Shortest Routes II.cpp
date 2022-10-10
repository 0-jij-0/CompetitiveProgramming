#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<vector<ll>> D;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, ll w) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
	}

	void allPairsShortestPath() {
		int n = nodes.size(); D.resize(n, vector<ll>(n, INF));
		for (int i = 0; i < n; i++) { D[i][i] = 0; }
		for (auto &x : nodes) for (auto &y : x.edges) D[y.u][y.v] = min(D[y.u][y.v], y.w);

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, q; cin >> n >> m >> q; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--; g.add_edge(u, v, w);
	}
	g.allPairsShortestPath(); while (q--) {
		int u, v; cin >> u >> v;
		cout << (g.D[--u][--v] == INF ? -1 : g.D[u][v]) << endl;
	}
	cin.ignore(2); return 0;
}