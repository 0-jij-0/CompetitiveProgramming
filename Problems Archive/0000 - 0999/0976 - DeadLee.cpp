#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct edge {
	int u, v, id; edge() {}
	edge(int _u, int _v, int _id) :
		u(_u), v(_v), id(_id) {}
};

struct node { vector<edge> edges; };

vector<int> w;

struct graph {
	vector<node> nodes; int n, m = 0;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v, m), e2(v, u, m); m++;
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	vector<int> bfs() {
		queue<int> q; 
		vector<bool> visEdge(m, false);
		vector<bool> visNode(n, false);
		for(int i = 0; i < n; i++)
			if (w[i] >= 0) { q.push(i); visNode[i] = true; }

		vector<int> res;
		while (!q.empty()) {
			int f = q.front(); q.pop(); node &n = nodes[f];
			for (edge &e : n.edges) {
				if (visEdge[e.id]) { continue; }
				res.push_back(e.id); visEdge[e.id] = true;
				if (++w[e.v] >= 0 && !visNode[e.v]) { 
					q.push(e.v); visNode[e.v] = true;
				}
			}
		}
		if (res.size() != m) { return vector<int>(); }
		reverse(res.begin(), res.end()); return move(res);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	graph g(n); w.resize(n);
	for (auto &x : w) { cin >> x; }
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		w[--u]--; w[--v]--; g.add_edge(u, v);
	}
	vector<int> res = g.bfs();
	if (res.empty()) { cout << "DEAD" << '\n'; return 0; }
	cout << "ALIVE" << '\n';
	for (auto &x : res) { cout << x + 1 << ' '; }
	cout << '\n'; cin.ignore(2); return 0;
}