#include <bits/stdc++.h>
using namespace std;

int TIME = 0;

struct DSU {
	vector<int> parent;
	vector<vector<int>> children, history;

	DSU(int n) : parent(n), children(n), history(n) {
		iota(parent.begin(), parent.end(), 0);
		for (int i = 0; i < n; i++) { children[i].push_back(i); }
	}

	int size(const int& u) { return (int)children[parent[u]].size(); }

	bool merge(int u, int v) {
		TIME++; u = parent[u]; v = parent[v];
		if (u == v) { return false; }
		if (size(u) > size(v)) { swap(u, v); }
		for (auto& x : children[u]) {
			history[x].push_back(TIME);
			parent[x] = v; children[v].push_back(x);
		}
		children[u].clear(); return true;
	}

	int query(int u, int v) {
		if (parent[u] != parent[v]) { return -1; }
		if (u == v) { return 0; }
		if (history[u].size() > history[v].size()) { swap(u, v); }
		if (history[u].empty()) { return history[v].back(); }

		int l = 0, r = (int) history[u].size();
		while (l != r) {
			int mid = (l + r) >> 1;
			int A = *(history[u].rbegin() + mid);
			int B = *(history[v].rbegin() + mid);
			A == B ? l = mid + 1 : r = mid;
		}
		if (l == (int) history[u].size()) { return *(history[v].rbegin() + l); }
		return max(*(history[v].rbegin() + l), *(history[u].rbegin() + l));
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, q; cin >> n >> m >> q; DSU dsu(n);

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; dsu.merge(u, v);
	}

	while (q--) {
		int u, v; cin >> u >> v;
		cout << dsu.query(--u, --v) << '\n';
	}
}