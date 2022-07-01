#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
using namespace std;

struct edge {
	int u, v; bool match = 0; edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node { int id; vector<edge> edges; node() {} };

struct graph {
	vector<node> nodes; int n;
	vector<edge> edges;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
		edges.emplace_back(u, v);
	}

	bool dfs(int cur, vector<bool>& vis, vector<bool>& col) {
		int newCol = (col[cur] & 1) ^ 1;
		for (edge& e : nodes[cur].edges) {
			if (vis[e.v] && col[cur] == col[e.v]) { return false; }
			if (vis[e.v]) { continue; }
			col[e.v] = newCol; vis[e.v] = true;
			if (!dfs(e.v, vis, col)) { return false; }
		}
		return true;
	}
};

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
		vis[v] = 1; for (auto& e : nodes[v].edges)
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
			for (auto& e : nodes[x].edges)
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
		for (auto& e : nodes[u].edges)
			if (!visited[e.v] && e.match != m)
				vertexCoverDFS(e.v, e.match, visited);
	}

	vector<pair<int, int>> vertexCover() {
		int K = maxMatching();
		for (int u = 0; u < n; u++) {
			if (match[u] == -1) { unMatched.push_back(u); continue; }
			int v = match[u];
			for (auto& e : nodes[u].edges)
				if (e.v == v) { e.match = 1; break; }
			for (auto& e : nodes[v].edges)
				if (e.v == u) { e.match = 1; break; }
		}

		vector<bool> visited(n + m, 0); for (auto& x : unMatched)
			if (!visited[x]) { vertexCoverDFS(x, 1, visited); }

		vector<pair<int, int>> ans;
		for (int i = 0; i < n; i++)	if (!Z[i]) ans.push_back({ 1, i });
		for (int i = n; i < m + n; i++)	if (Z[i]) ans.push_back({ 2, i - n });
		return move(ans);
	}
};

vector<string> G;
int di[3] = { 1, -1, -1 };
int dj[3] = { 1, 0, 1 };

int main() {
	freopen("event.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; G.resize(n);
		for (auto& x : G) cin >> x;

		graph g(n * m);
		for (int x = 0; x < n * m; x++) {
			int i = x / m, j = x % m;
			if (G[i][j] == '*') { continue; }
			for (int k = 0; k < 3; k++) {
				if (i + di[k] >= n || i + di[k] < 0) { continue; }
				if (j + dj[k] >= m) { continue; }
				if (G[i + di[k]][j + dj[k]] == '*') { continue; }
				g.add_edge(x, (i + di[k]) * m + j + dj[k]);
			}
		}

		vector<bool> vis2col(n * m, 0), col(n * m, 0);
		for (int x = 0; x < n * m; x++) {
			if (vis2col[x]) { continue; }
			int i = x / m, j = x % m;
			if (G[i][j] == '*') { continue; }
			vis2col[x] = true;
			assert(g.dfs(x, vis2col, col));
		}

		vector<int> L, R, inv(n * m);
		for (int x = 0; x < n * m; x++) if (vis2col[x]) {
			(col[x] ? R : L).push_back(x);
		}
		for (int i = 0; i < (int)L.size(); i++) inv[L[i]] = i;
		for (int i = 0; i < (int)R.size(); i++) inv[R[i]] = (int)L.size() + i;
		bipartiteGraph bg((int)L.size(), (int)R.size());

		for (edge& e : g.edges) bg.add_edge(inv[e.u], inv[e.v]);

		vector<pair<int, int>> vc = bg.vertexCover();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (G[i][j] != '*') G[i][j] = '#';

		for (auto& x : vc) {
			int y = x.first == 1 ? L[x.second] : R[x.second];
			G[y / m][y % m] = '.';
		}
		cout << (int) bg.n + bg.m - vc.size() << '\n';
		for (auto& x : G) cout << x << '\n';
	}
}