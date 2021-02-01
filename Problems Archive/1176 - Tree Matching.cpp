#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[200005][2];

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
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	int treeMatching(int cur, int p, bool match) {
		if (dp[cur][match] != -1) { return dp[cur][match]; }

		int res = 0, sum = 0;
		for (edge &e : nodes[cur].edges) {
			if (e.v == p) { continue; }
			sum += treeMatching(e.v, cur, 0);
			treeMatching(e.v, cur, 1);
		}
		res = sum; if (!match) {
			for (edge &e : nodes[cur].edges) {
				if (e.v == p) { continue; }
				int notTaken = dp[e.v][0], taken = dp[e.v][1];
				res = max(res, sum - notTaken + taken + 1);
			}
		}
		return dp[cur][match] = res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	fill(dp[0], dp[0] + 200005 * 2, -1);
	cout << g.treeMatching(0, -1, 0) << '\n';
	cin.ignore(2); return 0;
}