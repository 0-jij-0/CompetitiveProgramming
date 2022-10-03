#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU {
	vector<int> rank, par;

	DSU(int n) : rank(n, 1), par(n) { iota(par.begin(), par.end(), 0); }

	int find(const int& u) { return par[u] == u ? u : (par[u] = find(par[u])); }

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return false;
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	par[v] = u;
		return true;
	}
};

struct Edge {
	int u, v; ll w; Edge() {}
	Edge(int _u, int _v, ll _w) : u(_u), v(_v), w(_w) {}
	bool operator < (const Edge &rhs) const { return w < rhs.w; }
};

struct Graph {
	vector<vector<int>> nodes; int n = 0;
	vector<Edge> edges; int m = 0;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v, ll w) {
		nodes[u].emplace_back(m);
		nodes[v].emplace_back(m++);
		edges.emplace_back(u, v, w);
	}

	vector<Edge> KruskalMST() {
		DSU dsu(n); vector<Edge> res; sort(edges.begin(), edges.end());
		for (Edge &e : edges) if (dsu.merge(e.u, e.v)) res.push_back(e);
		return ((int)res.size() == n - 1) ? res : vector<Edge>();
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}