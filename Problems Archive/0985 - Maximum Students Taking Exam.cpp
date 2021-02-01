#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node { vector<edge> edges; node() {} };

struct bipartiteGraph {
	vector<node> nodes; int n, m;
	vector<bool> vis;
	vector<int> match;

	bipartiteGraph(int _n, int _m) : n(_n), m(_m) {
		nodes.resize(n + m); match.resize(n + m, -1); vis.resize(n + m, 0);
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

map<int, int> N, M; int a, b;
int ID(int i, int j) { return (j % 2 ? M : N)[i * b + j]; }

int maxStudents(vector<vector<char>> &seats) {
	a = seats.size(); b = seats.back().size();
	int res = 0;
	for (int i = 0; i < a; i++) {
		res += count(seats[i].begin(), seats[i].end(), '.');
		for (int j = 0; j < b; j++)
			(j % 2 ? M : N)[i * b + j] = 0;
	}
	int n = 0; for (auto &x : N) { x.second = n++; }
	int m = n; for (auto &x : M) { x.second = m++; }
	bipartiteGraph g(n, m - n);
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++) {
			if (seats[i][j] == '#') { continue; }
			if (j != 0 && seats[i][j - 1] == '.') { g.add_edge(ID(i, j), ID(i, j - 1)); }
			if (i != 0 && j != 0 && seats[i - 1][j - 1] == '.') { g.add_edge(ID(i, j), ID(i - 1, j - 1)); }
			if (i != 0 && j != b - 1 && seats[i - 1][j + 1] == '.') { g.add_edge(ID(i, j), ID(i - 1, j + 1)); }
		}
	return res - g.maxMatching();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> a >> b; vector<vector<char>> seats(a, vector<char>(b));
	for (auto &x : seats) for (auto & y : x) cin >> y;
	cout << maxStudents(seats) << endl;

	cin.ignore(2); return 0;
}