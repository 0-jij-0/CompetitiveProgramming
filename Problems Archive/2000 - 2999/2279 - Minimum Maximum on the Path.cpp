#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

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

	vector<int> bfs(int d, int M) {
		queue<int> q; q.push(0);
		vector<int> par(n, -1); par[0] = 0;
		vector<int> dist(n, -1); dist[0] = 0;

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto& e : nodes[cur]) 
				if(par[e.v] == -1 && e.w <= M) {
					q.push(e.v); par[e.v] = cur;
					dist[e.v] = 1 + dist[cur]; 
				}
		}
		
		if (dist[n - 1] > d || dist[n - 1] == -1) { return {}; }

		vector<int> res(1, n - 1);
		while (res.back()) { res.push_back(par[res.back()]); }
		return res;
	}
};

vector<int> minMaxEdgePath(Graph &G, int d) {
	int L = 0, R = 1 << 30;
	while (L != R) {
		int M = (L + R) >> 1;
		G.bfs(d, M).empty() ? L = M + 1 : R = M;
	}
	vector<int> res = G.bfs(d, L);
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, d; cin >> n >> m >> d; Graph G(n);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		G.addEdge(--u, --v, w);
	}

	vector<int> path = minMaxEdgePath(G, d);
	int P = (int)path.size();

	if (!P) { cout << "-1\n"; return 0; }
	cout << P - 1 << '\n'; for (auto& x : path)
		cout << x + 1 << ' '; cout << '\n';
}