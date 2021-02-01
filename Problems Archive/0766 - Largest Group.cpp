#include <iostream>
#include <vector>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node { vector<edge> edges; node() {} };

struct bipartiteGraph {
	vector<node> nodes; int n, m;
	vector<int> match; vector<bool> vis;

	bipartiteGraph(int _n, int _m) : n(_n), m(_m) {
		nodes.resize(n + m); 
		match.resize(n + m, -1); 
		vis.resize(n + m, 0);
	}

	void add_edge(int u, int v) {
		nodes[u].edges.push_back(edge(u, v));
		nodes[v].edges.push_back(edge(v, u));
	}

	bool augment(int v) {
		if (v == -1) { return 1; }
		if (vis[v]) { return 0; }
		vis[v] = 1;
		for (auto &e : nodes[v].edges)
			if (augment(match[e.v])) {
				match[e.v] = v; match[v] = e.v;
				return 1;
			}
		return 0;
	}

	int maxMatch() {
		int w = 0;
		for (int i = 0; i < n; i++) {
			if (match[i] != -1) { continue; }
			for (int j = 0; j < n; j++) { vis[j] = 0; }
			w += augment(i);
		}
		return w;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int p, n; cin >> p >> n;
		vector<vector<int>> ma(2*p, vector<int>(2*p, 0));
		for (int i = 0; i < n; i++) {
			int u, v; cin >> u >> v; 
			u--; v--; ma[u][v + p] = 1;
		}
		bipartiteGraph g(p, p);
		for (int i = 0; i < p; i++)
			for (int j = p; j < 2*p; j++)
				if (!ma[i][j]) { g.add_edge(i, j); }

		cout << 2 * p - g.maxMatch() << endl;
	}

	cin.ignore(2); return 0;
}