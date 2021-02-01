#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<edge> edges;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		edges.emplace_back(u, v);
	}

	bool cycleDFS(int u, vector<int> &color, vector<int> &parent) {
		color[u] = 1;
		for (edge &e : nodes[u].edges)
			if (color[e.v] == 0) {
				parent[e.v] = u;
				if (cycleDFS(e.v, color, parent)) { return true; }
			}
			else if (color[e.v] == 1) { return true; }

		color[u] = 2; return false;
	}
	bool find_cycle() {
		vector<int> color(n, 0), parent(n, -1);
		for (int v = 0; v < n; v++)
			if (cycleDFS(v, color, parent)) { return true; }
		return false;
	}

	void topSortDFS(int u, vector<int> &visited, vector<int> &ans) {
		visited[u] = true;
		for (edge &e : nodes[u].edges)
			if (!visited[e.v]) { topSortDFS(e.v, visited, ans); }
		ans.push_back(u);
	}
	vector<int> topologicalSort() {
		vector<int> visited(n, false), ans;
		for (int i = 0; i < n; ++i)
			if (!visited[i]) { topSortDFS(i, visited, ans); }
		reverse(ans.begin(), ans.end()); return move(ans);
	}
};

vector<pair<int, int>> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m; 
		a.clear(); graph g(n);
		for (int i = 0; i < m; i++) {
			int t, u, v; cin >> t >> u >> v;
			if (!t) { a.emplace_back(--u, --v); }
			else { u--; v--; g.add_edge(u, v); }
		}
		if (g.find_cycle()) { cout << "NO" << endl; continue; }
		vector<int> v = g.topologicalSort(), f(n);
		for (int i = 0; i < n; i++) f[v[i]] = i;
		cout << "YES" << endl;
		for (edge &e : g.edges) { cout << e.u + 1 << ' ' << e.v + 1 << '\n'; }
		for (auto &x : a) {
			if (f[x.first] > f[x.second]) { swap(x.first, x.second); }
			cout << x.first + 1 << ' ' << x.second + 1 << '\n';
		}
	}

	cin.ignore(2); return 0;
}