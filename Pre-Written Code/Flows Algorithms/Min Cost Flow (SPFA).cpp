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

	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v, ll cost, ll cap1, ll cap2 = 0) {
		nodes[u].emplace_back(m++);
		nodes[v].emplace_back(m++);
		edges.emplace_back(u, v, cap1, cost);
		edges.emplace_back(v, u, cap2, -cost);
	}

	ll minCostFlow(int s, int t, int k, ll prevFlow = 0) {
		ll flow = prevFlow, newFlow = 0, cost = 0;

		vector<int> parent(n);
		while (flow < k && (newFlow = maxFlowSPFA(s, t, parent))) {
			newFlow = min(newFlow, k - flow);
			flow += newFlow; int cur = t;
			while (cur != s) {
				int& e = parent[cur]; cost += edges[e].cost * newFlow;
				edges[e].cap -= newFlow; edges[e ^ 1].cap += newFlow;
				edges[e].flow += newFlow; edges[e ^ 1].flow -= newFlow;
				cur = edges[e].u;
			}
		}
		return flow == k ? cost : -1;
	}

	ll maxFlowSPFA(const int& s, int t, vector<int>& parent) {
		parent.assign(n, -1); parent[s] = -2;
		vector<ll> dist(n, INF); dist[s] = 0;
		vector<bool> inQueue(n, false);
		queue<int> q; q.push(s);

		while (!q.empty()) {
			int cur = q.front(); inQueue[cur] = false; q.pop();

			for (auto& e : nodes[cur]) {
				int u = edges[e].u, v = edges[e].v;
				if (edges[e].cap && dist[v] > dist[u] + edges[e].cost) {
					parent[v] = e; dist[v] = dist[u] + edges[e].cost;
					if (!inQueue[v]) { q.push(v); inQueue[v] = true; }
				}
			}
		}

		if (dist[t] == INF) { return 0; }
		ll res = INF; while (t != s) {
			int e = parent[t];
			res = min(res, edges[e].cap);
			t = edges[e].u;
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}