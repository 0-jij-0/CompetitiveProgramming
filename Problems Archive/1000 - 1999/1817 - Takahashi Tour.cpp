#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

struct node { set<int> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.insert(v);
		nodes[v].edges.insert(u);
	}

	void dfs(int u, int p = -1) {
		cout << u + 1 << ' ';
		for (auto& e : nodes[u].edges) {
			if (e == p) { continue; }
			dfs(e, u); cout << u + 1 << ' ';
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g.add_edge(--u, --v);
	}

	g.dfs(0); cout << '\n';
	cin.ignore(2); return 0;
}