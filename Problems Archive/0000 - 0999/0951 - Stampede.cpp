#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;
ll INF = 1ll << 40;

struct edge {
	int u, v, id, dual; edge() {}
	edge(int _u, int _v, int _id, int _d) :
		u(_u), v(_v), id(_id), dual(_id + _d) {}
};

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<edge> edges;
	vector<ll> capacity;
	vector<int> parent;

	graph(int _n) : n(_n), nodes(_n), parent(_n) {}

	void add_edge(int u, int v, ll c) {
		nodes[u].edges.emplace_back(capacity.size());
		nodes[v].edges.emplace_back(capacity.size() + 1);
		edges.emplace_back(u, v, capacity.size(), 1);
		edges.emplace_back(v, u, capacity.size() + 1, -1);
		capacity.push_back(c); capacity.push_back(0); //Change if undirected
	}

	ll maxflow(int s, int t, int prevFlow = 0) {
		ll flow = prevFlow, new_flow = maxFlowBFS(s, t, parent);

		while (new_flow) {
			flow += new_flow; int cur = t;
			while (cur != s) {
				edge &e = edges[parent[cur]];
				capacity[e.id] -= new_flow;
				capacity[e.dual] += new_flow;
				cur = e.u;
			}
			new_flow = maxFlowBFS(s, t, parent);
		}
		return flow;
	}

	ll maxFlowBFS(const int &s, const int &t, vector<int> &parent) {
		fill(parent.begin(), parent.end(), -1); parent[s] = -2;
		queue<pair<int, ll>> q; q.push({ s, INF });

		while (!q.empty()) {
			int cur = q.front().first; ll flow = q.front().second; q.pop();
			for (auto &e : nodes[cur].edges) {
				int next = edges[e].v, id = edges[e].id;
				if (parent[next] == -1 && capacity[id]) {
					parent[next] = e;
					ll new_flow = min(flow, capacity[id]);
					if (next == t) { return new_flow; }
					q.push({ next, new_flow });
				}
			}
		}
		return 0ll;
	}
};

vector<string> v; int n;
int in(int i, int j, int d) { return 2 * (n * n * d + i * n + j); }
int out(int i, int j, int d) { return 2 * (n * n * d + i * n + j) + 1; }
int snk(int i) { return 2 * n * n * n * n + i; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int test = 1; cin >> n; while (n) {
		v.resize(n); for (auto &x : v) { cin >> x; }
		graph g(2 * n * n * n * n + n + 2); int turns = n - 1;
		int source = g.n - 2, sink = g.n - 1;
		for (int i = 0; i < n; i++) {
			g.add_edge(source, in(i, 0, 0), 1);
			g.add_edge(snk(i), sink, 1);
			for (int j = 0; j < n; j++) {
				if (v[i][j] == 'X') { continue; }
				for (int t = 0; t <= turns; t++) {
					if (j == n - 1) { g.add_edge(out(i, j, t), snk(i), 1); }
					g.add_edge(in(i, j, t), out(i, j, t), 1); //Edge in->out
					g.add_edge(out(i, j, t), in(i, j, t + 1), 1); //Edge for waiting
					if (i != 0 && v[i - 1][j] != 'X') { g.add_edge(out(i, j, t), in(i - 1, j, t + 1), 1); }
					if (j != 0 && v[i][j - 1] != 'X') { g.add_edge(out(i, j, t), in(i, j - 1, t + 1), 1); }
					if (i != n - 1 && v[i + 1][j] != 'X') { g.add_edge(out(i, j, t), in(i + 1, j, t + 1), 1); }
					if (j != n - 1 && v[i][j + 1] != 'X') { g.add_edge(out(i, j, t), in(i, j + 1, t + 1), 1); }
				}
			}
		}
		int maxFlow = g.maxflow(source, sink);
		while (maxFlow != n) {
			turns++; for(int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					if (v[i][j] == 'X') { continue; }
					g.add_edge(in(i, j, turns), out(i, j, turns), 1); //Edge in->out
					g.add_edge(out(i, j, turns), in(i, j, turns + 1), 1); //Edge for waiting
					if (j == n - 1) { g.add_edge(out(i, j, turns), snk(i), 1); }
					if (i != 0 && v[i - 1][j] != 'X') { g.add_edge(out(i, j, turns), in(i - 1, j, turns + 1), 1); }
					if (j != 0 && v[i][j - 1] != 'X') { g.add_edge(out(i, j, turns), in(i, j - 1, turns + 1), 1); }
					if (i != n - 1 && v[i + 1][j] != 'X') { g.add_edge(out(i, j, turns), in(i + 1, j, turns + 1), 1); }
					if (j != n - 1 && v[i][j + 1] != 'X') { g.add_edge(out(i, j, turns), in(i, j + 1, turns + 1), 1); }
				}
			maxFlow = g.maxflow(source, sink, maxFlow);
		}
		cout << "Case " << test++ << ": " << turns << endl; cin >> n;
	}

	cin.ignore(2); return 0;
}