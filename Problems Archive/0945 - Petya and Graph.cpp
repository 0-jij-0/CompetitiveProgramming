#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
ll INF = 1ll << 50;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes;
	vector<vector<ll>> capacity;
	vector<int> parent; int n;

	graph(int _n) : n(_n), parent(_n), nodes(_n), capacity(_n, vector<ll>(_n)) {}

	void add_edge(int u, int v, ll c) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
		capacity[u][v] = c;	//directed edge
	}

	//O(VE^2)
	ll maxflow(int s, int t) {
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
		fill(parent.begin(), parent.end(), -1); parent[s] = -2;
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
		return 0ll;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; graph g(n + m + 2);
	int source = g.n - 2, sink = g.n - 1; ll res = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; g.add_edge(m + i, sink, a);
	}
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--; res += w;
		g.add_edge(source, i, w);
		g.add_edge(i, m + u, INF); 
		g.add_edge(i, m + v, INF);
	}
	res -= g.maxflow(source, sink);
	cout << res << endl;
	cin.ignore(2); return 0;
}

