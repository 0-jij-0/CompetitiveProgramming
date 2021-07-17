#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edge {
	int u, v; bool match = 0; edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node { vector<edge> edges; node() {} };

struct bipartiteGraph {
	vector<node> nodes; int n, m;
	vector<bool> Z, vis;
	vector<int> unMatched, match;

	bipartiteGraph(int _n, int _m) : n(_n), m(_m),
		nodes(_n + _m), Z(_n + _m, 0), match(_n + _m, -1), vis(_n + _m, 0) {}

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	bool augment(int v) {
		if (v == -1) { return 1; }
		if (vis[v]) { return 0; }
		vis[v] = 1; for (auto &e : nodes[v].edges)
			if (augment(match[e.v])) {
				match[e.v] = v; match[v] = e.v;
				return 1;
			}
		return 0;
	}

	int maxMatching() {
		int w = 0;
		for (int x = 0; x < n; x++) {
			if (match[x] != -1) { continue; }
			for (auto &e : nodes[x].edges)
				if (match[e.v] == -1) {
					match[e.v] = x; match[x] = e.v;
					w++; break;
				}
		}
		for (int i = 0; i < n; i++) {
			if (match[i] != -1) { continue; }
			for (int j = 0; j < n; j++) { vis[j] = 0; }
			w += augment(i);
		}
		return w;
	}

	void vertexCoverDFS(int u, bool m, vector<bool>& visited) {
		visited[u] = Z[u] = 1;
		for (auto &e : nodes[u].edges)
			if (!visited[e.v] && e.match != m)
				vertexCoverDFS(e.v, e.match, visited);
	}

	vector<pair<int, int>> vertexCover() {
		int K = maxMatching();
		for (int u = 0; u < n; u++) {
			if (match[u] == -1) { unMatched.push_back(u); continue; }
			int v = match[u];
			for (auto &e : nodes[u].edges)
				if (e.v == v) { e.match = 1; break; }
			for (auto &e : nodes[v].edges)
				if (e.v == u) { e.match = 1; break; }
		}

		vector<bool> visited(n + m, 0); for (auto &x : unMatched)
			if (!visited[x]) { vertexCoverDFS(x, 1, visited); }

		vector<pair<int, int>> ans;
		for (int i = 0; i < n; i++)	if (!Z[i]) ans.push_back({ 1, i + 1 });
		for (int i = n; i < m + n; i++)	if (Z[i]) ans.push_back({ 2, i - n + 1 });
		return move(ans);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; bipartiteGraph g(n, n);
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char c; cin >> c; if (c == 'o')
				g.add_edge(i, n + j);
		}

	vector<pair<int, int>> res = g.vertexCover();
	cout << res.size() << '\n';
	for (auto &x : res) cout << x.first << ' ' << x.second << '\n';
	cin.ignore(2); return 0;
}