#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
using namespace std;
typedef int ll;

struct edge {
	int u, v, id; edge() {}
	edge(int _u, int _v, int _id) : u(_u), v(_v), id(_id) {}
};

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes;
	vector<edge> edges;
	vector<vector<ll>> capacity;
	int n;

	graph(int _n) : n(_n) { nodes.resize(n); capacity.resize(n, vector<ll>(n, 0)); }

	void add_edge(int u, int v, ll c) {
		nodes[u].edges.push_back(edges.size());
		edges.push_back(edge(u, v, edges.size()));
		nodes[v].edges.push_back(edges.size());
		edges.push_back(edge(v, u, edges.size()));
		capacity[u][v] += c;
	}

	//O(VE^2)
	ll maxflow(int s, int t) {
		vector<int> parent(n);
		ll flow = 0, new_flow = maxFlowBFS(s, t, parent);

		while (new_flow) {
			flow += new_flow;
			int cur = t;
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
		fill(parent.begin(), parent.end(), -1);
		parent[s] = -2;
		queue<pair<int, ll>> q; q.push({ s, 1 << 30 });

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
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n; graph g(n);
		for (int i = 0; i < n - 1; i++) {
			int m; cin >> m;
			for (int j = 0; j < m; j++) {
				int x; cin >> x; x--;
				int w = (i == 0 || x == n - 1) ? 1 : 1000;
				g.add_edge(i, x, w);
			}
		}
		cout << g.maxflow(0, n - 1) << endl;
	}

	cin.ignore(2); return 0;
}