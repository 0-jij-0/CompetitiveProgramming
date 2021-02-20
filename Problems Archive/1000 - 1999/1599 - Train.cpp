#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

struct edge {
	int u, v; ll w, k; edge() {}
	edge(int _u, int _v, ll _w, ll _k) :
		u(_u), v(_v), w(_w), k(_k) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, ll w, ll k) {
		nodes[u].edges.emplace_back(u, v, w, k);
		nodes[v].edges.emplace_back(v, u, w, k);
	}

	ll dijkstra(int s, int t) {
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		vector<ll> dist(n, INF); dist[s] = 0ll; pq.push({ 0, s });

		while (!pq.empty()) {
			int cur = pq.top().second; 
			ll w = pq.top().first; pq.pop();

			for (edge& e : nodes[cur].edges) {
				ll c = (e.k - (w % e.k)) % e.k;
				c += w + e.w; if (dist[e.v] > c) {
					dist[e.v] = c; pq.push({ c, e.v });
				}
			}
		}
		return (dist[t] == INF ? -1 : dist[t]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, s, t; cin >> n >> m >> s >> t; graph g(n);
	for (int i = 0; i < m; i++) {
		int a, b, t, k; cin >> a >> b >> t >> k;
		a--; b--; g.add_edge(a, b, t, k);
	}
	cout << g.dijkstra(--s, --t) << '\n';
	cin.ignore(2); return 0;
}