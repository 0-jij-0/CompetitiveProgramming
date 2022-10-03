#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

struct Edge {
	int u, v; ll w; Edge() {}
	Edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct Graph {
	vector<vector<int>> nodes; int n;
	vector<Edge> edges; int m = 0;
	vector<vector<ll>> D;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v, ll w) {
		if(u != n) nodes[u].emplace_back(m++);
		//if(u != n) nodes[v].emplace_back(m++); //Unidrected
		edges.emplace_back(u, v, w);
		//if (u != n) edges.emplace_back(v, u, w); //Undirected
	}

	vector<ll> dijkstra(int s, vector<ll> &h) {
		vector<ll> dist(n, INF); dist[s] = 0ll;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({ 0, s }); vector<bool> vis(n, false);

		while (!pq.empty()) {
			if (vis[pq.top().second]) { pq.pop(); continue; }
			int cur = pq.top().second; pq.pop(); vis[cur] = true;
			for (auto& e : nodes[cur]) {
				int v = edges[e].v; ll W = edges[e].w + h[cur] - h[v];
				if (dist[v] > dist[cur] + W) pq.push({ dist[v] = dist[cur] + W, v });
			}
		}
		return dist;
	}

	vector<ll> bellmanFord(int src) {
		vector<ll> d(n + 1, INF); int x = -1; d[src] = 0;
		for (int i = 0; i <= n; i++) {
			x = -1;	for (Edge& e : edges)
				if (d[e.u] != INF && d[e.u] + e.w < d[e.v])
					d[x = e.v] = d[e.u] + e.w;
		}
		return x == -1 ? d : vector<ll>();
	}

	bool allPairsShortestPaths() {
		for (int i = 0; i < n; i++)	addEdge(n, i, 0);
		vector<ll> h = bellmanFord(n);
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

}