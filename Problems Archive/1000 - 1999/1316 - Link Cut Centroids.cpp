#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

vector<int> subSize;

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) { subSize.resize(_n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	int dfs(int cur, int p = -1) {
		int res = 0; for (edge &e : nodes[cur].edges)
			if (e.v != p) res += dfs(e.v, cur);
		return subSize[cur] = 1 + res;
	}

	pair<int, int> centroids(int cur, int p = -1) {
		int idx = -1, ma = 0;
		for (edge &e : nodes[cur].edges) {
			if (e.v == p) { continue; }
			if (subSize[e.v] > ma) { idx = e.v; ma = subSize[e.v]; }
		}
		if (ma > n / 2) { return centroids(idx, cur); }
		if (n - ma > n / 2) { return { cur, -1 }; }
		return { cur, idx };
	}

	int leaf(int cur, int p) {
		if (nodes[cur].edges.size() == 1) { return cur; }
		for (edge &e : nodes[cur].edges)
			if (e.v != p) return leaf(e.v, cur);
		return -1;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; graph g(n);
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			u--; v--; g.add_edge(u, v);
		}
		g.dfs(0); pair<int, int> p = g.centroids(0);
		if (p.second == -1) {
			cout << 1 << ' ' << g.nodes[0].edges.front().v + 1 << '\n';
			cout << 1 << ' ' << g.nodes[0].edges.front().v + 1 << '\n';
			continue;
		}
		int idx = g.leaf(p.second, p.first);
		cout << idx + 1 << ' ' << g.nodes[idx].edges[0].v + 1 << '\n';
		cout << p.first + 1 << ' ' << idx + 1 << '\n';
	}

	cin.ignore(2); return 0;
}