#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
ll INF = 1ll << 40;

struct Edge {
	int u, v; ll cap, flow = 0; Edge() {}
	Edge(int _u, int _v, ll _cap) :
		u(_u), v(_v), cap(_cap) {}
};

struct Graph {
	vector<vector<int>> nodes; int n;
	vector<Edge> edges; int m = 0;
	vector<int> parent;

	Graph(int _n) : n(_n), nodes(_n), parent(_n) {}

	void addEdge(int u, int v, ll c1, ll c2 = 0) {
		nodes[u].emplace_back(m++);
		nodes[v].emplace_back(m++);
		edges.emplace_back(u, v, c1); 
		edges.emplace_back(v, u, c2); 
	}

	ll maxflow(int s, int t, ll prevFlow = 0) {
		ll flow = prevFlow, newFlow = maxFlowBFS(s, t, parent);

		while (newFlow) {
			flow += newFlow; int cur = t;
			while (cur != s) {
				int &e = parent[cur];
				edges[e].cap -= newFlow; edges[e ^ 1].cap += newFlow;
				edges[e].flow += newFlow; edges[e ^ 1].flow -= newFlow;
				cur = edges[e].u;
			}
			newFlow = maxFlowBFS(s, t, parent);
		}
		return flow;
	}

	ll maxFlowBFS(const int &s, const int &t, vector<int> &parent) {
		fill(parent.begin(), parent.end(), -1); parent[s] = -2;
		queue<pair<int, ll>> q; q.push({ s, INF }); 

		while (!q.empty()) {
			int cur = q.front().first; ll flow = q.front().second; q.pop();
			for (auto &e : nodes[cur]) {
				int &next = edges[e].v;
				if (parent[next] == -1 && edges[e].cap) {
					parent[next] = e;
					ll newFlow = min(flow, edges[e].cap);
					if (next == t) { return newFlow; }
					q.push({ next, newFlow });
				}
			}
		}
		return 0ll;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}