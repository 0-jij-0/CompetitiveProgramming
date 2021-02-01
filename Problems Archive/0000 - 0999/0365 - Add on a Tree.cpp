#include <iostream>
#include <vector>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v, int _w = 0, int _id = 0) :
		u(_u), v(_v) {}
};

struct node { int id; vector<edge> edges; };

struct graph {
	vector<node> nodes;
	int n, m;

	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v), e2(v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n; graph g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	bool b = true;
	for (auto &x : g.nodes) {
		if (x.edges.size() == 2) { b = false; break; }
	}
	cout << (b ? "YES" : "NO") << endl;
	cin.ignore(2); return 0;
}