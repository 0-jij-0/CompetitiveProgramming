#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

vector<int> colors, res;

struct edge {
	int u, v; edge() {}
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

	bool bfs() {
		queue<int> q; vector<int> done(n, 0);
		for (int i = 0; i < n; i++)
			if (colors[i] == 1) { q.push(i); done[i] = 1; }

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			res.push_back(cur + 1); int &c = colors[cur];
			for (edge &e : nodes[cur].edges) {
				if (colors[e.v] == colors[cur]) { return false; }
				if (done[e.v] < c - 1 && colors[e.v] >= c) { return false; }
				if (done[e.v] == c) { continue; }
				done[e.v]++; if (colors[e.v] == c + 1) { q.push(e.v); }
			}
		}
		return res.size() == n;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; 
	colors.resize(n); graph g(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--; g.add_edge(a, b);
	}
	for (auto &x : colors) { cin >> x; }
	if (!g.bfs()) { cout << -1; }
	else for (auto &x : res) cout << x << ' ';
	cout << '\n'; cin.ignore(2); return 0;
}