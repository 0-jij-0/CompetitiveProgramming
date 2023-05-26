#include <bits/stdc++.h>
using namespace std;

struct Graph {
	vector<vector<int>> nodes; int N;
	Graph(int _n) : N(_n), nodes(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	bool bfs(int u, vector<bool>& vis) {
		queue<int> q; q.push(u);
		vis[u] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto& e : nodes[cur]) {
				if (vis[e]) { continue; }
				q.push(e); vis[e] = true;
			}
		}
		return true;
	}

	int countConnectedComponents() {
		vector<bool> vis(N, false); int res = 0;
		for (int i = 0; i < N; i++)
			if (!vis[i]) res += bfs(i, vis);
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; Graph G(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		G.addEdge(--u, --v);
	}

	cout << (m - (n - G.countConnectedComponents())) << '\n';

}