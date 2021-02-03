#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;
ll INF = 1ll << 40;

vector<int> w;

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
		capacity[u][v] += c;	//directed edge
		//capacity[v][u] += c;	//unidrected edge
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

vector<string> v; int n, m, c;

inline int in(int i, int j) { return i * m + j; }
inline int out(int i, int j) { return n * m + i * m + j; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n >> c; 
	v.resize(n); w.resize(c); 
	graph g(2 * n * m + 2);
	int source = g.n - 2, sink = g.n - 1;
	for (auto &x : v) { cin >> x; }
	for (auto &x : w) { cin >> x; }

	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'B') { g.add_edge(source, in(i, j), INF); }
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
				g.add_edge(out(i, j), sink, INF);
			bool b = v[i][j] == '.' || v[i][j] == 'B';
			g.add_edge(in(i, j), out(i, j), b ? INF : w[v[i][j] - 'a']);
			if (i != 0) { g.add_edge(out(i, j), in(i - 1, j), INF); }
			if (j != 0) { g.add_edge(out(i, j), in(i, j - 1), INF); }
			if (i != n - 1) { g.add_edge(out(i, j), in(i + 1, j), INF); }
			if (j != m - 1) { g.add_edge(out(i, j), in(i, j + 1), INF); }
		}

	ll res = g.maxflow(source, sink);
	cout << (res >= INF ? -1 : res) << '\n';
	cin.ignore(2); return 0;
}