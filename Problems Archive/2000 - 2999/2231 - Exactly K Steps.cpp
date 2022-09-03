#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <tuple>
#include <cmath>
using namespace std;

struct Tree {
	vector<vector<int>> nodes; int n;
	Tree(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	void BFS(int src, vector<int>& par, vector<int>& depth) {
		queue<int> Q; Q.push(src);
		depth[src] = 0;	par[src] = src;

		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (auto& e : nodes[cur]) if (par[e] == -1) {
				par[e] = cur; depth[e] = depth[cur] + 1; Q.push(e);
			}
		}
	}

	int diameterBFS(int u) {
		queue<int> q; q.push(u);
		vector<bool> vis(n, false);
		vis[u] = true; int cur = u;
		while (!q.empty()) {
			cur = q.front(); q.pop();
			for (int& e : nodes[cur]) {
				if (vis[e]) { continue; }
				q.push(e); vis[e] = true;
			}
		}
		return cur;
	}

	pair<int, int> getDiameter() {
		int A = diameterBFS(0), B = diameterBFS(A);
		return { A, B };
	}
};

struct LCA {
	vector<int> depth; int n, m;
	vector<vector<int>> anc;

	LCA(int root, Tree& T) : n(T.n), depth(T.n) {
		m = (int)ceil(log2(T.n + 0.0)) + 1;
		anc.resize(m + 1, vector<int>(n, -1));

		T.BFS(root, anc[0], depth);
		for (int i = 1; i <= m; i++)
			for (int j = 0; j < n; j++)
				anc[i][j] = anc[i - 1][anc[i - 1][j]];
	}

	int kthAncestor(int cur, int k) {
		for(int i = m; i>= 0; i--)
			if ((1 << i) & k) { cur = anc[i][cur]; }
		return cur;
	}

	int find(int u, int v) {
		if (depth[u] < depth[v]) { swap(u, v); }
		int diff = depth[u] - depth[v];

		for (int i = m; i >= 0; i--)
			if ((1 << i) <= diff) {
				u = anc[i][u]; diff -= 1 << i;
			}

		if (u == v) { return u; }
		for (int i = m; i >= 0; i--)
			if (anc[i][u] != anc[i][v]) {
				u = anc[i][u]; v = anc[i][v];
			}
		return anc[0][u];
	}

	int dist(int i, int j) { return depth[i] + depth[j] - 2 * depth[find(i, j)]; }
};

int getNode(int U, int V, int K, LCA& lca) {
	int L = lca.find(U, V);
	int UV = lca.depth[U] + lca.depth[V] - 2 * lca.depth[L];
	if (UV < K) { return -1; }

	int UL = lca.depth[U] - lca.depth[L];
	if (UL >= K) { return 1 + lca.kthAncestor(U, K); }

	int VL = UV - UL;
	return 1 + lca.kthAncestor(V, VL - (K - UL));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; Tree T(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		T.addEdge(--u, --v);
	}
	int A, B; tie(A, B) = T.getDiameter();

	LCA lca(0, T); int q; cin >> q; while (q--) {
		int u, k; cin >> u >> k; --u;
		int a = getNode(u, A, k, lca), b = getNode(u, B, k, lca);
		cout << max(a, b) << '\n';
	}
}