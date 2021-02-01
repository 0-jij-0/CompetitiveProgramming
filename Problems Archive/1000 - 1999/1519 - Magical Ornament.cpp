#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

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

	void bfs(int u, vector<int>& visited, int& t) {
		queue<int> q; q.push(u); visited[u] = t;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (edge& e : nodes[cur].edges) {
				if (visited[e.v]) { continue; }
				q.push(e.v); visited[e.v] = t;
			}
		}
	}

	void spBFS(int u, vector<int>& dist) {
		queue<int> q; q.push(u); 
		dist.resize(n, -1); dist[u] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (edge& e : nodes[cur].edges) {
				if (dist[e.v] != -1) { continue; }
				q.push(e.v); dist[e.v] = 1 + dist[cur];
			}
		}
	}
};

vector<int> c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--; g.add_edge(a, b);
	}

	int k; cin >> k; c.resize(k);
	for (auto& x : c) { cin >> x; x--; }

	int t = 0; vector<int> comp(n);
	for (int i = 0; i < n; i++)
		if (!comp[i]) g.bfs(i, comp, ++t);

	int cur = comp[c[0]]; bool ok = true;
	for (int i = 1; i < k && ok; i++)
		if (comp[c[i]] != cur) ok = false;
	if (!ok) { cout << -1 << '\n'; }
	else {
		vector<vector<int>> dist(n);
		for (int i = 0; i < k; i++) { g.spBFS(c[i], dist[c[i]]); }

		vector<vector<ll>> dp(1 << k, vector<ll>(k, 1ll << 50));
		for (int i = 0; i < k; i++) { dp[1 << i][i] = 1; }
		for(int i = 1; i < (1 << k); i++)
			for(int j = 0; j < k; j++) if(i & (1 << j))
				for (int x = 0; x < k; x++) if (!(i & (1 << x)))
					dp[i | (1 << x)][x] = min(dp[i | (1 << x)][x], dp[i][j] + dist[c[j]][c[x]]);

		ll res = *min_element(dp[(1 << k) - 1].begin(), dp[(1 << k) - 1].end());
		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}