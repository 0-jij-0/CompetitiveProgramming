#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Graph {
	vector<vector<int>> nodes; int n;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v);
	}

	bool cycleDFS(int cur, vector<int> &color, vector<int> &parent) {
		color[cur] = 1;
		for (auto &e : nodes[cur])
			if (color[e] == 0) {
				parent[e] = cur;
				if (cycleDFS(e, color, parent)) { return true; }
			}
			else if (color[e] == 1) { return true; }

		color[cur] = 2; return false;
	}

	bool findCycle() {
		vector<int> color(n, 0), parent(n, -1);
		for (int v = 0; v < n; v++)
			if (cycleDFS(v, color, parent)) return true;
		return false;
	}

	void topSortDFS(int u, vector<int> &vis, vector<int> &ans) {
		vis[u] = true;
		for (auto &e : nodes[u])
			if (!vis[e]) topSortDFS(e, vis, ans);
		ans.push_back(u);
	}
	vector<int> topologicalSort() {
		vector<int> vis(n, false), ans;
		for (int i = 0; i < n; ++i)
			if (!vis[i]) topSortDFS(i, vis, ans);
		reverse(ans.begin(), ans.end()); return ans;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}