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
		edges.emplace_back(v, u, cap2, -cost);
	}

	ll minCostMatching(int s, int t, int k, ll prevFlow = 0) {
		ll flow = prevFlow, cost = 0;
		potentialSPFA(s, t); vector<int> parent(n);

		while (flow < k && maxFlowDijkstraSparse(s, t, parent)) {
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

	bool maxFlowDijkstraSparse(const int& s, int t, vector<int>& parent) {
		vector<ll> dist(n, INF); dist[s] = 0ll;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({ 0, s }); vector<bool> vis(n, false);

		while (!pq.empty()) {
			if (vis[pq.top().second]) { pq.pop(); continue; }
			int cur = pq.top().second; pq.pop(); vis[cur] = true;
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

	bool maxFlowDijkstraDense(const int& s, const int& t, vector<int>& parent) {
		vector<ll> dist(n, INF); dist[s] = 0;
		vector<bool> vis(n, false); int cur = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (vis[cur] || (!vis[j] && dist[j] < dist[cur])) cur = j;

			vis[cur] = true;
			for (auto& e : nodes[cur]) if (edges[e].cap > 0) {
				int v = edges[e].v; ll W = edges[e].cost + P[cur] - P[v];
				if (dist[v] > dist[cur] + W) {
					parent[v] = e; dist[v] = dist[cur] + W;
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
			if (e.u != s && e.v != t) res.emplace_back(e.u, e.v);
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}