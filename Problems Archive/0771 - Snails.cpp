#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
using namespace std;
typedef long long ll;
ll INF = 1ll << 40;

vector<vector<int>> res;

struct edge {
	int u, v, id; edge() {}
	edge(int _u, int _v, int _id) : u(_u), v(_v), id(_id) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes;
	vector<map<int, ll>> capacity;
	vector<map<int, ll>> flowCap;
	vector<int> parent;
	vector<edge> edges;
	int n;

	graph(int _n) : n(_n) {
		nodes.resize(n);
		capacity.resize(n);
		flowCap.resize(n);
	}

	void add_edge(int u, int v, int c) {
		edge e1(u, v, edges.size()); nodes[u].edges.push_back(e1);
		edge e2(v, u, edges.size() + 1); nodes[v].edges.push_back(e2);
		edges.push_back(e1); edges.push_back(e2);
		capacity[u][v] += c; //undirected edge
	}

	//O(VE^2)
	ll maxflow(int s, int t) {
		parent.resize(n);
		ll flow = 0, new_flow = bfs(s, t, parent);

		while (new_flow) {
			flow += new_flow;
			int cur = t;
			while (cur != s) {
				int prev = parent[cur];
				capacity[prev][cur] -= new_flow; flowCap[prev][cur] += new_flow;
				capacity[cur][prev] += new_flow; flowCap[cur][prev] -= new_flow;
				cur = prev;
			}
			if (flow >= 2) { return true; }
			new_flow = bfs(s, t, parent);
		}

		return false;
	}

	ll bfs(int s, int t, vector<int>& parent) {
		fill(parent.begin(), parent.end(), -1);
		parent[s] = -2;
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


	bool dfs(int cur, const int &t, ll flow, vector<int> &path, vector<int> &col) {
		if (flow <= 0) { return false; }
		if (cur == t) { path.push_back(t); return true; }
		col[cur] = 1; path.push_back(cur);
		for (auto &e : nodes[cur].edges) {
			if (col[e.v]) { continue; }
			if (dfs(e.v, t, min(flow, flowCap[cur][e.v]), path, col)) {	return true; }
		}
		col[cur] = 0; path.pop_back(); return false;
	}
};

int main() {
	int n, m, s, t; cin >> n >> m >> s >> t;
	s--; t--; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v, 1);
	}
	if (!g.maxflow(s, t)) { cout << "NO" << endl; return 0; }
	vector<int> path, col(n, 0); g.dfs(s, t, INF, path, col);
	for (int i = 1; i < (int)path.size(); i++) {
		g.flowCap[path[i - 1]][path[i]]--;
		g.flowCap[path[i]][path[i - 1]]++;
	}
	res.push_back(path); path.clear(); col.clear(); col.resize(n, 0);
	g.dfs(s, t, INF, path, col); res.push_back(path);

	cout << "YES" << endl; assert(res.size() == 2);
	for (auto &x : res) { for (auto &y : x) cout << y + 1 << ' '; cout << endl; }
	cin.ignore(2); return 0;
}