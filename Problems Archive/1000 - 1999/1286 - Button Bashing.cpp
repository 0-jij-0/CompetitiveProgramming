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

struct graph {
	vector<node> nodes; 
	vector<int> dist; int n;
	graph(int _n) : n(_n), nodes(_n), dist(_n, -1) {}

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
	}

	void bfs(int d) {
		queue<int> q; q.push(0); dist[0] = 0;
		vector<bool> vis(n, 0); vis[0] = 1;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (edge &e : nodes[cur].edges) {
				if (vis[e.v]) { continue; }
				dist[e.v] = 1 + dist[cur];
				q.push(e.v); vis[e.v] = true;
			}
		}
		for (int i = d; i < n; i++) if (dist[i] != -1) {
			cout << dist[i] << ' ' << i - d << '\n'; break;
		}
	}
};

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T; while (T--) {
		int n, t; cin >> n >> t;
		v.resize(n); graph g(3601);
		for (auto &x : v) { cin >> x; }

		for (int i = 0; i <= 3600; i++)
			for (auto &x : v) g.add_edge(i, min(max(i + x, 0), 3600));

		g.bfs(t);
	}
	cin.ignore(2); return 0;
}