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

	ll KruskalMST(vector<edge> &res) {
		sort(edges.begin(), edges.end());
		DSU dsu(n); res.clear(); int i = 0; ll ans = 0;
		while (i < m && res.size() != n - 1) {
			edge &e = edges[i];
			if (!dsu.merge(e.u, e.v)) { i++; continue; }
			res.push_back(e); ans += e.w; i++;
		}
		if (res.size() != n - 1) { res.clear(); return -1; }
		return ans;
	}
};

vector<ll> x, y, c, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n; graph g(n + 1);
	x.resize(n); y.resize(n); c.resize(n); k.resize(n);
	for (int i = 0; i < n; i++) { cin >> x[i] >> y[i]; }
	for (auto &a : c) { cin >> a; }
	for (auto &a : k) { cin >> a; }
	
	for(int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			ll w = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			g.add_edge(i, j, w*(k[i] + k[j]));
		}
	for (int i = 0; i < n; i++)
		g.add_edge(i, n, c[i]);
	vector<edge> edges;
	ll ans = g.KruskalMST(edges);
	vector<int> powp; vector<pair<int, int>> con;
	for (auto &e : edges) {
		if (e.v == n) { powp.push_back(e.u + 1); }
		else { con.push_back({ e.u + 1, e.v + 1 }); }
	}
	cout << ans << endl << powp.size() << endl;
	for (auto &a : powp) { cout << a << ' '; }
	cout << endl << con.size() << endl;
	for (auto &a : con) { cout << a.first << ' ' << a.second << endl; }
	cin.ignore(2); return 0;
}