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
	vector<vector<Edge>> nodes; int n;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v, ll w) {
		nodes[u].emplace_back(u, v, w);
		nodes[v].emplace_back(v, u, w);
	}

	vector<ll> dijkstra(int s, vector<int> &par) {
		vector<ll> dist(n, INF); dist[s] = 0ll;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({ 0, s }); vector<bool> vis(n, false);

		while (!pq.empty()) {
			if (vis[pq.top().second]) { pq.pop(); continue; }
			int cur = pq.top().second; pq.pop(); vis[cur] = true;
			for (Edge &e : nodes[cur])
				if (dist[e.v] > dist[cur] + e.w) {
					dist[e.v] = dist[par[e.v] = cur] + e.w;
					pq.push({ dist[e.v], e.v });
				}
		}
		return dist;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}