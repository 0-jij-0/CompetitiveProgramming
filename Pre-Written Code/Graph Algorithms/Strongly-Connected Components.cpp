#include <iostream>
#include <vector>
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

	vector<vector<int>> SCC(int& t, vector<int>& sccMap) {
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
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}