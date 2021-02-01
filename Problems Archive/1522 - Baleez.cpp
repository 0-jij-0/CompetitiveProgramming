#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> Point;

struct DSU {
	vector<int> rank, parent;
	DSU(int n) : rank(n, 1), parent(n) {
		iota(parent.begin(), parent.end(), 0);
	}
	int find(const int& u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
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
	edge(int _u, int _v, ll _w) : u(_u), v(_v), w(_w) {}
	bool operator < (const edge& rhs) const { return w < rhs.w; }
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n = 0;
	vector<edge> edges; int m = 0;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, ll w) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
		edges.emplace_back(u, v, w); m++;
	}
};

int dist2(const Point &a, const Point &b) {
	int dx = a.first - b.first;
	int dy = a.second - b.second;
	return dx * dx + dy * dy;
}

vector<Point> p;

int main() {
	freopen("baleez.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; graph g(n); p.resize(n);
		for (auto& x : p) cin >> x.first >> x.second;

		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				g.add_edge(i, j, dist2(p[i], p[j]));

		sort(g.edges.begin(), g.edges.end()); 
		DSU dsu(n); int res = 0, i = 0;
		while (dsu.find(0) != dsu.find(1)) {
			dsu.merge(g.edges[i].u, g.edges[i].v);
			res = g.edges[i].w; i++;
		}

		cout << fixed << setprecision(8) << sqrt(res) << '\n';
	}

	cin.ignore(2); return 0;
}