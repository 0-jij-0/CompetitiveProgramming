#include <iostream>
#include <vector>
#include <algorithm>
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		u--; v--; g.add_edge(u, v, c);
	}
	cout << g.maxflow(0, n - 1) << endl;
	cin.ignore(2); return 0;
}