#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

map<pair<int, int>, int> res;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

vector<vector<int>> D, helper;

struct graph {
	vector<edge> edges;
	vector<node> nodes;
	int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v);
		nodes[u].edges.push_back(e1);
		edges.push_back(e1);
	}

	void cycle_dfs(int u, vector<int> &color) {
		color[u] = 1;
		for (auto x : nodes[u].edges) {
			int v = x.v;
			if (!color[v]) { res[{u, v}] = 1; cycle_dfs(v, color); }
			else if (color[v] == 1) { res[{u, v}] = 2; }
			else { res[{u, v}] = 1; }
		}
		color[u] = 2;
	}

	void edge_coloring() {
		vector<int> color(n, 0);
		for (int i = 0; i < n; i++) {
			if (color[i]) { continue; }
			cycle_dfs(i, color);
		}
		vector<int> c(edges.size(), 0); bool b = false;
		for (int i = 0; i < (int)c.size(); i++) {
			c[i] = res[{edges[i].u, edges[i].v}];
			if (c[i] == 2) { b = true; }
		}
		cout << 1 + b << endl;
		for (int i = 0; i < (int)c.size(); i++) {
			cout << c[i];
			if (i + 1 != (int)c.size()) { cout << ' '; }
			else { cout << endl; }
		}
	}
};

int main() {
	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	g.edge_coloring();
	cin.ignore(2); return 0;
}