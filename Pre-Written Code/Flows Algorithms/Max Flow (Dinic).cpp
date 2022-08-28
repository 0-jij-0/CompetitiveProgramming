#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 40;

struct Edge {
	int u, v; ll cap, flow = 0; Edge() {}
	Edge(int _u, int _v, ll _cap) :
		u(_u), v(_v), cap(_cap) {}
};

struct Graph {
	vector<vector<int>> nodes; int n;
	vector<Edge> edges; int m = 0;
	vector<int> level, ptr;
	Graph(int _n) : n(_n), nodes(_n), level(_n), ptr(_n) {}

	void addEdge(int u, int v, ll c1, ll c2 = 0) {
		nodes[u].emplace_back(m++);
		nodes[v].emplace_back(m++);
		edges.emplace_back(u, v, c1); 
		edges.emplace_back(v, u, c2); 
	}

	bool dinicBFS(const int &s, const int &t) {
		fill(level.begin(), level.end(), -1);
		queue<int> Q; Q.push(s); level[s] = 0;

		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (auto &e : nodes[cur]) {
				if (edges[e].cap - edges[e].flow < 1) { continue; }
				if (level[edges[e].v] != -1) { continue; }
				level[edges[e].v] = level[cur] + 1;
				Q.push(edges[e].v);
			}
		}
		return level[t] != -1;
	}

	ll dinicDFS(int cur, const int &t, ll flow) {
		if (!flow) { return 0; }
		if (cur == t) { return flow; }
		for (int &cid = ptr[cur]; cid < (int)nodes[cur].size(); cid++) {
			int e = nodes[cur][cid], v = edges[e].v;
			if (level[cur] + 1 != level[v] || edges[e].cap - edges[e].flow < 1) continue;
			ll newFlow = min(flow, edges[e].cap - edges[e].flow);
			newFlow = dinicDFS(v, t, newFlow); if (!newFlow) { continue; }
			edges[e].flow += newFlow; edges[e ^ 1].flow -= newFlow;
			return newFlow;
		}
		return 0;
	}

	ll maxFlow(int s, int t, ll prevFlow = 0) {
		ll res = prevFlow;
		while (dinicBFS(s, t)) {
			fill(ptr.begin(), ptr.end(), 0);
			while (ll flow = dinicDFS(s, t, INF)) { res += flow; }
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}