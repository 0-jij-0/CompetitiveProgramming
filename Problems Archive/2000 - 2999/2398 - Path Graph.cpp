#include <bits/stdc++.h>
using namespace std;

vector<int> deg;

struct Graph {
	vector<vector<int>> nodes; int N;
	Graph(int _n) : N(_n), nodes(_n) {}

	void addEdge(int u, int v) {
		deg[u]++; deg[v]++;
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}
};

bool check(Graph& G, int n, int m) {
	if (m != n - 1) return false;
	int cur = find_if(deg.begin(), deg.end(), [&](const int& x) {return x == 1; }) - deg.begin();
	if (cur == n) return false;

	vector<int> vis(n, 0); vis[cur] = true; 
	int prev = cur; cur = G.nodes[cur][0];
	for (int i = 0; i < n - 2; i++) {
		if (deg[cur] != 2) return false;
		int nxt = G.nodes[cur][0] == prev ? G.nodes[cur][1] : G.nodes[cur][0];
		if (vis[nxt]) return false;
		vis[cur] = true; prev = cur; cur = nxt;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	Graph G(n); deg.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		G.addEdge(--u, --v);
	}
	cout << (check(G, n, m) ? "Yes" : "No") << '\n';

}