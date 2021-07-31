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
	ll num = 0;
	vector<edge> edges; node() {}
};

struct graph {
	vector<node> nodes; int n;	vector<ll> dist;
	graph(int _n) : n(_n), nodes(_n), dist(_n, INF) {}

	void add_edge(int u, int v, ll w) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
	}

	void dijkstra(int s) {
		priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		vector<bool> vis(n, false); dist[s] = 0ll; pq.push({ 0, s });
		nodes[s].num = 1;

		while(!pq.empty()) {
			int cur = pq.top().second; pq.pop();
			while (vis[cur]) { cur = pq.top().second; pq.pop(); }
			vis[cur] = true; for (auto& e : nodes[cur].edges) {
				if (dist[e.v] > dist[cur] + e.w) {
					dist[e.v] = dist[cur] + e.w;
					nodes[e.v].num = nodes[e.u].num;
					pq.push({ dist[e.v], e.v });
				}
				else if (dist[e.v] == dist[cur] + e.w) {
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
		int u, v; cin >> u >> v;
		g.add_edge(--u, --v, 1);
	}

	g.dijkstra(0);
	cout << g.nodes[n - 1].num << '\n';
	cin.ignore(2); return 0;
}