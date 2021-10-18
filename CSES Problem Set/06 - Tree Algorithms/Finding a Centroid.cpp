#include <iostream>
#include <vector>
using namespace std;

struct graph {
	vector<vector<int>> nodes; int n;
	vector<int> subtreeSize;
	graph(int _n) : n(_n), nodes(_n), subtreeSize(_n, 1) {}

	void add_edge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}
	
	int subsizeDFS(int cur, int p = -1) {
		for (auto& e : nodes[cur]) if (e != p)
			subtreeSize[cur] += subsizeDFS(e, cur);
		return subtreeSize[cur];
	}

	int findCentroid(int cur) {
		for (auto& e : nodes[cur])
			if (subtreeSize[e] > n / 2) {
				subtreeSize[cur] = n - subtreeSize[e];
				return findCentroid(e);
			}
		return cur;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g.add_edge(--u, --v);
	}

	g.subsizeDFS(0);
	cout << g.findCentroid(0) + 1 << '\n';
	cin.ignore(2); return 0;
}