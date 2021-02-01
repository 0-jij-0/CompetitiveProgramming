#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> color, res;

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

	int dfs1(int cur, int p) {
		node &n = nodes[cur]; int ans = color[cur];
		for (auto &x : n.edges) {
			if (x.v == p) { continue; }
			int y = dfs1(x.v, cur);
			if (y > 0) { ans += y; }
		}
		return res[cur] = ans;
	}

	void dfs2(int cur, int p, int cont) {
		res[cur] += cont;
		for (auto &x : nodes[cur].edges) {
			if (x.v == p) { continue; }
			dfs2(x.v, cur, max(0, res[cur] - max(0, res[x.v])));
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n; cin >> n; graph g(n); 
	color.resize(n); res.resize(n);
	for (auto &x : color) { cin >> x; x -= (x == 0); }

	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; 
		u--; v--; g.add_edge(u, v);
	}

	g.dfs1(0, -1); g.dfs2(0, -1, 0);
	for (auto &x : res) { cout << x << ' '; }
	cout << endl; cin.ignore(2); return 0;
}