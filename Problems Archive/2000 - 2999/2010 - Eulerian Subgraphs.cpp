#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

struct graph {
	vector<vector<int>> edges; int n;
	graph(int _n) : n(_n) { edges.resize(n); }

	void add_edge(int u, int v) {
		edges[u].emplace_back(v);
		edges[v].emplace_back(u);
	}

	void bfs(int u, vector<bool>& visited) {
		queue<int> q; q.push(u);
		visited[u] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto& e : edges[cur]) {
				if (visited[e]) { continue; }
				q.push(e); visited[e] = true;
			}
		}
	}

	int countConnectedComponents() {
		int res = 0; vector<bool> vis(n, 0);
		for(int i = 0; i < n; i++)
			if (!vis[i]) { res++; bfs(i, vis); }
		return res;
	}
};

ll powerTwo(int n) {
	ll x = 2, res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g.add_edge(--u, --v);
	}

	int cc = g.countConnectedComponents();
	cout << powerTwo(m - n + cc) << '\n';
	cin.ignore(2); return 0;
}