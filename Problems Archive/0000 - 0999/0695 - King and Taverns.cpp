#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

struct edge {
	int u, v;
	bool closable;
	edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v), closable(false) {}
};

struct node {
	int id; vector<int> edges;
};

struct graph {
	vector<node> nodes; vector<pair<edge, edge>> edges;
	vector<int> accessible;
	vector<bool> dead;
	int n;

	graph(int _n) : n(_n) { nodes.resize(n); dead.resize(n, false); }

	void add_edge(int u, int v) {
		edge e1(u, v); nodes[u].edges.push_back(edges.size());
		edge e2(v, u); nodes[v].edges.push_back(edges.size());
		edges.push_back({ e1, e2 });
	}

	void bfs() {
		queue<int> Q;
		for (auto x : accessible) { Q.push(x); dead[x] = 1; }
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (auto &eIdx : nodes[cur].edges) {
				auto &e = edges[eIdx].first;
				if (e.u != cur) { e = edges[eIdx].second; }

				if (e.closable || dead[e.v]) { continue; }
				dead[e.v] = 1; Q.push(e.v);
			}
		}
	}

	int safe() {
		int res = -1;
		for (int i = 0; i < n; i++) {
			if (dead[i]) { continue; }
			res = i; break;
		}
		return res;
	}
};

int main() {
	int N, M, P; cin >> N >> M >> P;
	graph g(N);

	for (int i = 0; i < P; i++) {
		int temp; cin >> temp; temp--;
		g.accessible.push_back(temp);
	}
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v; u--; v--;
		g.add_edge(u, v);
	}
	for (int u = 0; u < N; u++) {
		int k; cin >> k;
		while (k--) {
			int v; cin >> v; v--;
			if (g.edges[v].first.u == u) { g.edges[v].second.closable = true; }
			else { g.edges[v].first.closable = true; }
		}
	}

	g.bfs();
	int res = g.safe();
	if (res == -1) { cout << "Impossible" << endl; }
	else { cout << res + 1 << endl; }
}