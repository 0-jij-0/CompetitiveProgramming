#include <bits/stdc++.h>
using namespace std;

vector<int> max1, max2, res;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) { max1.resize(n, 0); max2.resize(n, -1); res.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	void init(int cur, int p) {
		for (edge &e : nodes[cur].edges) {
			if (e.v == p) { continue; }	init(e.v, cur);
			if (1 + max1[e.v] > max1[cur]) { max2[cur] = max1[cur]; max1[cur] = 1 + max1[e.v]; }
			else if (1 + max1[e.v] > max2[cur]) { max2[cur] = 1 + max1[e.v]; }
		}
	}

	void dfs(int cur, int p, int pAns) {
		res[cur] = max(max1[cur], pAns);
		for (edge &e : nodes[cur].edges) {
			if (e.v == p) { continue; }
			int cMax = (1 + max1[e.v]) == max1[cur] ? max2[cur] : max1[cur];
			int cAns = max(pAns + 1, cMax + 1);	dfs(e.v, cur, cAns);
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	} g.init(0, -1); g.dfs(0, -1, 0);

	for (auto &x : res) cout << x << ' '; cout << '\n';
}