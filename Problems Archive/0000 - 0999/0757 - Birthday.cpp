#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int MAXV = 305;

int match[MAXV];
bool vis[MAXV];

struct edge {
	int u, v; bool matched = 0; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { bool matched = 0; vector<edge> edges; };

struct bipartiteGraph {
	vector<node> nodes; int n, m;
	vector<int> Z;

	bipartiteGraph(int _n, int _m) : n(_n), m(_m) { nodes.resize(n + m); Z.resize(n + m, 0); }

	void add_edge(int u, int v) {
		edge e1(u, v); nodes[u].edges.push_back(e1);
		edge e2(v, u); nodes[v].edges.push_back(e2);
	}

	bool augment(int v) {
		if (v == -1) { return 1; }
		if (vis[v]) { return 0; }
		vis[v] = 1;
		for (auto &e : nodes[v].edges) {
			if (augment(match[e.v])) {
				match[e.v] = v; match[v] = e.v;
				return 1;
			}
		}
		return 0;
	}

	int matching() {
		for (int i = 0; i < n + m; i++) { match[i] = -1; }
		int w = 0;
		for (int i = 0; i < n; i++) {
			if (match[i] != -1) { continue; }
			for (int j = 0; j < n; j++) { vis[j] = 0; }
			w += augment(i);
		}
		return w;
	}

	void printMatch() {
		for (int i = 0; i < n; i++) {
			if (match[i] == -1) { continue; }
			cout << i + 1 << " " << match[i] - n + 1 << endl;
		}
	}

	void dfs(int u, bool m, vector<bool>& visited) {
		visited[u] = Z[u] = 1;
		for (auto &e : nodes[u].edges) {
			if (visited[e.v] || e.matched == m) { continue; }
			dfs(e.v, e.matched, visited);
		}
	}

	vector<pair<int, int>> vertexCover() {
		int K = matching();

		for (int u = 0; u < n; u++) {
			if (match[u] == -1) { continue; }
			int v = match[u];
			for (auto &e : nodes[u].edges) {
				if (e.v == v) {
					e.matched = nodes[u].matched = nodes[e.v].matched = 1;
					break;
				}
			}
			for (auto &e : nodes[v].edges) {
				if (e.v == u) { e.matched = 1; break; }
			}
		}

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
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int k; cin >> k;
	while (k--) {
		int m, n; cin >> m >> n;
		vector<vector<int>> ma(n + m, vector<int>(n + m, 0));
		for (int i = 0; i < m; i++) {
			int x; cin >> x;
			while (x != 0) { ma[i][x + m - 1] = ma[x + m - 1][i] = 1; cin >> x; }
		}
		bipartiteGraph g(m, n);
		for (int i = 0; i < m; i++)
			for (int j = m; j < n + m; j++)
				if (!ma[i][j]) { g.add_edge(i, j); }

		vector<pair<int, int>> v = g.vertexCover();
		set<pair<int, int>> s(v.begin(), v.end());
		int bC = 0, gC = 0;
		vector<int> boys, girls;
		for (int i = 0; i < n + m; i++) {
			int t = (i >= m), id = t ? i - m : i; t++; id++;
			if (s.count({ t, id })) { continue; }
			if (t == 1) { bC++; boys.push_back(id); }
			else { gC++; girls.push_back(id); }
		}
		cout << bC + gC << endl << bC << ' ' << gC << endl;
		for (auto &x : boys) { cout << x << ' '; } cout << endl;
		for (auto &x : girls) { cout << x << ' '; } cout << endl;
	}

	cin.ignore(2); return 0;
}