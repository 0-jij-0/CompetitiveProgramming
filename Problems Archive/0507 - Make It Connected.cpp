#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

typedef long long ll;

struct DSU {
	vector<int> rank, parent;
	DSU(int n) {
		rank.resize(n, 1); parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}
	int find(const int u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge &rhs) const { return w < rhs.w; }
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n = 0;
	vector<edge> edges; int m = 0;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, ll w) {
		edge e1(u, v, w), e2(v, u, w);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
		edges.push_back(e1); m++;
	}

	ll KruskalMST() {
		sort(edges.begin(), edges.end());
		DSU dsu(n); int i = 0, c = 0; ll ans = 0;
		while (i < m && c != n - 1) {
			edge &e = edges[i];
			if (!dsu.merge(e.u, e.v)) { i++; continue; }
			ans += e.w; i++; c++;
		}
		return ans;
	}
};

vector<ll> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; 
	a.resize(n); graph g(n);
	for (auto &x : a) { cin >> x; }
	int idx = min_element(a.begin(), a.end()) - a.begin();

	for (int i = 0; i < n; i++) {
		if (i == idx) { continue; }
		g.add_edge(idx, i, a[idx] + a[i]);
	}

	for (int i = 0; i < m; i++) {
		int u, v; ll w; cin >> u >> v >> w;
		u--; v--; g.add_edge(u, v, w);
	}
	cout << g.KruskalMST() << endl;

	cin.ignore(2); return 0;
}