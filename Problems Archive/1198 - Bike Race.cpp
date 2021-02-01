#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 1 << 20;

struct edge {
	int u, v; int w; edge() {}
	edge(int _u, int _v, int _w = 1) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<vector<int>> D;
	graph(int _n) : n(_n), nodes(_n), D(n, vector<int>(n, INF)) {}

	void add_edge(int u, int v, ll w = 1) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
	}

	void allPairsShortestPath() {
		for (int i = 0; i < n; i++) { D[i][i] = 0; }
		for (auto &x : nodes) for (auto &y : x.edges) D[y.u][y.v] = y.w;

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (D[i][k] + D[k][j] < D[i][j])
						D[i][j] = D[i][k] + D[k][j];
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; graph g(n);
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			u--; v--; g.add_edge(u, v);
		}
		g.allPairsShortestPath(); int res = 0;
		for (int i = 0; i < n; i++)
			res = max(res, *max_element(g.D[i].begin(), g.D[i].end()));
		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}