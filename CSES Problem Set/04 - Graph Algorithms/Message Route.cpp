#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v), e2(v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	void bfs(int s, int d) {
		vector<bool> vis(n, false); vector<int> parent(n, -1);
		queue<int> q; q.push(s); vis[s] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (edge &e : nodes[cur].edges) {
				if (vis[e.v]) { continue; }
				q.push(e.v); vis[e.v] = true;
				parent[e.v] = cur;
			}
		}
		if (parent[d] == -1) { cout << "IMPOSSIBLE\n"; return; }
		vector<int> res(1, d); while (d != s) { res.push_back(d = parent[d]); }
		reverse(res.begin(), res.end()); cout << res.size() << '\n'; 
		for (auto &x : res) { cout << x + 1 << ' '; } cout << '\n';
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	g.bfs(0, n - 1);
}