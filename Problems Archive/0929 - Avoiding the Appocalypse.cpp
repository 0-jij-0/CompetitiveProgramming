#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
		edges.emplace_back(u, v, capacity.size() + 1, -1);
		capacity.push_back(c); capacity.push_back(0); //Change if undirected
	}

	ll maxflow(int s, int t) {
		ll flow = 0, new_flow = maxFlowBFS(s, t, parent);

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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int n, s, g, t; cin >> n >> s >> g >> t; s--; t++;
		int source = n * t, sink = n * t + 1; graph G(n * (t + 1) + 2); 
		G.add_edge(source, s * t, g); int m; cin >> m;

		for (int i = 0; i < m; i++) {
			int d; cin >> d; d--;
			for (int i = 0; i < t; i++)
				G.add_edge(d * t + i, sink, INF);
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < t - 1; j++)
				G.add_edge(i * t + j, i * t + j + 1, INF);

		int r; cin >> r;
		for (int i = 0; i < r; i++) {
			int a, b, p, d; cin >> a >> b >> p >> d; a--; b--;
			for (int i = 0; i < t - d; i++)
				G.add_edge(a * t + i, b * t + i + d, p);
		}

		cout << G.maxflow(source, sink) << '\n';
	}

	cin.ignore(2); return 0;
}