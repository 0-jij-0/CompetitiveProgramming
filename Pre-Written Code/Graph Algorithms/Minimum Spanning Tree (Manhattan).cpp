#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

const int N = 100005;
const ll mod = 1000 * 1000 * 1000 + 7;
int n, q, Sq, Mk;

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
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge& rhs) const { return w < rhs.w; }
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n = 0;
	vector<edge> edges; int m = 0;
	int root;

	graph(int _n) : n(_n), root(0) {
		nodes.resize(n);
	}

	void add_edge(int u, int v, int w) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
		edges.emplace_back(u, v, w); m++;
	}

	void KruskalMST(vector<edge>& res) {
		sort(edges.begin(), edges.end());
		DSU dsu(n); res.clear(); int i = 0;
		while (i < m && res.size() != n - 1) {
			edge& e = edges[i];
			if (!dsu.merge(e.u, e.v)) { i++; continue; }
			res.push_back(e);
		}
	}
};

struct point {
	int x, y, index;
	bool operator<(const point& p) const { return x == p.x ? y < p.y : x < p.x; }
};
struct nodeM {
	int value, p;
};

point p[N];
nodeM T[N];

int query(int x) {
	int r = INT_MAX, p = -1;
	for (; x <= n; x += (x & -x)) {
		if (T[x].value < r) {
			r = T[x].value;
			p = T[x].p;
		}
	}
	return p;
}
void modify(int x, int w, int p) {
	for (; x > 0; x -= (x & -x)) {
		if (T[x].value > w) {
			T[x].value = w;
			T[x].p = p;
		}
	}
}

inline int dist(point& p1, point& p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

vector<int> v; int a[N];

//Creates a graph with nlogn edges, assumes distance is manhattan between points
void manhattan(graph& g) {
	for (int i = 1; i <= n; ++i) { p[i].index = i; }
	for (int dir = 1; dir <= 4; ++dir) {
		if (dir == 2 || dir == 4) {
			for (int i = 1; i <= n; ++i) { swap(p[i].x, p[i].y); }
		}
		else if (dir == 3) {
			for (int i = 1; i <= n; ++i) { p[i].x = -p[i].x; }
		}
		sort(p + 1, p + 1 + n);

		v.clear();
		for (int i = 1; i <= n; ++i) {
			a[i] = p[i].y - p[i].x;
			v.push_back(a[i]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for (int i = 1; i <= n; ++i) { a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1; }
		for (int i = 1; i <= n; ++i) {
			T[i].value = INT_MAX;
			T[i].p = -1;
		}
		for (int i = n; i >= 1; --i) {
			int pos = query(a[i]);
			if (pos != -1) {
				g.add_edge(p[i].index - 1, p[pos].index - 1, dist(p[i], p[pos]));
			}
			modify(a[i], p[i].x + p[i].y, i);
		}
	}
}
