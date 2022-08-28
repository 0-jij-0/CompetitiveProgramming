#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Graph {
	vector<vector<int>> nodes; int n;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	void bfs(int u, vector<bool> &vis) {
		queue<int> q; q.push(u);
		vis[u] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto &e : nodes[cur]) {
				if (vis[e]) { continue; }
				q.push(e); vis[e] = true;
			}
		}
	}

	void dfs(int cur, vector<bool> &vis) {
		vis[cur] = true;
		for (auto& e : nodes[cur])
			if (!vis[e]) dfs(e, vis);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}