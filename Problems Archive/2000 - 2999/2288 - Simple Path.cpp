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

	vector<int> bfs(int s, int t) {
		queue<int> q; q.push(s);
		vector<int> par(n, -1); par[s] = s;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto& e : nodes[cur]) {
				if (par[e] != -1) { continue; }
				q.push(e); par[e] = cur;
			}
		}

		vector<int> path(1, t);
		while (path.back() != s) path.push_back(t = par[t]);
		return path;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, x, y; cin >> n >> x >> y; Graph G(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		G.addEdge(--u, --v);
	}

	vector<int> res = G.bfs(--y, --x);
	for (auto& x : res) cout << x + 1 << ' '; cout << '\n';
}