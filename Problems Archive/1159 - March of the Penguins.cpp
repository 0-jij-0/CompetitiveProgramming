#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
typedef double ld;
ll INF = 1ll << 40;

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


bool check(graph g, int &s, int &t, int &c, int i) {
	g.add_edge(i, t, c); return g.maxflow(s, t) == c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; ld d; cin >> n >> d; graph g(2 * n + 2);
		int source = 2 * n, sink = 2 * n + 1; d *= d;
		vector<int> x(n), y(n), p(n), o(n), res;
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i] >> p[i] >> o[i];

		int numPen = 0; for (int i = 0; i < n; i++) {
			if (p[i]) g.add_edge(source, i, p[i]); 
			numPen += p[i]; g.add_edge(i, i + n, o[i]);
			for (int j = i + 1; j < n; j++) {
				int dx = x[i] - x[j], dy = y[i] - y[j];
				if (dx * dx + dy * dy <= d) { 
					g.add_edge(n + i, j, INF); 
					g.add_edge(n + j, i, INF);
				}
			}
		}

		for (int i = 0; i < n; i++)
			if (check(g, source, sink, numPen, i))
				res.push_back(i);

		if (res.empty()) { cout << -1 << '\n'; continue; }
		n = (int)res.size(); int i = 0; while (i != n) {
			cout << res[i]; i++;
			cout << (i == n ? '\n' : ' ');
		}
	}

	cin.ignore(2); return 0;
}