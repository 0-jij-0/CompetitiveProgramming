#include <iostream>
#include <vector>
using namespace std;

struct graph {
	vector<vector<int>> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	bool dfs(int cur, vector<int>& vis, vector<int>& col) {
		int newCol = (col[cur] + 1) & 1;
		for (auto& e : nodes[cur]) {
			if (vis[e] && col[cur] == col[e]) { return false; }
			if (vis[e]) { continue; }
			col[e] = newCol; vis[e] = true;
			if (!dfs(e, vis, col)) { return false; }
		}
		return true;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; graph g(n); 
		vector<vector<int>> D(n);

		bool ok = true;
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b; --a; --b;
			if (D[a].size() > 1 || D[b].size() > 1 || a == b) { ok = false; }
			if (!D[a].empty()) g.add_edge(D[a][0], i);
			if (!D[b].empty()) g.add_edge(D[b][0], i);
			D[a].push_back(i); D[b].push_back(i);
		}
		vector<int> team(n, 0), vis(n, 0);
		for (int i = 0; i < n && ok; i++)
			if (!vis[i] && !g.dfs(i, vis, team)) ok = false;

		cout << (ok ? "YES" : "NO") << '\n';
	}
}