#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

vector<int> A;

struct Graph {
	vector<vector<int>> nodes; int n;
	vector<ll> _cost;
	Graph(int _n) : n(_n), nodes(_n), _cost(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v); _cost[u] += A[v];
		nodes[v].emplace_back(u); _cost[v] += A[u];
	}

	bool bfs(ll K) {
		vector<ll> cost = _cost;
		queue<int> Q; vector<bool> vis(n, false);
		for (int i = 0; i < n; i++) if (cost[i] <= K) {
			Q.push(i); vis[i] = true;
		}

		int v = 0; while (!Q.empty()) {
			int cur = Q.front(); Q.pop(); v++;
			for (auto& e : nodes[cur]) if(!vis[e]) 
				if((cost[e] -= A[cur]) <= K){ Q.push(e); vis[e] = true;	}
		}

		return v == n;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; Graph G(n);
	A.resize(n); for (auto& x : A) cin >> x;

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		G.addEdge(--u, --v);
	}

	ll L = 0, R = 1ll << 50;
	while (L != R) {
		ll M = (L + R) >> 1;
		G.bfs(M) ? R = M : L = M + 1;
	}

	cout << L << '\n';

}