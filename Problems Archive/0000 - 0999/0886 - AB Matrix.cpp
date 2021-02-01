#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
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
		//capacity[v][u] += c; //if undirected edge
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

map<pair<pair<int, int>, pair<int, int>>, vector<vector<bool>>> cache;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, m, a, b; cin >> n >> m >> a >> b;
		if (cache.count({ {n, m}, {a, b} })){
			cout << "YES" << '\n';
			vector<vector<bool>> &res = cache[{ {n, m}, { a, b }}];
			for (auto &x : res) { for (auto y : x) cout << y; cout << '\n'; }
			continue;
		}
		if (n * a != m * b) { cout << "NO" << '\n'; continue; }
		graph g(n + m + 2);
		for (int i = 1; i <= n; i++)
			g.add_edge(0, i, a);
		for (int j = n + 1; j <= n + m; j++)
			g.add_edge(j, n + m + 1, b);
		for (int i = 1; i <= n; i++)
			for (int j = n + 1; j <= n + m; j++)
				g.add_edge(i, j, 1);
		g.maxflow(0, n + m + 1); cout << "YES" << '\n';
		vector<vector<bool>> res(n, vector<bool>(m));
		for (int i = 1; i <= n; i++)
			for (int j = n + 1; j <= n + m; j++)
				res[i - 1][j - n - 1] = (g.capacity[i][j] == 0);
		for (auto &x : res) { for (auto y : x) cout << y; cout << '\n';	}
		cache[{ {n, m}, { a, b } }] = move(res);
	}

	cin.ignore(2); return 0;
}