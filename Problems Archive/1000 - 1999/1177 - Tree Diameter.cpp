#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

vector<int> d;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); d.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	int bfs(int u) {
		queue<int> q; q.push(u);
		vector<bool> vis(n, false);
		vis[u] = true; d[u] = 0; int cur;
		while (!q.empty()) {
			cur = q.front(); q.pop();
			for (edge &e : nodes[cur].edges) {
				if (vis[e.v]) { continue; }
				q.push(e.v); vis[e.v] = true;
				d[e.v] = 1 + d[cur];
			}
		}
		return cur;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	int f = g.bfs(0);
	cout << d[g.bfs(f)] << '\n';
	cin.ignore(2); return 0;
}