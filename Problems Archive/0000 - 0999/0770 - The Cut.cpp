#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
ll INF = 1ll << 40;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes;
	vector<vector<ll>> capacity;
	vector<vector<ll>> inCapacity;
	vector<int> parent;
	vector<edge> edges;
	int n;

	graph(int _n) : n(_n) { nodes.resize(n); capacity.resize(n, vector<ll>(n, 0)); inCapacity.resize(n, vector<ll>(n, 0));}

	void add_edge(int u, int v, int c) {
		edge e1(u, v); nodes[u].edges.push_back(e1);
		edge e2(v, u); nodes[v].edges.push_back(e2);
		edges.push_back(e1);
		capacity[u][v] = c; capacity[v][u] = c;	//undirected edge
		inCapacity[u][v] = inCapacity[v][u] = c;
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
				capacity[prev][cur] -= new_flow;
				capacity[cur][prev] += new_flow;
				cur = prev;
			}
			new_flow = bfs(s, t, parent);
		}

		return flow;
	}
private:
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
};

int main() {
	int n, m; cin >> n >> m;
	graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c; 
		u--; v--; g.add_edge(u, v, c);
	}
	ll x = g.maxflow(0, n - 1);
	set<int> cutNode; cutNode.insert(0);
	for (int i = 0; i < n; i++) 
		if (g.parent[i] > -1) { cutNode.insert(i); }

	set<int> cutEdge;
	for (int i = 0; i < m; i++)
		if (cutNode.count(g.edges[i].u) ^ cutNode.count(g.edges[i].v)) { cutEdge.insert(i); }

	cout << cutEdge.size() << ' ' << x << endl;
	for (auto &x : cutEdge) { cout << x + 1 << ' '; }
	cout << endl; cin.ignore(2); return 0;
}