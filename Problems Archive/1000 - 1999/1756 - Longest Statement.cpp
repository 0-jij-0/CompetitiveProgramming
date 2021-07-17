#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

struct DSU {
	vector<int> rank, parent;

	DSU(int n) : rank(n, 1), parent(n) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int& u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<edge> edges;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, int w = 0) {
		nodes[u].edges.emplace_back(edges.size());
		edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(edges.size());
		edges.emplace_back(v, u, w);
	}

	//tin[u] = discovery time of u
	//low[u] = lowest discovery time of a reachable node
	void bridgeDFS(int cur, int p, vector<bool>& vis, vector<int>& low, vector<int>& tin, int& timer, DSU &dsu) {
		vis[cur] = true; tin[cur] = low[cur] = timer++;
		for (auto& x : nodes[cur].edges) {
			edge& e = edges[x];	if (e.v == p) { continue; }
			if (vis[e.v]) { low[cur] = min(low[cur], tin[e.v]); continue; }

			bridgeDFS(e.v, cur, vis, low, tin, timer, dsu);
			low[cur] = min(low[cur], low[e.v]);
			if (low[e.v] > tin[cur]) dsu.merge(e.u, e.v);
		}
	}

	void findBridges(DSU &dsu) {
		int timer = 0; vector<bool> vis(n, false);
		vector<int> low(n, -1), tin(n, -1);
		for (int i = 0; i < n; i++)	if (!vis[i])
			bridgeDFS(i, -1, vis, low, tin, timer, dsu);
	}
};

int main() {
	freopen("graph.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; 
	graph g(n); DSU dsu(n);
	
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}

	g.findBridges(dsu); vector<bool> vis(n, 0);
	ll res = 0; for (int i = 0; i < n; i++) {
		if (vis[dsu.find(i)]) { continue; }
		vis[dsu.find(i)] = true;
		ll s = dsu.size(i);
		res += (s * (s - 1)) >> 1;
	}

	cout << res << '\n';
	cin.ignore(2); return 0;
}