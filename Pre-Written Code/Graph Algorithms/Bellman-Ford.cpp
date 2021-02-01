#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<edge> edges; int m;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, ll w) {
		nodes[u].edges.emplace_back(u, v, w);
		//nodes[v].edges.emplace_back(v, u, w); //Undirected
		edges.emplace_back(u, v, w);
		//edges.emplace_back(v, u, w); //Undirected
	}

	//Check if Cycle is reachable if given some destination (switch to vector)
	vector<int> bellman_ford(int src) { //returns negative weight cycle
		vector<ll> d(n, 1ll << 40), parent(n, -1); 
		int x; d[src] = 0;
		for (int i = 0; i < n; i++) {
			x = -1;	for (edge &e : edges)
				if (d[e.u] != 1ll << 40 && d[e.u] + e.w < d[e.v])
					d[x = e.v] = d[parent[e.v] = e.u] + e.w;
		}

		if (x == -1) { return vector<int>(); }

		vector<int> cycle;
		for (int i = 0; i < n; i++) x = parent[x];
		for (int v = x; ; v = parent[v]) {
			cycle.push_back(v);
			if (v == x && cycle.size() > 1) { break; }
		}
		reverse(cycle.begin(), cycle.end());
		return move(cycle);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin.ignore(2); return 0;
}