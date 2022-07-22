#pragma GCC target("popcnt")

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
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
	}
 
	void topSortDFS(int u, vector<int>& visited, vector<int>& ans) {
		visited[u] = true;
		for (edge& e : nodes[u].edges)
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
 
vector<bitset<50000>> dp;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int n, m; cin >> n >> m; 
	graph g(n); dp.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
 
	vector<int> v = g.topologicalSort();
	for (int i = n - 1; i >= 0; i--) {
		for (edge& e : g.nodes[v[i]].edges)
			dp[v[i]] |= dp[e.v]; dp[v[i]][v[i]] = 1;
	}
 
	for (auto& x : dp) cout << x.count() << ' '; cout << '\n';
 
	cin.ignore(2); return 0;
}