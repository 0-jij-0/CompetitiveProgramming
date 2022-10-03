#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
	int u, v; ll w; Edge() {}
	Edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
};

struct Graph {
	vector<vector<int>> nodes; int n;
	vector<Edge> edges; int m = 0;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v, ll w) {
		nodes[u].emplace_back(m++);
		//nodes[v].emplace_back(m++); //Undirected
		edges.emplace_back(u, v, w);
		//edges.emplace_back(v, u, w); //Undirected
	}

	//Check if Cycle is reachable if given some destination (switch to vector)
	vector<int> bellmanFord(int src) { //returns negative weight cycle
		vector<ll> dist(n, 1ll << 40), parent(n, -1); 
		int lastRelax = -1; dist[src] = 0;
		for (int i = 0; i < n; i++) {
			lastRelax = -1;	for (Edge &e : edges)
				if (dist[e.u] != 1ll << 40 && dist[e.u] + e.w < dist[e.v])
					dist[lastRelax = e.v] = dist[parent[e.v] = e.u] + e.w;
		}

		if (lastRelax == -1) { return vector<int>(); }

		vector<int> negCycle;
		for (int i = 0; i < n; i++) lastRelax = parent[lastRelax];
		for (int v = lastRelax; ; v = parent[v]) {
			negCycle.push_back(v);
			if (v == lastRelax && negCycle.size() > 1) { break; }
		}
		reverse(negCycle.begin(), negCycle.end());
		return negCycle;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}