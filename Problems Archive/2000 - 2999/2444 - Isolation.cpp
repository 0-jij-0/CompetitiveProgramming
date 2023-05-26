#include <bits/stdc++.h>
using namespace std;

struct Graph {
	vector<set<int>> nodes; int n;
	vector<int> deg; int isolated;
	Graph(int _n) : n(_n), nodes(_n), deg(_n), isolated(_n) {}

	void addEdge(int u, int v) {
		nodes[u].insert(v);
		nodes[v].insert(u);
		deg[u] += 1; deg[v] += 1;
		isolated -= (deg[u] == 1) + (deg[v] == 1);
	}
	void removeEdge(int u, int v) {
		nodes[u].erase(v);
		nodes[v].erase(u);
		deg[u] -= 1; deg[v] -= 1;
		isolated += (deg[u] == 0) + (deg[v] == 0);
	}
	void removeEdges(int u) {
		set<int> s = nodes[u];
		for (auto& x : s) removeEdge(u, x);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q; 
	Graph G(n); while (q--) {
		int t; cin >> t; if (--t) {
			int u; cin >> u; G.removeEdges(--u);
		}
		else { int u, v; cin >> u >> v; G.addEdge(--u, --v); }
		cout << G.isolated << '\n';
	}
}