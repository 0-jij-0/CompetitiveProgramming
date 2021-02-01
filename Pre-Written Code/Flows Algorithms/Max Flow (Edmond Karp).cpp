#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
ll INF = 1ll << 40;

struct edge {
	int u, v; ll cap, flow = 0; edge() {}
	edge(int _u, int _v, ll _cap) :
		u(_u), v(_v), cap(_cap) {}
};

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<edge> edges; int m;
	vector<int> parent;

	graph(int _n) : n(_n), nodes(_n), parent(_n) {}

	void add_edge(int u, int v, ll c1, ll c2 = 0) {
		nodes[u].edges.emplace_back(edges.size());
		nodes[v].edges.emplace_back(edges.size() + 1);
		edges.emplace_back(u, v, c1); m++;
		edges.emplace_back(v, u, c2); m++;
	}

	ll maxflow(int s, int t, ll prevFlow = 0) {
		ll flow = prevFlow, new_flow = maxFlowBFS(s, t, parent);

		while (new_flow) {
			flow += new_flow; int cur = t;
			while (cur != s) {
				int &e = parent[cur];
				edges[e].cap -= new_flow; edges[e ^ 1].cap += new_flow;
				edges[e].flow += new_flow; edges[e ^ 1].flow -= new_flow;
				cur = edges[e].u;
			}
			new_flow = maxFlowBFS(s, t, parent);
		}
		return flow;
	}

	ll maxFlowBFS(const int &s, const int &t, vector<int> &parent) {
		fill(parent.begin(), parent.end(), -1); parent[s] = -2;
		queue<pair<int, ll>> q; q.push({ s, INF }); 

		while (!q.empty()) {
			int cur = q.front().first; ll flow = q.front().second; q.pop();
			for (auto &e : nodes[cur].edges) {
				int &next = edges[e].v;
				if (parent[next] == -1 && edges[e].cap) {
					parent[next] = e;
					ll new_flow = min(flow, edges[e].cap);
					if (next == t) { return new_flow; }
					q.push({ next, new_flow });
				}
			}
		}
		return 0ll;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin.ignore(2); return 0;
}