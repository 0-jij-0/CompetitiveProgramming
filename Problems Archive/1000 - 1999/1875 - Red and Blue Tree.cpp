#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll dp[1000][100001];
map<pair<int, int>, int> edges;
vector<int> a;

struct graph {
	vector<vector<int>> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	void bfs(int s, int t) {
		queue<int> q; q.push(s);
		vector<int> vis(n, 0); vis[s] = 1;
		vector<int> par(n, -1);

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			if (cur == t) { break; }

			for (auto& e : nodes[cur]) {
				if (vis[e]) { continue; }
				q.push(e); par[e] = cur; vis[e] = 1;
			}
		}

		while (t != s) {
			int u = par[t], v = t;
			if (u > v) { swap(u, v); }
			edges[{u, v}]++; t = par[t];
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k; cin >> n >> m >> k; 
	graph g(n); a.resize(m);
	for (auto& x : a) { cin >> x; x--; }

	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		if (--u > --v) { swap(u, v); }
		edges[{u, v}]; g.add_edge(u, v);
	}

	for (int i = 1; i < m; i++) {
		g.bfs(a[i - 1], a[i]);
	}

	vector<int> v; int sum = 0;
	for (auto& x : edges) {
		v.push_back(x.second);
		sum += x.second;
	}

	if ((sum + k) % 2) { cout << 0 << '\n'; return 0; }

	int B = (sum - k) >> 1;
	fill(dp[0], dp[0] + 1000 * 100000, 0);

	dp[0][0] = 1; for(int i = 0; i < n - 1; i++)
		for (int j = 0; j <= B; j++) if(dp[i][j]) {
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
			dp[i + 1][j + v[i]] = (dp[i + 1][j + v[i]] + dp[i][j]) % mod;
		}

	cout << dp[n - 1][B] << '\n';
	cin.ignore(2); return 0;
}