#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct edge {
	int u, v; ll w; bool match = 0; edge() {}
	edge(int _u, int _v, ll _w) : u(_u), v(_v), w(_w) {}
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
		nodes[u].edges.push_back(edge(u, v, 0));
		nodes[v].edges.push_back(edge(v, u, 0));
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

struct graph {
	vector<edge> edges;
	vector<node> nodes;
	vector<vector<ll>> D;
	int n, m;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, int w) {
		edge e1(u, v, w), e2(v, u, w);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
		edges.push_back(e1); m++;
	}

	void allPairsShortestPath() {
		//Change max to be bigger than any possible output
		int n = nodes.size(), max = (1 << 30); D.resize(n); 
		for (int i = 0; i < n; i++) { D[i].resize(n, max); D[i][i] = 0; }

		for(auto &y : edges)
			D[y.u][y.v] = D[y.v][y.u] = min(D[y.u][y.v], y.w);

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (D[i][k] + D[k][j] < D[i][j])
						D[i][j] = D[i][k] + D[k][j];
	}
};

vector<int> friends;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int n, m, f, t; cin >> n >> m >> f >> t;
		friends.resize(f); graph g(n);
		for (auto &x : friends) { cin >> x; x--; }
		for (int i = 0; i < m; i++) {
			int a, b, l; cin >> a >> b >> l;
			a--; b--; g.add_edge(a, b, l);
		}
		g.allPairsShortestPath(); bipartiteGraph G(f, n);
		for (int i = 0; i < f; i++)
			for (int j = 0; j < n; j++)
				if (g.D[friends[i]][j] <= t)
					G.add_edge(i, f + j);
		cout << G.maxMatching() << endl;
	}

	cin.ignore(2); return 0;
}