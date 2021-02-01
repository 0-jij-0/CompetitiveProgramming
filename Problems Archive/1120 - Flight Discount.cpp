#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;
typedef pair<pair<ll, int>, bool> T;

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };


struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, ll w) {
		nodes[u].edges.emplace_back(u, v, w);
	}

	ll dijkstra(int s) {
		vector<ll> dist[2]; dist[0].resize(n, INF); dist[1].resize(n, INF); dist[0][0] = 0ll;
		vector<bool> visited[2]; visited[0].resize(n, false); visited[1].resize(n, false);
		priority_queue<T, vector<T>, greater<T>> pq; pq.push({ { 0, s }, 0 });

		while (!pq.empty()) {
			if (visited[pq.top().second][pq.top().first.second]) { pq.pop(); continue; }
			int cur = pq.top().first.second, t = pq.top().second; pq.pop(); visited[t][cur] = true;
			for (edge &e : nodes[cur].edges) {
				if (dist[t][e.v] > dist[t][cur] + e.w) {
					dist[t][e.v] = dist[t][cur] + e.w;
					pq.push({ { dist[t][e.v], e.v }, t != 0});
				}
				if (!t && dist[1][e.v] > dist[0][cur] + (e.w >> 1)) {
					dist[1][e.v] = dist[0][cur] + (e.w >> 1);
					pq.push({ { dist[1][e.v], e.v }, 1 });
				}
			}
		}
		return dist[1].back();
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		u--; v--; g.add_edge(u, v, c);
	}
	cout << g.dijkstra(0) << endl;
	cin.ignore(2); return 0;
}