#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

ll dp[300000][2];
vector<int> d;

struct edge {
	int u, v, w;
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
};

struct graph {
	vector<vector<edge>> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, int w) {
		nodes[u].emplace_back(u, v, w);
		nodes[v].emplace_back(v, u, w);
	}

	ll selectEdges(int cur, int p, bool keptPar) {
		if (dp[cur][keptPar] != -INF) { return dp[cur][keptPar]; }

		int keep = d[cur] - keptPar; ll res = 0;
		priority_queue<ll, vector<ll>, greater<ll>> pq;

		for (edge& e : nodes[cur]) if(e.v != p) {
			ll select = d[e.v] == 0 ? -INF : e.w + selectEdges(e.v, cur, 1);
			ll remove = selectEdges(e.v, cur, 0);
			ll change = select - remove; res += remove;

			if (change < 0 || keep == 0) { continue; }
			if ((int)pq.size() < keep) { res += change; pq.push(change); continue; }
			if (keep && pq.top() < change) { res += change - pq.top(); pq.pop(); pq.push(change); }
		}
		
		return dp[cur][keptPar] = res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n); d.resize(n);
	for (auto& x : d) { cin >> x; }
	for (int i = 1; i < n; i++) {
		int u, v, w; cin >> u >> v >> w;
		g.add_edge(--u, --v, w);
	}
	fill(dp[0], dp[0] + 300000 * 2, -INF);
	cout << g.selectEdges(0, -1, 0) << '\n';
}