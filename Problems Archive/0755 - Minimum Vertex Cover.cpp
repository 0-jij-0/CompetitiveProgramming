#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>
using namespace std;
const int MAXV = 8005;

int match[MAXV];
bool vis[MAXV];

struct edge {
	int u, v; bool matched; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {
		matched = false;
	}
};

struct node { bool matched; vector<edge> edges; node() { matched = false; } };


struct bipartiteGraph {
	vector<node> nodes; int n, m;
	vector<bool> Z;

	bipartiteGraph(int _n, int _m) : n(_n), m(_m) { nodes.resize(n + m); Z.resize(n + m, 0); }

	void add_edge(int u, int v) {
		edge e1(u, v); nodes[u].edges.push_back(e1);
		edge e2(v, u); nodes[v].edges.push_back(e2);
	}

	void dfs(int u, bool m, vector<bool>& visited) {
		visited[u] = Z[u] = 1;
		for (auto &e : nodes[u].edges) {
			if (visited[e.v] || e.matched == m) { continue; }
			dfs(e.v, e.matched, visited);
		}
	}

	vector<pair<int, int>> vertexCover() {
		vector<bool> visited(n + m, 0);
		for (int i = 0; i < n; i++) {
			if (nodes[i].matched || visited[i]) { continue; }
			dfs(i, 1, visited);
		}

		vector<pair<int, int>> ans;
		for (int i = 0; i < n; i++) {
			if (Z[i]) { continue; }
			ans.push_back({ 1,i + 1 });
		}
		for (int i = n; i < m + n; i++) {
			if (Z[i]) { ans.push_back({ 2, i - n + 1 }); }
		}
		return move(ans);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	bipartiteGraph g(n, m);
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		while (k--) {
			int cur; cin >> cur;
			g.add_edge(i, cur + n - 1);
		}
	}

	for (int u = 0; u < n; u++) {
		int v; cin >> v;
		if (v == 0) { continue; }
		v--; v += n;
		for (auto &e : g.nodes[u].edges) {
			if (e.v == v) {
				e.matched = g.nodes[u].matched = g.nodes[e.v].matched = 1;
				break;
			}
		}
		for (auto &e : g.nodes[v].edges) {
			if (e.v == u) { e.matched = 1; break; }
		}
	}

	vector<pair<int, int>> ans = g.vertexCover();
	cout << ans.size() << endl;
	vector<int> L, R;
	for (auto &p : ans) {
		if (p.first == 1) { L.push_back(p.second); }
		else { R.push_back(p.second); }
	}

	cout << L.size() << " ";
	for (auto &x : L) { cout << x << " "; }cout << endl;
	cout << R.size() << " ";
	for (auto &x : R) { cout << x << " "; }cout << endl;
}