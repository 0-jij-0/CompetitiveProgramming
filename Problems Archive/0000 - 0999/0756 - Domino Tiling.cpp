#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>
using namespace std;
const int MAXV = 10005;

vector<string> v;
vector<char> s;
vector<int> color;

int match[MAXV];
bool vis[MAXV];

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<edge> edges;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v), e2(v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
		edges.push_back(e1);
	}

	void bfs(int u, vector<bool> &visited) {
		queue<int> q; q.push(u);
		color[u] = 1; visited[u] = true;
		while (!q.empty()) {
			int f = q.front(); q.pop();
			node&n = nodes[f];
			for (auto &x : n.edges) {
				int dest = x.v;
				if (visited[dest] == false) {
					color[dest] = (color[f] == 1) ? 2 : 1;
					q.push(dest); visited[dest] = true;
				}
			}
		}
	}
};

struct bipartiteGraph {
	vector<node> nodes; int n, m;

	bipartiteGraph(int _n, int _m) : n(_n), m(_m) { nodes.resize(n + m); }

	void add_edge(int u, int v) {
		edge e1(u, v); nodes[u].edges.push_back(e1);
		edge e2(v, u); nodes[v].edges.push_back(e2);
	}

	bool augment(int v) {
		if (v == -1) { return 1; }
		if (vis[v]) { return 0; }
		vis[v] = 1;
		for (auto &e : nodes[v].edges) {
			if (augment(match[e.v])) {
				match[e.v] = v; match[v] = e.v;
				return 1;
			}
		}
		return 0;
	}

	int matching() {
		for (int i = 0; i < n + m; i++) { match[i] = -1; }
		int w = 0;
		for (int i = 0; i < n; i++) {
			if (match[i] != -1) { continue; }
			for (int j = 0; j < n; j++) { vis[j] = 0; }
			w += augment(i);
		}
		return w;
	}

	void printMatch() {
		for (int i = 0; i < n; i++) {
			if (match[i] == -1) { continue; }
			cout << i + 1 << " " << match[i] - n + 1 << endl;
		}
	}
};

vector<int> idx;
bool compare(int i, int j) { return color[i] < color[j]; }

bipartiteGraph convertGraph(graph &g, int n, int m) {
	vector<bool> visited(n * m, false);
	for (int i = 0; i < n * m; i++) {
		if (s[i] == '.') { continue; }
		if (visited[i]) { continue; }
		g.bfs(i, visited);
	}

	int l = 0;
	for (int i = 0; i < n*m; i++) {
		if (color[i] == 1) { l++; }
	}
	idx.resize(n * m);
	int curL = 0, curR = l;
	for (int i = 0; i < n * m; i++) {
		if (color[i] == 0) { continue; }
		if (color[i] == 1) { idx[i] = curL++; }
		else { idx[i] = curR++; }
	}

	bipartiteGraph bG(l, curR - l);
	for (auto &e : g.edges) 
		bG.add_edge(idx[e.u], idx[e.v]);

	return move(bG);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m, a, b; cin >> n >> m >> a >> b;
	graph g(n * m); v.resize(n); color.resize(n*m, 0);
	for (auto &x : v) { cin >> x; }

	int freeCount = 0; s.resize(n * m, '.');
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '.') { continue; }
			freeCount++; s[i*m + j] = v[i][j];
			if (i < n - 1 && v[i + 1][j] != '.') { g.add_edge(i*m + j, (i + 1)*m + j); }
			if (j < m - 1 && v[i][j + 1] != '.') { g.add_edge(i*m + j, i*m + j + 1); }
		}
	}
	if (2 * b <= a || freeCount == 0) { cout << freeCount * b << endl; return 0; }

	int K = convertGraph(g, n, m).matching();
	cout << a * K + (freeCount - 2 * K)*b << endl;

	cin.ignore(2); return 0;
}