#include <iostream>
#include <vector>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
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

	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x; x--; graph g(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v;
			u--; v--; g.add_edge(u, v);
		}
		if (g.nodes[x].edges.size() <= 1) { cout << "Ayush" << '\n'; continue; }
		cout << (n % 2 ? "Ashish" : "Ayush") << "\n";
	}

	cin.ignore(2); return 0;
}