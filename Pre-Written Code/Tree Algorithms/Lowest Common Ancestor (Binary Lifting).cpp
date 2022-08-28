#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

struct Edge {
	int u, v; ll w; Edge() {}
	Edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct Tree {
	vector<vector<Edge>> nodes; int n;
	Tree(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v, ll w) {
		nodes[u].emplace_back(u, v, w);
		nodes[v].emplace_back(v, u, w);
	}

	void BFS(int src, vector<int>& par, vector<ll> & weight, vector<int>& depth) {
		queue<int> Q; Q.push(src);
		depth[src] = 0;	par[src] = src; weight[src] = -1;

		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (auto& e : nodes[cur]) if (par[e.v] == -1) {
				par[e.v] = cur; weight[e.v] = e.w;
				depth[e.v] = depth[cur] + 1; Q.push(e.v); 
			}
		}
	}
};

struct LCA {
	vector<int> depth; int n, m;
	vector<vector<int>> anc;
	vector<vector<ll>> heavy;

	LCA(int root, Tree &T) : n(T.n), depth(T.n) {
		m = (int)ceil(log2(T.n + 0.0)) + 1;
		anc.resize(m + 1, vector<int>(n, -1));
		heavy.resize(m + 1, vector<ll>(n));

		T.BFS(root, anc[0], heavy[0], depth);
		for (int i = 1; i <= m; i++)
			for (int j = 0; j < n; j++) {
				anc[i][j] = anc[i - 1][anc[i - 1][j]];
				heavy[i][j] = max(heavy[i - 1][j], heavy[i - 1][anc[i - 1][j]]);
			}
	}

	pair<int, ll> find(int u, int v) {
		if (depth[u] < depth[v]) { swap(u, v); }
		int diff = depth[u] - depth[v]; ll res = 0;

		for (int i = m; i >= 0; i--)
			if ((1 << i) <= diff) {
				res = max(res, heavy[i][u]);
				u = anc[i][u]; diff -= 1 << i;
			}

		if (u == v) { return { u, res }; }
		for (int i = m; i >= 0; i--)
			if (anc[i][u] != anc[i][v]) {
				res = max(res, max(heavy[i][u], heavy[i][v]));
				u = anc[i][u]; v = anc[i][v];
			}
		int lca = anc[0][u];
		ll w = max(res, max(heavy[0][u], heavy[0][v]));
		return { lca, w };
	}

	int dist(int i, int j) { return depth[i] + depth[j] - 2 * depth[find(i, j).first]; }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}