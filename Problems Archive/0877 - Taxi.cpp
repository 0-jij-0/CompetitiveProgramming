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
	vector<bool> Z, vis;
	vector<int> unMatched, match;

	bipartiteGraph(int _n, int _m) : n(_n), m(_m) {
		nodes.resize(n + m); Z.resize(n + m, 0);
		match.resize(n + m, -1); vis.resize(n + m, 0);
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

	//In Bipartite Graphs (Konig's Theorem)
	//Max Matching = Min Vertex Cover = Max Flow = Min Cut
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
};

vector<pair<int, int>> pass, taxi;

bool check(int i, int j, int s, int c) {
	int dx = abs(pass[i].first - taxi[j].first);
	int dy = abs(pass[i].second - taxi[j].second);
	return (dx + dy)*200 <= s * c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int k; cin >> k;
	while (k--) {
		int p, t, s, c; cin >> p >> t >> s >> c;
		pass.resize(p); taxi.resize(t);
		for (auto &x : pass) { cin >> x.first >> x.second; }
		for (auto &x : taxi) { cin >> x.first >> x.second; }
		bipartiteGraph g(p, t);
		for(int i = 0; i < p; i++)
			for(int j = 0; j < t; j++)
				if (check(i, j, s, c)) { g.add_edge(i, p + j); }
		cout << g.maxMatching() << endl;
	}

	cin.ignore(2); return 0;
}