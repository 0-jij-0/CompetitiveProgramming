#include <bits/stdc++.h>
using namespace std;

struct Graph {
	vector<vector<int>> nodes[2]; int n;
	Graph(int _n) : n(_n) { nodes[0].resize(n); nodes[1].resize(n); }

	void addEdge(int u, int v) {
		nodes[0][u].emplace_back(v);
		nodes[1][v].emplace_back(u);
	}

	void sccDFS(int cur, vector<bool>& vis, vector<int>& comp, bool rev) {
		vis[cur] = true;
		for (auto& e : nodes[rev][cur])	
			if (!vis[e]) sccDFS(e, vis, comp, rev);
		comp.push_back(cur);
	}

	vector<vector<int>> SCC(int& t, vector<int> &sccMap) {
		vector<bool> vis(n, false);
		vector<int> order, component;
		vector<vector<int>> scc;

		for (int i = 0; i < n; i++)
			if (!vis[i]) { sccDFS(i, vis, order, false); }

		vis.assign(n, false);
		for (int i = 0; i < n; i++) {
			int v = order[n - 1 - i];
			if (!vis[v]) {
				sccDFS(v, vis, component, true);
				scc.push_back(component);
				for (auto& x : component) { sccMap[x] = t; }
				component.clear(); t++;
			}
		}
		return scc;
	}

	int componentBFS(int src, vector<bool>& vis, vector<int> &sccMap, vector<vector<int>> &scc) {
		queue<int> Q; Q.push(src); vis[src] = true;

		int res = 0; bool cycle = false; while (!Q.empty()) {
			int cc = Q.front(); Q.pop(); res += scc[cc].size(); 
			cycle = cycle || scc[cc].size() > 1;

			for (auto& cur : scc[cc]) {
				for (auto& e : nodes[0][cur]) if (!vis[sccMap[e]]) {
					vis[sccMap[e]] = true; Q.push(sccMap[e]);
				}
				for (auto& e : nodes[1][cur]) if (!vis[sccMap[e]]) {
					vis[sccMap[e]] = true; Q.push(sccMap[e]);
				}
			}
		}

		return res - 1 + cycle;
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

	vector<int> sccMap(n); int S = 0;
	vector<vector<int>> scc = g.SCC(S, sccMap);

	int res = 0; vector<bool> vis(S, false);
	for (int i = 0; i < S; i++) if(!vis[i])
		res += g.componentBFS(i, vis, sccMap, scc);

	cout << res << '\n';
}