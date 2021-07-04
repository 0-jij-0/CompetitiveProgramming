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

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	void dfs(int cur, int p, vector<int>& leaves) {
		if ((int)nodes[cur].edges.size() == 1) { leaves.push_back(cur); return; }
		for (edge& e : nodes[cur].edges) {
			if (e.v == p) { continue; }
			dfs(e.v, cur, leaves);
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	int root = 0; while ((int)g.nodes[root].edges.size() == 1) { root++; }
	vector<int> leaves; g.dfs(root, -1, leaves);
	int m = (int)leaves.size(), K = (m + 1) / 2;
	cout << K << '\n'; for (int i = 0; i + K < m; i++)
		cout << leaves[i] + 1 << ' ' << leaves[i + K] + 1 << '\n';


	if (m % 2) cout << leaves[K - 1] + 1 << ' ' << leaves[m - 1] + 1 << '\n';
	cin.ignore(2); return 0;
}