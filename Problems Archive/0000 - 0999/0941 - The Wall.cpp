#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

struct edge {
	int u, v; bool match = 0; edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node { vector<edge> edges; node() {} };

struct bipartiteGraph {
	vector<node> nodes; int n, m;
	vector<bool> Z, vis;
	vector<int> unMatched, match;

	bipartiteGraph(int _n, int _m) : n(_n), m(_m) {
		nodes.resize(n + m); Z.resize(n + m, 0);
		match.resize(n + m, -1); vis.resize(n + m, 0);
	}

	void add_edge(int u, int v) {
		nodes[u].edges.push_back(edge(u, v));
		nodes[v].edges.push_back(edge(v, u));
	}

	bool augment(int v) {
		if (v == -1) { return 1; }
		if (vis[v]) { return 0; }
		vis[v] = 1;
		for (auto &e : nodes[v].edges)
			if (augment(match[e.v])) {
				match[e.v] = v; match[v] = e.v;
				return 1;
			}
		return 0;
	}

	int maxMatching() { 
		int w = 0;
		for (int x = 0; x < n; x++) {
			if (match[x] != -1) { continue; }
			for (auto &e : nodes[x].edges)
				if (match[e.v] == -1) {
					match[e.v] = x; match[x] = e.v;
					w++; break;
				}
		}
		for (int i = 0; i < n; i++) {
			if (match[i] != -1) { continue; }
			for (int j = 0; j < n; j++) { vis[j] = 0; }
			w += augment(i);
		}
		return w;
	}
};

double dist(double x1, double y1, double x2, double y2) {
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ifstream ifs("wall.in");

	int t; ifs >> t;
	while (t--) {
		int n, m, p; ifs >> n >> m >> p;
		bipartiteGraph g(n, m + 1); 
		double X = (n + 0.0) / 2.0, R = (n * n + 0.0) / 4.0;
		while (p--) {
			double x, y; ifs >> x >> y;
			int u = (int)floor(x), v = n + 1;
			for (int i = 1; i <= m; i++) {
				double Y = v++ - n + 0.0;
				double d = dist(x, y, X, Y);
				if (d <= R) { break; }
			}
			g.add_edge(u, v - 1);
		}
		cout << g.maxMatching() << endl;
	}

	cin.ignore(2); return 0;
}