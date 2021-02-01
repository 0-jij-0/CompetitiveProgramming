#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
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

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

vector<int> t;

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.push_back(edge(u, v));
	}

	int bfs(int u, int v) {
		queue<pair<int, pair<int, int>>> q; q.push({ 0, { u, v } }); DSU dsu(n);
		while (!q.empty()) {
			pair<int, pair<int, int>> f = q.front(); q.pop();
			int fu = f.second.first, fv = f.second.second, d = f.first;
			if (t[fu] != t[fv]) { return d; }
			if (!dsu.merge(fu, fv)) { continue; }
			int Lu = nodes[fu].edges[0].v, Lv = nodes[fv].edges[0].v;
			int Ru = nodes[fu].edges[1].v, Rv = nodes[fv].edges[1].v;
			q.push({ d + 1, { Lu, Lv } }); q.push({ d + 1, { Ru, Rv } });
		}
		return -1;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, a, b; cin >> n >> a >> b; 
	graph g(n); t.resize(n);
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r >> t[i];
		g.add_edge(i, l); g.add_edge(i, r);
	}
	int res = g.bfs(a, b);
	if (res != -1) { cout << res << endl; }
	else { cout << "indistinguishable" << endl; }
	cin.ignore(2); return 0;
}