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
	vector<edge> edges;
	vector<vector<ll>> D;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, ll w) {
		if(u != n) nodes[u].edges.emplace_back(u, v, w);
		//if(u != n) nodes[v].edges.emplace_back(v, u, w); //Unidrected
		edges.emplace_back(u, v, w);
		//if (u != n) edges.emplace_back(v, u, w); //Undirected
	}

	vector<ll> dijkstra(int s, vector<ll> &h) {
		vector<ll> dist(n, INF); dist[s] = 0ll;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({ 0, s }); vector<bool> visited(n, false);

		while (!pq.empty()) {
			if (visited[pq.top().second]) { pq.pop(); continue; }
			int cur = pq.top().second; pq.pop(); visited[cur] = true;
			for (edge& e : nodes[cur].edges)  
				if (dist[e.v] > dist[cur] + e.w + h[e.u] - h[e.v]) {
					dist[e.v] = dist[cur] + e.w + h[e.u] - h[e.v];
					pq.push({ dist[e.v], e.v });
				}
		}
		return move(dist);
	}

	vector<ll> bellman_ford(int src) {
		vector<ll> d(n + 1, INF); int x = -1; d[src] = 0;
		for (int i = 0; i <= n; i++) {
			x = -1;	for (edge& e : edges)
				if (d[e.u] != INF && d[e.u] + e.w < d[e.v])
					d[x = e.v] = d[e.u] + e.w;
		}
		return move(x == -1 ? d : vector<ll>());
	}

	bool allPairsShortestPaths() {
		for (int i = 0; i < n; i++)	add_edge(n, i, 0);
		vector<ll> h = bellman_ford(n);
		for (int i = 0; i < n; i++) edges.pop_back();
		if (h.empty()) { return false; }

		D.resize(n); for (int i = 0; i < n; i++)
			D[i] = move(dijkstra(i, h));
		
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
			if(D[i][j] != INF) D[i][j] -= (h[i] - h[j]);

		return true;
	}

};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin.ignore(2); return 0;
}