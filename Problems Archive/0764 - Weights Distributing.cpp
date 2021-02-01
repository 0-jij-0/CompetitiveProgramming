#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;
typedef long long ll;

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

	void bfs(int u, vector<int> &dist) {
		queue<int> q; q.push(u);
		vector<bool> visited(n, false);
		visited[u] = true;
		while (!q.empty()) {
			int f = q.front(); q.pop();
			node& n = nodes[f];
			for (auto &x : n.edges) {
				int dest = x.v;
				if (visited[dest] == false) {
					dist[dest] = 1 + dist[f];
					q.push(dest); visited[dest] = true;
				}
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		vector<ll> prices; vector<int> distA, distB, distC;
		int n, m, a, b, c; cin >> n >> m >> a >> b >> c;
		prices.resize(m); graph g(n); a--; b--; c--;
		distA.resize(n, 0); distB.resize(n, 0); distC.resize(n, 0);
		for (auto &x : prices) { cin >> x; }
		sort(prices.begin(), prices.end());
		partial_sum(prices.begin(), prices.end(), prices.begin());
		prices.insert(prices.begin(), 0);
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			u--; v--; g.add_edge(u, v);
		}
		g.bfs(a, distA); g.bfs(b, distB); g.bfs(c, distC);
		ll res = 1ll << 60;
		for (int i = 0; i < n; i++) {
			if (distA[i] + distB[i] + distC[i] > m) { continue; }
			ll x = 2 * prices[distB[i]];
			x += prices[distA[i] + distB[i] + distC[i]] - prices[distB[i]];
			res = min(res, x);
		}
		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}