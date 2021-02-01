#include <iostream>
#include <vector>
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
	vector<vector<int>> helper;
	graph(int _n) : n(_n), nodes(_n), helper(n, vector<int>(n, -1)) {}

	void add_edge(int u, int v, ll w) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
	}

	void allPairsShortestPath() {
		int n = nodes.size(); D.resize(n, vector<ll>(n, INF));
		for (int i = 0; i < n; i++) { D[i][i] = 0; }
		for (auto &x : nodes) for (auto &y : x.edges) D[y.u][y.v] = y.w;

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (D[i][k] + D[k][j] < D[i][j])
						D[i][j] = D[i][helper[i][j] = k] + D[k][j];
	}

	void APSP_printPath(int s, int d) {
		if (s == d) { cout << s << ' '; return; }
		APSP_printPath(s, helper[s][d]);
		APSP_printPath(helper[s][d], d);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin.ignore(2); return 0;
}