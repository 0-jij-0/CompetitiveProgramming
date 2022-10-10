#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1ll << 40;

struct edge {
	int u, v; bool b; edge() {}
	edge(int _u, int _v, bool _b) : u(_u), v(_v), b(_b) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes;
	vector<vector<ll>> capacity;
	vector<vector<ll>> FLOW;
	vector<int> parent; int n;

	graph(int _n) : n(_n), parent(_n), nodes(_n), capacity(_n, vector<ll>(_n)), FLOW(_n, vector<ll>(_n)) {}

	void add_edge(int u, int v, ll c) {
		nodes[u].edges.emplace_back(u, v, true);
		nodes[v].edges.emplace_back(v, u, false);
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
				FLOW[prev][cur] += new_flow;
				FLOW[cur][prev] -= new_flow;
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

	ll pathCoverDFS(int cur, const int &t, int p, vector<int> &v) {
		if (cur == t) { v.push_back(t); return INF; }
		v.push_back(cur); for (edge &e : nodes[cur].edges) {
			if (!e.b || e.v == p || !FLOW[cur][e.v]) { continue; }
			ll x = pathCoverDFS(e.v, t, cur, v);
			if (x) { return min(FLOW[cur][e.v], x); }
			if (pathCoverDFS(e.v, t, cur, v)) return true;
		}
		v.pop_back(); return 0;
	}

	vector<vector<int>> pathCover(int s, int t) {
		vector<vector<int>> res; maxflow(s, t);
		vector<int> v; int f; while (f = pathCoverDFS(s, t, -1, v)) {
			int N = (int)v.size();
			for (int i = 1; i < N; i++) { FLOW[v[i - 1]][v[i]] -= f; }
			res.push_back(v); v.clear();
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v, 1);
	}
	vector<vector<int>> res = g.pathCover(0, n - 1);
	cout << res.size() << endl; for (auto &x : res) {
		cout << x.size() << endl; for (auto &y : x)
			cout << y + 1 << ' '; cout << '\n';
	}
}

