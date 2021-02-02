#include <iostream>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

struct edge {
	int u, v;
	edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v), e2(v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	bool graphColoringUtil(int m, vector<int> &color, int v) {
		if (v == n) { return true; }
		set<int> used;
		for (auto &x : nodes[v].edges) { used.insert(color[x.v]); }
		for (int c = 1; c <= m; c++) {
			if (!used.count(c)) {
				color[v] = c;
				if (graphColoringUtil(m, color, v + 1)) { return true; }
				color[v] = 0;
			}
		}
		return false;
	}
	void graphColoring(int m) {
		vector<int> color(n);
		for (int i = 0; i < n; i++) { color[i] = 0; }
		graphColoringUtil(m, color, 0);
		for (int i = 0; i < n; i++)
			cout << i + 1 << ' ' << color[i] << endl;
	}
};

int main() {
	int n; cin >> n; graph g(n);
	string s; cin >> s; set<pair<int, int>> e;
	while (!cin.fail() || s.empty()) {
		stringstream ss(s); int a, b; char c; 
		ss >> a >> c >> b; a--; b--;
		if (a > b) { swap(a, b); }
		if (!e.count({ a, b })) { g.add_edge(a, b); }
		cin >> s;
	}
	e.clear(); g.graphColoring(4);
	cin.ignore(2); return 0;
}