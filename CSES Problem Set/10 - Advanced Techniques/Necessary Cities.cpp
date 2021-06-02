#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<int> res;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<edge> edges;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(edges.size());
		edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(edges.size());
		edges.emplace_back(v, u);
	}

	void artPointDFS(int cur, int p, vector<bool>& vis, vector<int>& low, vector<int>& tin, int& timer) {
		vis[cur] = true; tin[cur] = low[cur] = timer++; int c = 0;
		for (auto& x : nodes[cur].edges) {
			edge& e = edges[x];	if (e.v == p) { continue; }
			if (vis[e.v]) { low[cur] = min(low[cur], tin[e.v]); continue; }

			artPointDFS(e.v, cur, vis, low, tin, timer);
			low[cur] = min(low[cur], low[e.v]); c++;
			if (p != -1 && low[e.v] >= tin[cur]) res.insert(cur); //isArtPoint(cur);		Might run this for node cur multiple times (once for each child)
		}
		if (p == -1 && c > 1) res.insert(cur);
	}

	void findArtPoints() {
		int timer = 0; vector<bool> vis(n, false);
		vector<int> low(n, -1), tin(n, -1);
		for (int i = 0; i < n; i++)	if (!vis[i])
			artPointDFS(i, -1, vis, low, tin, timer);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		--u; --v; g.add_edge(u, v);
	}

	g.findArtPoints(); cout << res.size() << '\n';
	for (auto& x : res) cout << x + 1 << ' '; cout << '\n';

	cin.ignore(2); return 0;
}