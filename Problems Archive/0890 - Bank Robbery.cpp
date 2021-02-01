#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
ll INF = 1ll << 40;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<vector<ll>> capacity;
	vector<int> parent;

	graph(int _n) : n(_n) { nodes.resize(n); capacity.resize(n, vector<ll>(n, 0)); }

	void add_edge(int u, int v, int c) {
		nodes[u].edges.push_back(edge(u, v));
		nodes[v].edges.push_back(edge(v, u));
		capacity[u][v] += c;
		if (abs(u - v) == 1 && v % 2) { capacity[v][u] += c; } //if undirected edge
	}

	//O(VE^2)
	ll maxflow(int s, int t) {
		parent.resize(n);
		ll flow = 0, new_flow = maxFlowBFS(s, t, parent);

		while (new_flow) {
			flow += new_flow; int cur = t;
			while (cur != s) {
				int prev = parent[cur];
				capacity[prev][cur] -= new_flow;
				capacity[cur][prev] += new_flow;
				cur = prev;
			}
			new_flow = maxFlowBFS(s, t, parent);
		}
		return flow;
	}

	ll maxFlowBFS(int s, int t, vector<int>& parent) {
		fill(parent.begin(), parent.end(), -1);	parent[s] = -2;
		queue<pair<int, ll>> q; q.push({ s, INF });

		while (!q.empty()) {
			int cur = q.front().first; ll flow = q.front().second; q.pop();
			for (auto &e : nodes[cur].edges) {
				int next = e.v;
				if (parent[next] == -1 && capacity[cur][next]) {
					parent[next] = cur;
					ll new_flow = min(flow, capacity[cur][next]);
					if (next == t) { return new_flow; }
					q.push({ next, new_flow });
				}
			}
		}
		return 0;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; graph g(2*n);
	int s, t; cin >> s >> t; s--; t--;
	for (int i = 0; i < n; i++) { 
		if (i != s && i != t) { g.add_edge(2 * i, 2 * i + 1, 1); }
		else { g.add_edge(2 * i, 2 * i + 1, 1 << 20); }
	}
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--; 
		g.add_edge(2 * a + 1, 2 * b, 1 << 20);
		g.add_edge(2 * b + 1, 2 * a, 1 << 20);
	}
	cout << g.maxflow(2 * s, 2 * t + 1) << '\n';
	cin.ignore(2); return 0;
}