#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll INF = 1ll << 60;

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { 
	int miL = 0, maL = 0; ll num = 0;
	vector<edge> edges; node() {}
};

struct graph {
	vector<node> nodes; int n;	vector<ll> dist;
	graph(int _n) : n(_n), nodes(_n), dist(_n, INF) {}

	void add_edge(int u, int v, ll w) {
		nodes[u].edges.emplace_back(u, v, w);
	}

	void dijkstra(int s) {
		priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		vector<bool> vis(n, false); dist[s] = 0ll; pq.push({ 0, s });
		nodes[s].miL = nodes[s].maL = 0; nodes[s].num = 1;

		for (int i = 0; i < n; i++) {
			int cur = pq.top().second; pq.pop();
			while (vis[cur]) { cur = pq.top().second; pq.pop(); }
			vis[cur] = true; for (auto &e : nodes[cur].edges) {
				if (dist[e.v] > dist[cur] + e.w) {
					dist[e.v] = dist[cur] + e.w;
					nodes[e.v].miL = nodes[e.u].miL + 1;
					nodes[e.v].maL = nodes[e.u].maL + 1;
					nodes[e.v].num = nodes[e.u].num;
					pq.push({ dist[e.v], e.v });
				}
				else if (dist[e.v] == dist[cur] + e.w) {
					nodes[e.v].miL = min(nodes[e.v].miL, nodes[e.u].miL + 1);
					nodes[e.v].maL = max(nodes[e.v].maL, nodes[e.u].maL + 1);
					nodes[e.v].num = (nodes[e.v].num + nodes[e.u].num) % mod;
				}
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; ll w; cin >> u >> v >> w;
		g.add_edge(--u, --v, w);
	}

	g.dijkstra(0); node& N = g.nodes[n - 1];
	cout << g.dist[n - 1] << ' ' << N.num << ' ' << N.miL << ' ' << N.maL << '\n';
	cin.ignore(2); return 0;
}