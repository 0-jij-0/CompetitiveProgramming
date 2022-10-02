#include <bits/stdc++.h>
using namespace std;

struct Graph {
	vector<vector<int>> nodes; int n;
	vector<int> bfsOrder, par;
	Graph(int _n) : n(_n), nodes(_n), par(_n, -1) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	void bfs() {
		queue<int> q; q.push(0); par[0] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop(); 
			bfsOrder.push_back(cur);
			for (auto& e : nodes[cur]) if(par[e] == -1) {
				q.push(e); par[e] = cur;
			}
		}
	}

	bool check(int M, int k) {
		vector<int> height(n);
		for (int i = n - 1; i > 0; i--) {
			int cur = bfsOrder[i]; if (!par[cur]) break;
			for (auto& e : nodes[cur]) if(e != par[cur])
				height[cur] = max(height[cur], 1 + height[e]);

			if (height[cur] == M - 1) { --k; height[cur] = -1; }
		}
		return k >= 0;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k; Graph G(n);
		for (int i = 1; i < n; i++) {
			int p; cin >> p; G.addEdge(i, --p);
		}

		G.bfs(); int L = 1, R = n - 1;
		while (L != R) {
			int M = (L + R) >> 1;
			G.check(M, k) ? R = M : L = M + 1;
		}

		cout << L << '\n';
	}
}