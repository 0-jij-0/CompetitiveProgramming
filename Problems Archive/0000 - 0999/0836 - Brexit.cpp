#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

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

	bool bfs(int l, int x) {
		queue<int> q; q.push(l); if (x == l) { return true; }
		vector<bool> visited(n, false); visited[l] = true;
		vector<int> gone(n, 0); gone[l] = true;
		while (!q.empty()) {
			int f = q.front(); q.pop();
			node& n = nodes[f];
			for (auto &e : n.edges) {
				if (visited[e.v] == false) {
					gone[e.v]++;
					if (2 * gone[e.v] >= (int)nodes[e.v].edges.size()) {
						if (e.v == x) { return true; }
						visited[e.v] = true; q.push(e.v);
					}
				}
			}
		}
		return false;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int c, p, x, l; 
	cin >> c >> p >> x >> l;
	graph g(c);
	for (int i = 0; i < p; i++) {
		int a, b; cin >> a >> b;
		a--; b--; g.add_edge(a, b);
	}
	cout << (g.bfs(l - 1, x - 1) ? "leave" : "stay") << endl;
	cin.ignore(2); return 0;
}