#include <bits/stdc++.h>
using namespace std;

int res = 1 << 20;

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
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	int bfs(int s, int t) {
		queue<int> q; q.push(s);
		vector<int> dist(n, -1); dist[s] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			if (dist[cur] >= res) { return 1 << 20; }
			for (edge& e : nodes[cur].edges) {
				if (dist[e.v] != -1) { continue; }
				if (e.v == t) { return 1 + dist[cur]; }
				q.push(e.v); dist[e.v] = 1 + dist[cur];
			}
		}
		return 1 << 20;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		res = min(res, 1 + g.bfs(--u, --v));
		g.add_edge(u, v);
	}

	cout << (res == 1 << 20 ? -1 : res) << '\n';
}