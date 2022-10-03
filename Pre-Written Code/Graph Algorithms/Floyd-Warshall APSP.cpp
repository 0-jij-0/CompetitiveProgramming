#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

struct Edge {
	int u, v; ll w; Edge() {}
	Edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct Graph {
	vector<vector<Edge>> nodes; int n;
	vector<vector<ll>> D;
	vector<vector<int>> lastRelax;
	Graph(int _n) : n(_n), nodes(_n), lastRelax(n, vector<int>(n, -1)) {}

	void addEdge(int u, int v, ll w) {
		nodes[u].emplace_back(u, v, w);
		nodes[v].emplace_back(v, u, w);
	}

	void allPairsShortestPath() {
		int n = nodes.size(); D.resize(n, vector<ll>(n, INF));
		for (int i = 0; i < n; i++) { D[i][i] = 0; }
		for (auto &x : nodes) for (auto &y : x) D[y.u][y.v] = y.w;

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (D[i][k] + D[k][j] < D[i][j])
						D[i][j] = D[i][lastRelax[i][j] = k] + D[k][j];
	}

	void printPath(int s, int d) {
		if (s == d) { cout << s << ' '; return; }
		printPath(s, lastRelax[s][d]);
		printPath(lastRelax[s][d], d);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}