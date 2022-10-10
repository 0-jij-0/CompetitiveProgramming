#include <bits/stdc++.h>
using namespace std;

struct Graph {
	vector<vector<int>> nodes; int n;
	vector<pair<int, int>> directedEdges;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	void dfs(int cur, int p, vector<int>& vis, vector<int> &outDegree) {
		vis[cur] = 1; vector<int> children;
		for (auto& e : nodes[cur]) if(e != p && vis[e] != 2)
			if (!vis[e]) { children.push_back(e); dfs(e, cur, vis, outDegree); }
			else { outDegree[cur]++; directedEdges.emplace_back(cur, e); }

		for(auto &e : children)
			if (outDegree[e] & 1) { directedEdges.emplace_back(e, cur); }
			else { outDegree[cur]++; directedEdges.emplace_back(cur, e); }

		vis[cur] = 2;
	}

	void directEdges() {
		bool ok = true;
		vector<int> vis(n, 0);
		vector<int> outDegree(n, 0);

		for (int i = 0; i < n; i++) if (!vis[i]) {
			int prev = (int)directedEdges.size();
			dfs(i, -1, vis, outDegree);
			int cur = (int)directedEdges.size();
			if ((prev - cur) & 1) { ok = false; break; }
		}

		if (!ok) { cout << "IMPOSSIBLE\n"; return; }
		for (auto& x : directedEdges) 
			cout << x.first + 1 << ' ' << x.second + 1 << '\n';
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; Graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g.addEdge(--u, --v);
	}
	g.directEdges();
}