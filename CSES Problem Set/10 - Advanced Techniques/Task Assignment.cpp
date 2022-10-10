#include <bits/stdc++.h>
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
		edges.emplace_back(v, u, cap2, -cost);
	}

	ll minCostMatching(int s, int t, int k, ll prevFlow = 0) {
		ll flow = prevFlow, cost = 0;
		vector<int> parent(n);

		while (flow < k && maxFlowDijkstra(s, t, parent)) {
			++flow; int cur = t;
			while (cur != s) {
				int& e = parent[cur]; cost += edges[e].cost;
				edges[e].cap--; edges[e ^ 1].cap++;
				edges[e].flow++; edges[e ^ 1].flow--;
				cur = edges[e].u;
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

	vector<pair<int, int>> getMinCostMatching() {
		vector<pair<int, int>> res;
		for (Edge& e : edges) if (e.flow > 0 && e.cost)
			res.emplace_back(e.u, e.v);
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; Graph g((n << 1) + 2);
	for (int i = 0; i < n; i++) {
		g.addEdge(n << 1, i, 0, 1);
		g.addEdge(i + n, n << 1 | 1, 0, 1);
		for (int j = 0; j < n; j++) {
			int c; cin >> c;
			g.addEdge(i, j + n, c, 1);
		}
	}

	cout << g.minCostMatching(n << 1, n << 1 | 1, n) << '\n';
	vector<pair<int, int>> res = g.getMinCostMatching();
	for (auto& x : res) cout << x.first + 1 << ' ' << x.second - n + 1 << '\n';
}