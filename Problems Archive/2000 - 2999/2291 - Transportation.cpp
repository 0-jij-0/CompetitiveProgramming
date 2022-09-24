#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

struct DSU {
	vector<int> rank, parent;
	DSU(int n) : rank(n, 1), parent(n) {
		iota(parent.begin(), parent.end(), 0);
	}
	int find(const int& u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

struct Edge {
	int u, v; ll w; Edge() {}
	Edge(int _u, int _v, ll _w) : u(_u), v(_v), w(_w) {}
	bool operator < (const Edge& rhs) const { return w < rhs.w; }
};

struct Graph {
	int n = 0; vector<Edge> edges; Graph() {}
	Graph(int _n) : n(_n) {}

	void addEdge(int u, int v, ll w) {
		edges.emplace_back(u, v, w);
	}

	ll KruskalMST() {
		DSU dsu(n); ll res = 0; int s = 0; sort(edges.begin(), edges.end());
		for (Edge& e : edges) if (dsu.merge(e.u, e.v)) { res += e.w; ++s; }
		return (s == n - 1) ? res : INF;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; 
	Graph G[4] = { Graph(n), Graph(n + 1), Graph(n + 1), Graph(n + 2) };
	for (int i = 0; i < n; i++) {
		int x; cin >> x; 
		G[1].addEdge(n, i, x);
		G[3].addEdge(n, i, x);
	}
	for (int i = 0; i < n; i++) {
		int x; cin >> x; 
		G[2].addEdge(n, i, x);
		G[3].addEdge(n + 1, i, x);
	}

	for (int i = 0; i < m; i++) {
		int u, v, z; cin >> u >> v >> z; --u; --v;
		G[0].addEdge(u, v, z); G[1].addEdge(u, v, z);
		G[2].addEdge(u, v, z); G[3].addEdge(u, v, z);
	}

	ll res = INF;
	for (int i = 0; i < 4; i++)
		res = min(res, G[i].KruskalMST());

	cout << res << '\n';
}