#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

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

	vector<ll> dijkstra(int s, int k) {
		vector<vector<ll>> dist(n, vector<ll>(k, INF)); dist[s][0] = 0ll;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({ 0, s }); vector<int> visited(n, 0);

		while (!pq.empty()) {
			if (visited[pq.top().second] == k) { pq.pop(); continue; }
			int cur = pq.top().second; dist[cur][visited[cur]++] = pq.top().first; pq.pop();
			for (edge &e : nodes[cur].edges) if (visited[e.v] != k)
				pq.push({ dist[cur][visited[cur] - 1] + e.w, e.v });
		}
		return move(dist.back());
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k; cin >> n >> m >> k; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		u--; v--; g.add_edge(u, v, c);
	}
	vector<ll> v = g.dijkstra(0, k);
	for (auto &x : v) cout << x << ' ';
	cout << '\n'; cin.ignore(2); return 0;
}