#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

vector<int> a, subtreeXor;

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(v);
		nodes[v].edges.emplace_back(u);
	}

	bool bfs(int u, int XS) {
		vector<int> par(n, -1), vis(n, false);
		queue<int> q; q.push(u); vis[u] = true;

		vector<int> order; while (!q.empty()) {
			int cur = q.front(); q.pop();
			order.push_back(cur);

			for (int& e : nodes[cur].edges) {
				if (vis[e]) { continue; }
				par[e] = cur; q.push(e); vis[e] = true;
			}
		}

		bool f = false;
		for (int i = n - 1; i > 0; i--) {
			if (!f && subtreeXor[order[i]] == XS) {
				int cur = order[i];	while (cur != -1) { 
					subtreeXor[cur] ^= XS; cur = par[cur];
				}
				f = true; continue;
			}
			if (subtreeXor[order[i]] == XS) { return true; }
		}

		return false;
	}

	int xorDFS(int cur, int p = -1) {
		int res = 0; for (auto& e : nodes[cur].edges) {
			if(e != p) res ^= xorDFS(e, cur);
		}
		return subtreeXor[cur] ^= res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k;
		graph g(n); a.resize(n);
		for (auto& x : a) { cin >> x; }
		subtreeXor = a;

		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			g.add_edge(--u, --v);
		}

		int xS = 0; for (auto& x : a) xS ^= x;
		if (xS == 0) { cout << "YES\n"; continue; }
		if (k == 2) { cout << "NO\n"; continue; }

		g.xorDFS(0); cout << (g.bfs(0, xS) ? "YES" : "NO") << '\n';
	}

	cin.ignore(2); return 0;
}