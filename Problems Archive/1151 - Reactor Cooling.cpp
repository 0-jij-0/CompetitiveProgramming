#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
using namespace std;
typedef long long ll;
ll INF = 1ll << 40;

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) : u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes;
	vector<vector<ll>> capacity;
	vector<int> parent; int n;

	graph(int _n) : n(_n), parent(_n), nodes(_n), capacity(_n, vector<ll>(_n)) {}

	void add_edge(int u, int v, ll c) {
		nodes[u].edges.emplace_back(u, v, c);
		nodes[v].edges.emplace_back(v, u, c);
		capacity[u][v] += c;	//directed edge
	}

	//O(VE^2)
	ll maxflow(int s, int t, ll prevFlow = 0) {
		ll flow = prevFlow, new_flow = maxFlowBFS(s, t, parent);

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

vector<edge> edges;
vector<int> DS, LB;

int main() {
	ifstream ifs("cooling.in");
	ofstream ofs("cooling.out");

	int n, m; ifs >> n >> m; 
	graph g(n + 2);
	DS.resize(n); edges.resize(m); LB.resize(m);
	for (int i = 0; i < m; i++) {
		int u, v, l, c; ifs >> u >> v >> l >> c;
		u--; v--; g.add_edge(u, v, c - l); LB[i] = l;
		DS[u] += l; DS[v] -= l; edges[i] = edge(u, v, c - l);
	}
	ll reqS = 0, reqT = 0;
	for (int i = 0; i < n; i++) {
		if (DS[i] > 0) { reqT += DS[i]; g.add_edge(i, n + 1, DS[i]); }
		if (DS[i] < 0) { reqS -= DS[i]; g.add_edge(n, i, -DS[i]); }
	}
	ll res = g.maxflow(n, n + 1);
	if (reqS != reqT || reqS != res) { ofs << "NO" << '\n'; return 0; }
	ofs << "YES" << '\n';
	for (int i = 0; i < m; i++) {
		int &u = edges[i].u, &v = edges[i].v; ll &c = edges[i].w;
		ofs << LB[i] + c - g.capacity[u][v] << '\n';
	}

	return 0;
}

