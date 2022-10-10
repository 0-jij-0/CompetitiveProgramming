#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> rank, parent;

	DSU(int n) : rank(n, 1), parent(n) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int& u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

bitset<100001> dp; vector<bool> vis;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; 
	DSU dsu(n); vis.resize(n, false);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		dsu.merge(--u, --v);
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++) if (!vis[dsu.find(i)]) {
		dp |= dp << dsu.size(i); vis[dsu.find(i)] = true;
	}

	for (int i = 1; i <= n; i++)
		cout << dp[i]; cout << '\n';
}