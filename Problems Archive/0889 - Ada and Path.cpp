#include <iostream>
#include <vector>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node { vector<edge> edges; node() {} };

struct bipartiteGraph {
	vector<node> nodes;
	vector<bool> vis;
	vector<int> match;
	int n, m;

	bipartiteGraph(const int &_n, int const &_m) : n(_n), m(_m) {
		nodes.resize(n + m); match.resize(n + m, -1); vis.resize(n + m, 0);
	}

	void add_edge(const int &u, const int &v) {
		nodes[u].edges.push_back(edge(u, v));
		nodes[v].edges.push_back(edge(v, u));
	}

	bool augment(const int &v) {
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

	int maxMatching() {
		int w = 0;
		for (int x = 0; x < n; x++) {
			if (match[x] != -1) { continue; }
			for (auto &e : nodes[x].edges)
				if (match[e.v] == -1) {
					match[e.v] = x; match[x] = e.v;
					w++; break;
				}
		}
		for (int i = 0; i < n; i++) {
			if (match[i] != -1) { continue; }
			for (int j = 0; j < n; j++) { vis[j] = 0; }
			w += augment(i);
		}
		return w;
	}
};

vector<vector<int>> v; int n;

inline void connect(bipartiteGraph &g, const int &i, const int &j) {
	int outNode = i * n + j;
	if (i != 0 && v[i - 1][j] == v[i][j] + 1) { g.add_edge(outNode, n * n + (i - 1)*n + j); }
	if (i != n - 1 && v[i + 1][j] == v[i][j] + 1) { g.add_edge(outNode, n * n + (i + 1)*n + j); }
	if (j != 0 && v[i][j - 1] == v[i][j] + 1) { g.add_edge(outNode, n * n + i * n + j - 1); }
	if (j != n - 1 && v[i][j + 1] == v[i][j] + 1) { g.add_edge(outNode, n * n + i * n + j + 1); }
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n; bipartiteGraph g(n*n, n*n);
		v.clear(); v.resize(n, vector<int>(n));
		int res = 0; for (auto &x : v) {
			for (auto &y : x) { cin >> y; res += (y == 1); }
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				connect(g, i, j);
		int pathCover = n * n - g.maxMatching();
		bool b = pathCover == res;
		cout << (b ? "YES" : "NO") << '\n';
	}

	return 0;
}