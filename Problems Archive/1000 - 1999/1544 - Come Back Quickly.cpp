#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
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

	ll dijkstra(int s) {
		vector<ll> dist(n, INF);
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({ 0, s }); vector<bool> visited(n, false);

		while (!pq.empty()) {
			if (visited[pq.top().second]) { pq.pop(); continue; }
			int cur = pq.top().second; ll w = pq.top().first;
			pq.pop(); visited[cur] = true;

			for (edge& e : nodes[cur].edges)
				if (dist[e.v] > w + e.w) {
					dist[e.v] = w + e.w;
					pq.push({ dist[e.v], e.v });
				}
		}
		return dist[s];
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--; g.add_edge(a, b, c);
	}

	for (int i = 0; i < n; i++) {
		ll cur = g.dijkstra(i);
		cout << (cur == INF ? -1 : cur) << '\n';
	}

	cin.ignore(2); return 0;
}