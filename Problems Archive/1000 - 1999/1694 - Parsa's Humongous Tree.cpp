#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <array>
using namespace std;
typedef long long ll;

ll dp[100001][2];
vector<array<int, 2>> val;

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

	void bfs(int u, vector<bool>& visited) {
		queue<int> q; q.push(u);
		visited[u] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (edge& e : nodes[cur].edges) {
				if (visited[e.v]) { continue; }
				q.push(e.v); visited[e.v] = true;
			}
		}
	}

	ll maxBeauty(int cur, bool c, int p = -1) {
		if (dp[cur][c] != -1) { return dp[cur][c]; }
		ll res = 0; for (edge& e : nodes[cur].edges) {
			if (e.v == p) { continue; }
			ll A = maxBeauty(e.v, 0, cur) + abs(val[cur][c] - val[e.v][0]);
			ll B = maxBeauty(e.v, 1, cur) + abs(val[cur][c] - val[e.v][1]);
			res += max(A, B);
		} return dp[cur][c] = res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; val.resize(n);
		for (auto& x : val) cin >> x[0] >> x[1];

		graph g(n); for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			u--; v--; g.add_edge(u, v);
		}

		for (int i = 0; i < n; i++)
			dp[i][0] = dp[i][1] = -1;

		cout << max(g.maxBeauty(0, 0), g.maxBeauty(0, 1)) << '\n';
	}

	cin.ignore(2); return 0;
}