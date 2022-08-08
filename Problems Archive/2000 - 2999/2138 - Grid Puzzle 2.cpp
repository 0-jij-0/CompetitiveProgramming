#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
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
		potentialSPFA(s, t); vector<int> parent(n);

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

	void potentialSPFA(const int& s, int t) {
		P.assign(n, INF); P[s] = 0;
		vector<bool> inQueue(n, false);
		queue<int> q; q.push(s);

		while (!q.empty()) {
			int cur = q.front(); inQueue[cur] = false; q.pop();

			for (auto& e : nodes[cur]) {
				int u = edges[e].u, v = edges[e].v;
				if (edges[e].cap && P[v] > P[u] + edges[e].cost) {
					P[v] = P[u] + edges[e].cost;
					if (!inQueue[v]) { q.push(v); inQueue[v] = true; }
				}
			}
		}
	}

	vector<pair<int, int>> getMinCostMatching(int s, int t) {
		vector<pair<int, int>> res;
		for (Edge& e : edges) if (e.flow > 0)
			if(e.u != s && e.v != t) res.emplace_back(e.u, e.v);
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k = 0; cin >> n; Graph g((n << 1) + 2);
	for (int i = 0; i < n; i++) {
		int a; cin >> a; g.addEdge(n << 1, i, 0, a); k += a;
	}
	for (int i = 0; i < n; i++) {
		int b; cin >> b; g.addEdge(i + n, n << 1 | 1, 0, b);
	}

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int c; cin >> c; g.addEdge(i, j + n, -c, 1);
		}

	int src = n << 1, dst = n << 1 | 1;
	ll minCost = g.minCostMatching(src, dst, k);
	if (minCost == -1) { cout << -1 << '\n'; return 0; }
	vector<pair<int, int>> matching = g.getMinCostMatching(src, dst);
	vector<string> res(n, string(n, '.'));
	for (auto& p : matching) res[p.first][p.second - n] = 'X';

	cout << -minCost << '\n';
	for (auto& s : res) cout << s << '\n';
}