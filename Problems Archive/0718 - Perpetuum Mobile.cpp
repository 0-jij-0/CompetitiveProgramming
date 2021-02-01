#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long double ld;

struct edge {
	int u, v; ld w; edge() {}
	edge(int _u, int _v, ld _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<edge> edges; int n;
	graph(int _n) : n(_n) {}

	void add_edge(int u, int v, ld w) {
		edges.push_back(edge(u, v, w));
	}

	bool bellman_ford() {
		//initialize distance to infinity
		vector<ld> d(n, 1e10); bool b = false;
		for (int i = 0; i < n; ++i) {
			b = false;
			for (edge &e : edges) {
				ld test = d[e.u] + e.w - d[e.v];
				if (test < -0.00001) {
					d[e.v] = d[e.u] + e.w;
					b = true;
				}
			}
		}
		return !b;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int a, b; ld c; cin >> a >> b >> c;
		ld w = (ld)log(1.0 / c); a--; b--;
		g.add_edge(a, b, w);
	}
	cout << (g.bellman_ford() ? "admissible" : "inadmissible") << endl;
	cin.ignore(2); return 0;	
}