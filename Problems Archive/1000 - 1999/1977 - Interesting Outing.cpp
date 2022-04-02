#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> d;

struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) { d.resize(_n); }

	void add_edge(int u, int v, int w) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
	}

	int bfs(int u) {
		queue<int> q; q.push(u);
		vector<bool> vis(n, false);
		vis[u] = true; d[u] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (edge& e : nodes[cur].edges) {
				if (vis[e.v]) { continue; }
				q.push(e.v); vis[e.v] = true;
				d[e.v] = e.w + d[cur];
			}
		}
		return max_element(d.begin(), d.end()) - d.begin();
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; d.clear();
		graph g(n);	ll edgeSum = 0; 
		for (int i = 1; i < n; i++) {
			int u, v, w; cin >> u >> v >> w;
			edgeSum += w; u--; v--;
			g.add_edge(u, v, w);
		}
		ll diam = d[g.bfs(g.bfs(0))];
		ll res = (edgeSum << 1) - diam;
		cout << "Case #" << t << ": " << res << '\n';
	}
	cin.ignore(2); return 0;
}