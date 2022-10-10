#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}
};

struct RMQ {
	vector<vector<int>> rmq;
	vector<int> v, logb2; RMQ() {}
	RMQ(vector<int> &_v) : v(_v) { //O(nlogn) time and space
		int n = (int)v.size(); logb2.resize(n, 0);
		rmq.resize(1, vector<int>(n));
		iota(rmq[0].begin(), rmq[0].end(), 0);

		for (int i = 0; (1 << i) < n; i++) { logb2[1 << i] = i; } //Precomputing Logs
		for (int i = 1; i < n; i++) { logb2[i] = max(logb2[i], logb2[i - 1]); }
		rmq.resize(logb2.back() + 1);

		for (int t = 1; t < (int)rmq.size(); t++) {
			rmq[t].resize(n - (1 << t) + 1);
			for (int i = 0; i <= n - (1 << t); i++) {
				int x = v[rmq[t - 1][i]], y = v[rmq[t - 1][i + (1 << (t - 1))]];
				rmq[t][i] = x < y ? rmq[t - 1][i] : rmq[t - 1][i + (1 << (t - 1))];
			}
		}
	}

	int query(int i, int j) { //O(1)
		if (i > j) { swap(i, j); }
		int k = logb2[j - i + 1];
		int x = v[rmq[k][i]], y = v[rmq[k][j - (1 << k) + 1]];
		return x < y ? rmq[k][i] : rmq[k][j - (1 << k) + 1];
	}
};

struct ETT { //Euler Tour Technique
	vector<int> tree, start, finish, d, v; ETT() {}
	ETT(graph &g, int root) : d(g.n, 0), start(g.n), finish(g.n) {
		int t = 0; init(g, root, -1, t);
	}
	void init(graph &g, int cur, int p, int &t) {
		tree.push_back(cur); start[cur] = t++;
		v.push_back(d[cur]);
		for (edge &e : g.nodes[cur].edges) {
			if (e.v == p) { continue; }
			d[e.v] = 1 + d[cur];
			init(g, e.v, cur, t);
			tree.push_back(cur); t++;
			v.push_back(d[cur]);
		}
		finish[cur] = t - 1;
	}
};

struct LCA {
	ETT ett; RMQ rmq; LCA() {}
	LCA(graph &g, int root) : ett(g, root), rmq(ett.v) {}
	int find(int i, int j) { return ett.tree[rmq.query(ett.start[i], ett.start[j])]; }
	int dist(int i, int j) { return ett.d[i] + ett.d[j] - 2 * ett.d[find(i, j)]; }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q; graph g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	LCA lca(g, 0); while (q--) {
		int u, v; cin >> u >> v;
		cout << lca.dist(--u, --v) << '\n';
	}
}