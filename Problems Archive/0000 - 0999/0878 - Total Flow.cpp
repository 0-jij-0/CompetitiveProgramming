#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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

struct E { char u, v; int w; };

map<char, int> m;
vector<E> edges;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; edges.resize(n);
	for (int i = 0; i < n; i++) {
		E e; cin >> e.u >> e.v >> e.w;
		m[e.u]++; m[e.v]++; edges.push_back(e);
	}
	graph g(m.size()); int i = 0;
	for (auto &x : m) { x.second = i++; }
	for (auto &x : edges)
		g.add_edge(m[x.u], m[x.v], x.w);

	cout << g.maxflow(m['A'], m['Z']) << endl;
	cin.ignore(2); return 0;
}