#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef double ld;
const ld INF = 1e10;
const ld EPS = 1e-10;

struct Edge {
	int v, w; Edge() {}
	Edge(int _v, int _w) : v(_v), w(_w) {}
};

struct Graph {
	vector<vector<Edge>> nodes; int n;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v, int w) {
		nodes[u].emplace_back(v, w);
	}

	vector<int> longestPath(ld M) {
		vector<ld> dp(n, INF); dp[n - 1] = 0.0;
		vector<int> par(n, -1); par[n - 1] = 0;
		for (int i = n - 2; i >= 0; i--) for (auto& e : nodes[i]) {
			ld cur = (e.w - M) + dp[e.v];
			if (cur < dp[i]) { par[i] = e.v; dp[i] = cur; }
		}

		if (dp[0] > EPS) { return {}; }
		vector<int> path(1, 0);	while (par[path.back()]) 
			path.push_back(par[path.back()]);

		return path;
	}
};

vector<int> minAveragePath(Graph& G) {
	ld L = 0.0, R = 101.0;
	for (int i = 0; i < 50; i++) {
		ld M = (L + R) / 2.0;
		G.longestPath(M).empty() ? L = M : R = M;
	}
	return G.longestPath(R);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; Graph G(n);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		G.addEdge(--u, --v, w);
	}

	vector<int> path = minAveragePath(G);
	int P = (int)path.size();

	cout << P - 1 << '\n'; for (auto& x : path)
		cout << x + 1 << ' '; cout << '\n';
}