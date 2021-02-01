#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> point;

map<point, int> seg;

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

vector<string> v; int Y, X;

point belong(int x, int y, bool h) {
	if (h) {
		int i = y, j = y;
		while (i > 0 && v[x][i] != '#') { i--; }
		while (j < X - 1 && v[x][j] != '#') { j++; }
		if (v[x][i] == '#') { i++; }
		if (v[x][j] == '#') { j--; }
		return { {h, x}, {i, j} };
	}
	int i = x, j = x;
	while (i > 0 && v[i][y] != '#') { i--; }
	while (j < Y - 1 && v[j][y] != '#') { j++; }
	if (v[i][y] == '#') { i++; }
	if (v[j][y] == '#') { j--; }
	return { {h, y}, {i, j} };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		cin >> Y >> X; v.clear(); v.resize(Y, string(X, '.')); seg.clear();
		int p; cin >> p; while (p--) { int x, y; cin >> x >> y; v[x - 1][y - 1] = '*'; }
		int w; cin >> w; while (w--) { int x, y; cin >> x >> y; v[x - 1][y - 1] = '#'; }
		for (int r = 0; r < Y; r++) {
			int i = 0, j = 0;
			while (j != X) {
				if (v[r][i] == '#') { i = j = j + 1; continue; }
				if (j + 1 != X && v[r][j + 1] != '#') { j++; continue; }
				seg[{ {true, r}, { i, j } }] = 0; i = j = j + 1;
			}
		}
		for (int c = 0; c < X; c++) {
			int i = 0, j = 0;
			while (j != Y) {
				if (v[i][c] == '#') { i = j = j + 1; continue; }
				if (j + 1 != Y && v[j + 1][c] != '#') { j++; continue; }
				seg[{ {false, c}, { i, j } }] = 0; i = j = j + 1;
			}
		}
		int id = 0, n = 0, m = 0;
		for (auto &x : seg) { 
			x.second = id++;
			(x.first.first.first ? m : n)++;
		}
		bipartiteGraph g(n, m);
		for (int i = 0; i < Y; i++)
			for (int j = 0; j < X; j++)	if (v[i][j] == '*')
					g.add_edge(seg[belong(i, j, false)], seg[belong(i, j, true)]);

		cout << g.maxMatching() << '\n';
	}

	cin.ignore(2); return 0;
}