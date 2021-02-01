#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;

struct DSU {
	vector<int> rank;
	vector<int> parent;

	DSU(int n) {
		rank.resize(n, 1); parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int u) { return (parent[u] == u) ? u : (parent[u] = find(parent[u])); }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}

	int size(int u) { return rank[find(u)]; }
};

struct edge {
	int u, v, w;
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge &rhs) const { return w < rhs.w; }
};

vector<edge> edges;
vector<long long> paths, pref;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m; DSU dsu(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--; edge e(u, v, w); edges.push_back(e);
	}
	sort(edges.begin(), edges.end());
	for (auto &x : edges) {
		long long p = (long long)dsu.size(x.u) * dsu.size(x.v);
		paths.push_back(p);	dsu.merge(x.u, x.v);
	}
	pref.push_back(0);
	for (auto &x : paths) { pref.push_back(pref.back() + x); }
	for (int i = 0; i < m; i++) {
		int q; cin >> q; edge e(0, 0, q);
		int idx = upper_bound(edges.begin(), edges.end(), e) - edges.begin();
		cout << pref[idx];
		if (i + 1 != m) { cout << ' '; }
		else { cout << endl; }
	}
	cin.ignore(2); return 0;
}