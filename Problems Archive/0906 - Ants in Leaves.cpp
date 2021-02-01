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

	int findMinTime() {
		vector<bool> vis(n, false);
		vector<int> d(n, 0);
		int res = 0; vis[0] = true;
		for (auto &e : nodes[0].edges)
			res = max(res, dfs(e.v, vis, d));
		return res + 1;
	}

	int dfs(int u, vector<bool> &vis, vector<int> &d) {
		stack<int> s; vector<int> leaf;
		s.push(u); vis[u] = true;

		while (!s.empty()) {
			int cur = s.top(); s.pop();
			if (nodes[cur].edges.size() == 1) { leaf.push_back(d[cur]); }
			for (edge &e : nodes[cur].edges) {
				if (!vis[e.v]) {
					d[e.v] = 1 + d[cur];
					vis[e.v] = true;
					s.push(e.v);
				}
			}
		}

		int res = -1; sort(leaf.begin(), leaf.end());
		for (auto &x : leaf) { res = max(res + 1, x); }
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	cout << g.findMinTime() << endl;
	cin.ignore(2); return 0;
}