#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
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
	vector<int> parent;
	int n;

	graph(int _n) : n(_n) {
		nodes.resize(n);
		capacity.resize(n, vector<ll>(n, 0));
	}

	void add_edge(int u, int v, ll c) {
		edge e1(u, v); nodes[u].edges.push_back(e1);
		edge e2(v, u); nodes[v].edges.push_back(e2);
		capacity[u][v] = c; //directed edge
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

vector<int> won, rem;

int main() {
	int n; cin >> n; won.resize(n);	rem.resize(n); graph g(n*n + n + 2);
	int source = n * n + n, sink = n * n + n + 1;
	for (auto &x : won) { cin >> x; }
	for (auto &x : rem) { cin >> x; }
	int sMax = won[0] + rem[0];
	if (*max_element(won.begin() + 1, won.end()) > sMax) { cout << "NO" << endl; return 0; }
	for (int i = n * n + 1; i < n*n + n; i++)
		g.add_edge(i, sink, sMax - won[i - n*n]);

	int total = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int idx = i * n + j; int x; cin >> x;
			if (j <= i || i == 0) { continue; }
			g.add_edge(idx, i + n*n, INF);
			g.add_edge(idx, j + n*n, INF);
			g.add_edge(source, idx, x); total += x;
		}

	bool b = g.maxflow(source, sink) == total;
	cout << (b ? "YES" : "NO") << endl;
	cin.ignore(2); return 0;
}