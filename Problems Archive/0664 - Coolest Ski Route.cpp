#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

vector<int> res;

struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, int w) {
		edge e1(u, v, w); nodes[u].edges.push_back(e1);
	}

	int dfs(int u) {
		if (res[u] != -1) { return res[u]; }
		int ans = 0;
		for (auto &x : nodes[u].edges)
			ans = max(ans, x.w + dfs(x.v));
		return res[u] = ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--; g.add_edge(u, v, w);
	}

	int ans = 0; res.resize(n, -1);
	for (int i = 0; i < n; i++) {
		if (res[i] != -1) { continue; }
		ans = max(ans, g.dfs(i));
	}

	cout << ans << endl; cin.ignore(2); return 0;
}