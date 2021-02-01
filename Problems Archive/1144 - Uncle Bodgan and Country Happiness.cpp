#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

vector<int> p, h, sP; int m;

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	void dfs(int u, int par) {
		int res = p[u];
		for (edge &e : nodes[u].edges) {
			if (e.v == par) { continue; }
			dfs(e.v, u); res += sP[e.v];
		}
		sP[u] = res;
	}

	bool bfs(int u) {
		queue<pair<int, int>> q; 
		if (abs(h[u]) > sP[u]) { return false; }
		if ((sP[u] + h[u]) % 2) { return false; }
		int H = (sP[u] + h[u]) >> 1; q.push({ u, H });
		vector<bool> vis(n, false); vis[u] = true;
		while (!q.empty()) {
			pair<int, int> p = q.front(); q.pop();
			int cur = p.first; H = p.second;
			for (edge &e : nodes[cur].edges) {
				if (vis[e.v]) { continue; }
				if (abs(h[e.v]) > sP[e.v]) { return false; }
				if ((sP[e.v] + h[e.v]) % 2) { return false; }
				int EH = (sP[e.v] + h[e.v]) >> 1;
				if (H < EH) { return false; }
				H -= EH; q.push({ e.v, EH }); vis[e.v] = true;
			}
		}
		return true;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n >> m; graph g(n); 
		p.resize(n); h.resize(n); sP.resize(n);
		for (auto &x : p) { cin >> x; }
		for (auto &x : h) { cin >> x; }
		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v;
			u--; v--; g.add_edge(u, v);
		}
		g.dfs(0, -1); cout << (g.bfs(0) ? "YES" : "NO") << '\n';
	}

	cin.ignore(2); return 0;
}