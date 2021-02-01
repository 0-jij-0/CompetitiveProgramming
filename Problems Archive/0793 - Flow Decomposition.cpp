#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
ll INF = 1ll << 60;

struct edge {
	int u, v, id; ll w; edge() {}
	edge(int _u, int _v, ll _w, int _id) : u(_u), v(_v), w(_w), id(_id) {}
};

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes;
	vector<edge> edges;
	vector<vector<ll>> capacity, edgeFlow;
	int n;

	graph(int _n) : n(_n) { nodes.resize(n); capacity.resize(n, vector<ll>(n, 0)); edgeFlow.resize(n, vector<ll>(n, 0)); }

	void add_edge(int u, int v, ll c) {
		nodes[u].edges.push_back(edges.size()); edges.push_back(edge(u, v, c, edges.size()));
		nodes[v].edges.push_back(edges.size()); edges.push_back(edge(v, u, 0, edges.size()));
		capacity[u][v] += c;
	}

	//O(VE^2)
	ll maxflow(int s, int t) {
		vector<int> parent(n);
		ll flow = 0, new_flow = bfs(s, t, parent);

		while (new_flow) {
			flow += new_flow;
			int cur = t;
			while (cur != s) {
				int prev = parent[cur];
				edgeFlow[prev][cur] += new_flow;
				edgeFlow[cur][prev] -= new_flow;

				capacity[prev][cur] -= new_flow;
				capacity[cur][prev] += new_flow;
				cur = prev;
			}
			new_flow = bfs(s, t, parent);
		}

		return flow;
	}
	ll bfs(int s, int t, vector<int>& parent) {
		fill(parent.begin(), parent.end(), -1);
		parent[s] = -2;
		queue<pair<int, ll>> q; q.push({ s, INF });

		while (!q.empty()) {
			int cur = q.front().first; ll flow = q.front().second; q.pop();
			for (auto &eIdx : nodes[cur].edges) {
				int next = edges[eIdx].v;
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
	ll dfs(int cur, const int &dest, ll curFlow, vector<int> &path, vector<int> &vis) {
		if (curFlow <= 0) { return 0; }
		if (cur == dest) { return curFlow; }
		vis[cur] = 1;
		for (auto &eIdx : nodes[cur].edges) {
			auto &e = edges[eIdx];
			if (vis[e.v] || e.w == 0 || edgeFlow[cur][e.v] <= 0) { continue; }
			path.push_back(e.id);
			ll nextFlow = min({ curFlow, edgeFlow[cur][e.v], e.w });
			ll x = dfs(e.v, dest, nextFlow, path, vis);
			if (x) { return x; }
			path.pop_back();
		}
		return 0;
	}
};

vector<pair<ll, vector<int>>> res;

int main() {
	int n, m; cin >> n >> m;
	graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		u--; v--; g.add_edge(u, v, c);
	}
	ll f = g.maxflow(0, n - 1);
	vector<int> path, vis(n, 0);
	f = g.dfs(0, n - 1, INF, path, vis);
	while (f) {
		res.push_back({ f, path });
		for (auto &x : path) {
			edge &e = g.edges[x]; e.w -= f;
			g.edgeFlow[e.u][e.v] -= f;
		}
		path.clear(); vis.clear(); vis.resize(n, 0);
		f = g.dfs(0, n - 1, INF, path, vis);
	}

	cout << res.size() << endl;
	for (auto &x : res) {
		cout << x.first << ' ' << x.second.size() << ' ';
		for (auto &y : x.second) { cout << (y / 2) + 1 << ' '; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}