#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { ll x = 0; vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		if (nodes[u].x == -1 || nodes[v].x == -1) { return; }
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	ll bfs(int u, int v, ll w) {
		queue<int> q; q.push(u);
		vector<ll> dist(n, INF); dist[u] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (edge& e : nodes[cur].edges) {
				if (dist[e.v] != INF) { continue; }
				q.push(e.v); dist[e.v] = w + dist[cur];
			}
		}
		q.push(v); vector<ll> dist2(n, INF); 
		dist2[v] = 0; while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (edge& e : nodes[cur].edges) {
				if (dist2[e.v] != INF) { continue; }
				q.push(e.v); dist2[e.v] = w + dist2[cur];
			}
		}
		
		ll res = dist[v];
		for (int i = 0; i < n; i++)
			if (nodes[i].x < 1) { dist[i] = dist2[i] = INF; }
			else { dist[i] += nodes[i].x; dist2[i] += nodes[i].x; }

		ll a = *min_element(dist.begin(), dist.end());
		ll b = *min_element(dist2.begin(), dist2.end());

		return min(res, a + b);
	}
};



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; ll w; cin >> n >> m >> w; graph g(n * m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		int x; cin >> x; g.nodes[i * m + j].x = x;
		if (i) g.add_edge(i * m + j, (i - 1) * m + j);
		if (j) g.add_edge(i * m + j, i * m + j - 1);
	}

	ll res = g.bfs(0, n * m - 1, w);
	cout << (res >= INF ? -1 : res) << '\n';

	cin.ignore(2); return 0;
}