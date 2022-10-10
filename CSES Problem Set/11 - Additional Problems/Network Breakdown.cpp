#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> rank, parent;

	DSU(int n) : rank(n, 1), parent(n) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int &u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

vector<pair<int, int>> edges, removedEdges;
unordered_map<int, unordered_set<int>> removedEdgesSet;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k; cin >> n >> m >> k; 
	DSU dsu(n); edges.resize(m); removedEdges.resize(k);
	for (auto &x : edges) {
		cin >> x.first >> x.second;
		if (--x.first > --x.second) swap(x.first, x.second);
	}
	for (auto &x : removedEdges) {
		cin >> x.first >> x.second;
		if (--x.first > --x.second) swap(x.first, x.second);
		removedEdgesSet[x.first].insert(x.second);
	} 

	int components = n; for (auto &x : edges)
		if (!removedEdgesSet[x.first].count(x.second))
			components -= dsu.merge(x.first, x.second);

	vector<int> res(k);
	for (int i = k - 1; i >= 0; i--) {
		res[i] = components;
		components -= dsu.merge(removedEdges[i].first, removedEdges[i].second);
	}

	for (auto &x : res) cout << x << ' '; cout << '\n';
}