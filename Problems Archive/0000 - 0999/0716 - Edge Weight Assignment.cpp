#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

vector<int> leaves, parent, height;
bool zero = false, one = false;

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

	void bfs(int u) {
		queue<int> q; q.push(u);
		vector<bool>visited(n, false);
		visited[u] = true; parent[u] = -1;
		while (!q.empty()) {
			int f = q.front(); q.pop();
			node& n = nodes[f]; bool leaf = true;
			for (auto &x : n.edges) {
				int dest = x.v;
				if (visited[dest] == false) {
					parent[dest] = f; leaf = false;
					q.push(dest); visited[dest] = true;
				}
			}
			if (leaf) { leaves.push_back(f); }
		}
	}

	void check(int cur, int p, int res) {
		bool leaf = true;
		for (auto &x : nodes[cur].edges) {
			if (x.v == p) { continue; }
			leaf = false; check(x.v, cur, res ^ 1);
		}
		if (!leaf) { return; }
		res ? one = true : zero = true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n; cin >> n; graph g(n); parent.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		a--; b--; g.add_edge(a, b);
	}
	int root = 0; while (g.nodes[root].edges.size() == 1) { root++; }
	g.bfs(root); set<int> par;
	for (auto &x : leaves) { par.insert(parent[x]); }
	int max = n - 1 - (int) (leaves.size() - par.size());
	g.check(root, -1, 0);
	int min = (zero && one) ? 3 : 1;
	cout << min << ' ' << max << endl;
	cin.ignore(2); return 0;
}