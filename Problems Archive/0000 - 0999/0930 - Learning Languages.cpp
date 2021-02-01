#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <queue>
using namespace std;

struct DSU {
	vector<int> rank, parent;

	DSU(int n) {
		rank.resize(n, 1); parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; int e = 0;
	DSU dsu(n + m);

	for (int i = 0; i < n; i++) {
		int k; cin >> k; e += k; int x;
		while (k--) { cin >> x; dsu.merge(i, n + x - 1); }
	}
	if (!e) { cout << n << endl; }
	else {
		set<int> s; while (n--) { s.insert(dsu.find(n)); }
		cout << s.size() - 1 << endl;
	}
	cin.ignore(2); return 0;
}