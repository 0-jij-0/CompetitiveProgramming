#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int INF = 1 << 20;

struct edge {
	int u, v, id, dual; edge() {}
	edge(int _u, int _v, int _id, int _d) :
		u(_u), v(_v), id(_id), dual(_id + _d) {}
};

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<edge> edges;
	vector<int> capacity;
	vector<int> parent;

	graph(int _n) : n(_n), nodes(_n), parent(_n) {}

	void add_edge(int u, int v, int c) {
		nodes[u].edges.emplace_back(capacity.size());
		nodes[v].edges.emplace_back(capacity.size() + 1);
		edges.emplace_back(u, v, capacity.size(), 1);
		edges.emplace_back(v, u, capacity.size() + 1, -1);
		capacity.push_back(c); capacity.push_back(0); //Change if undirected
	}

	int maxflow(int s, int t, int prevFlow = 0) {
		int flow = prevFlow, new_flow = maxFlowBFS(s, t, parent);

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

	int maxFlowBFS(const int &s, const int &t, vector<int> &parent) {
		fill(parent.begin(), parent.end(), -1); parent[s] = -2;
		queue<pair<int, int>> q; q.push({ s, INF });

		while (!q.empty()) {
			int cur = q.front().first; int flow = q.front().second; q.pop();
			for (auto &e : nodes[cur].edges) {
				int next = edges[e].v, id = edges[e].id;
				if (parent[next] == -1 && capacity[id]) {
					parent[next] = e;
					int new_flow = min(flow, capacity[id]);
					if (next == t) { return new_flow; }
					q.push({ next, new_flow });
				}
			}
		}
		return 0ll;
	}
};

vector<int> deg;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n1, n2, m; cin >> n1 >> n2 >> m;
	graph g(n1 + n2 + 2); deg.resize(n1 + n2);
	int source = g.n - 2, sink = g.n - 1;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; 
		u--; v--; deg[u]++; deg[v + n1]++;
		g.add_edge(u, v + n1, 1);
	}

	int minDeg = *min_element(deg.begin(), deg.end());
	vector<vector<int>> res(minDeg + 1); int maxFlow = 0;
	for (int i = 0; i < n1; i++) { g.add_edge(source, i, deg[i] - minDeg); }
	for (int i = 0; i < n2; i++) { g.add_edge(n1 + i, sink, deg[i + n1] - minDeg); }

	for (int i = minDeg; i >= 0; i--) {
		maxFlow = g.maxflow(source, sink, maxFlow);
		res[i].push_back(m - maxFlow);
		for (int j = 0; j < m; j++) 
			if (g.capacity[2 * j]) { res[i].push_back(j + 1); }
		for (int j = 0; j < n1 + n2; j++) g.capacity[2 * (m + j)]++;
	}

	for (auto &x : res) { for (auto &y : x) cout << y << ' '; cout << '\n'; }
	cin.ignore(2); return 0;
}