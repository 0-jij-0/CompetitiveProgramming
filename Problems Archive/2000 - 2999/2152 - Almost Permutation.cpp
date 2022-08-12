#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
ll INF = 1ll << 40;

struct Edge {
	int u, v; ll cap, cost, flow = 0; Edge() {}
	Edge(int _u, int _v, ll _cap, ll _cost) :
		u(_u), v(_v), cap(_cap), cost(_cost) {}
};

struct Graph {
	vector<vector<int>> nodes; int n;
	vector<Edge> edges; int m = 0;
	vector<ll> P;

	Graph(int _n) : n(_n), nodes(_n), P(_n) {}

	void addEdge(int u, int v, ll cost, ll cap1, ll cap2 = 0) {
		nodes[u].emplace_back(m++);
		nodes[v].emplace_back(m++);
		edges.emplace_back(u, v, cap1, cost);
		edges.emplace_back(v, u, cap2, cost);
	}

	ll minCostFlow(int s, int t, int k) {
		ll flow = 0, cost = 0;

		vector<int> parent(n);
		while (flow < k && maxFlowDijkstra(s, t, parent)) {
			flow++; int cur = t;
			while (cur != s) {
				int& e = parent[cur], u = edges[e].u, v = edges[e].v;
				cost += edges[e].cost; cur = edges[e].u;

				if (u == s || v == s) { edges[e].cost += 2; edges[e ^ 1].cost -= 2; }
				edges[e].cap--; edges[e ^ 1].cap++;
				edges[e].flow++; edges[e ^ 1].flow--;
			}
		}
		return flow == k ? cost : -1;
	}

	bool maxFlowDijkstra(const int& s, int t, vector<int>& parent) {
		vector<ll> dist(n, INF); dist[s] = 0ll;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({ 0, s }); vector<bool> visited(n, false);

		while (!pq.empty()) {
			if (visited[pq.top().second]) { pq.pop(); continue; }
			int cur = pq.top().second; pq.pop(); visited[cur] = true;
			for (auto& e : nodes[cur]) if (edges[e].cap > 0) {
				int v = edges[e].v; ll W = edges[e].cost + P[cur] - P[v];
				if (dist[v] > dist[cur] + W) {
					parent[v] = e;
					dist[v] = dist[cur] + W;
					pq.push({ dist[v], v });
				}
			}
		}

		for (int i = 0; i < n; i++) P[i] += dist[i];
		return dist[t] != INF;
	}
};

vector<int> L, U;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q; Graph G((n << 1) + 2);
	L.resize(n, 0); U.resize(n, n - 1);
	int src = n << 1, dst = n << 1 | 1;

	while (q--) {
		int t, l, r, x; cin >> t >> l >> r >> x; --x;
		if (--t) for (int i = --l; i < r; i++) U[i] = min(U[i], x); 
		else for (int i = --l; i < r; i++) L[i] = max(L[i], x);
	}

	for (int i = 0; i < n; i++) {
		G.addEdge(src, i, 1, INF);
		G.addEdge(i + n, dst, 0, 1);
		for (int j = L[i]; j <= U[i]; j++)
			G.addEdge(j, i + n, 0, 1);
	}

	cout << G.minCostFlow(src, dst, n) << '\n';
}