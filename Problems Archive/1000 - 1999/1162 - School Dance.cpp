#include <iostream>
#include <vector>
using namespace std;

struct edge {
	int u, v; bool match = 0; edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node { vector<edge> edges; node() {} };

//Classic Problems:
//Maximum Matching - Minimum Vertex Cover
//Minimum Path Cover - Maximum Bipartite Clique
struct bipartiteGraph {
	//Matching: Set of edges that do not share a node
	//Vertex Cover: Set of nodes that cover all edges
	//Cut Capacity: Set of edges that disconnect source(L) from sink(R) upon removal
	//Independent Set: Set of nodes not connected by edges

	//Complement of vertex cover = independent Set
	//Clique in graph = Independent Set in inverse Graph
	vector<node> nodes; int n, m;
	vector<bool> vis;
	vector<int> unMatched, match;

	bipartiteGraph(int _n, int _m) : n(_n), m(_m),
		nodes(_n + _m), match(_n + _m, -1), vis(_n + _m, 0) {}

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	bool augment(int v) {
		if (v == -1) { return 1; }
		if (vis[v]) { return 0; }
		vis[v] = 1; for (auto &e : nodes[v].edges)
			if (augment(match[e.v])) {
				match[e.v] = v; match[v] = e.v;
				return 1;
			}
		return 0;
	}

	//In Bipartite Graphs (Konig's Theorem)
	//Max Matching = Min Vertex Cover = Max Flow = Min Cut
	//Min Path Cover = n - Max Matching
	int maxMatching() { //With Greedy initialization
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

	void printMaxMatching() {
		cout << maxMatching() << '\n';
		for (int i = 0; i < n; i++) if (match[i] != -1)
				cout << i + 1 << " " << match[i] - n + 1 << '\n';
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k; cin >> n >> m >> k; bipartiteGraph g(n, m);
	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		a--; b--; g.add_edge(a, n + b);
	}
	g.printMaxMatching(); cin.ignore(2); return 0;
}