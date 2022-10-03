#include <bits/stdc++.h>
using namespace std;

struct Graph {
	vector<vector<int>> nodes; int n;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(u, v);
		nodes[v].emplace_back(v, u);
	}

	bool graphColoringUtil(int m, vector<int> &color, int v) {
		if (v == n) { return true; }
		set<int> usedColors; for (auto &e : nodes[v]) 
			usedColors.insert(color[e]);

		for (int c = 1; c <= m; c++)
			if (!usedColors.count(c)) {
				color[v] = c;
				if (graphColoringUtil(m, color, v + 1)) return true;
				color[v] = 0;
			}
		return false;
	}
	vector<int> graphColoring(int m) {
		vector<int> color(n);
		for (int i = 0; i < n; i++) { color[i] = 0; }
		graphColoringUtil(m, color, 0);
		return color;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}