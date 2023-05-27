#include <bits/stdc++.h>
using namespace std;

struct Graph {
	vector<vector<int>> nodes; int N;
	vector<pair<int, int>> edges;
	Graph(int _n) : N(_n), nodes(_n) {}

	void addEdge(int u, int v) {
		edges.emplace_back(u, v);
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; Graph G(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		G.addEdge(--u, --v);
	}

	vector<int> res; set<int> removed;
	for(int i = 0; i < n; i++) if (G.nodes[i].size() > 2) {
		res.push_back(G.nodes[i].size()); removed.insert(i);
		for (auto& e : G.nodes[i]) removed.insert(e);
	}
	
	n -= removed.size();
	for (int i = 0; i < n; i += 3) res.push_back(2);
	sort(res.begin(), res.end());
	for (auto& x : res) cout << x << ' '; cout << '\n';
}