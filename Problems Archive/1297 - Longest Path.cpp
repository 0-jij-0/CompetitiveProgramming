#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

vector<int> dp;

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(v);
	}

	int longestPath(int cur) {
		if (dp[cur]) return dp[cur];
		int res = 0; for (auto &e : nodes[cur].edges)
			res = max(res, longestPath(e));
		return dp[cur] = 1 + res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	dp.resize(n, 0); int res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, g.longestPath(i));
	cout << res - 1 << '\n';
	cin.ignore(2); return 0;
}