#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

vector<pair<int, int>> bombs;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<vector<int>> dist;
	graph(int _n) : n(_n) { nodes.resize(n); dist.resize(n, vector<int>(n, n + 2)); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	void bfs(int s) {
		queue<int> Q;
		vector<bool> visited(n, false);
		dist[s][s] = 0ll; Q.push(s);

		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			visited[cur] = true;

			for (auto& e : nodes[cur].edges) {
				if (visited[e.v]) { continue; }
				visited[e.v] = true;
				dist[s][e.v] = dist[s][e.u] + 1;
				Q.push(e.v);
			}
		}
	}

	bool check(int d) {
		int cur = bombs[0].second, day = d;

		for (auto& bomb : bombs) {
			int avTime = bomb.first - day;
			if (dist[cur][bomb.second] > avTime) { return false; }
			day += dist[cur][bomb.second];
			cur = bomb.second;
		}

		return true;
	}
};

int main() {
	freopen("ysys.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, q; cin >> n >> m >> q; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; 
		u--; v--; g.add_edge(u, v);
	}

	while (q--) {
		int d, c; cin >> d >> c;
		bombs.push_back({ d, --c });
	}

	int res = 0; for (int i = 0; i < n; i++) { g.bfs(i); }
	if (!g.check(0)) { cout << 0 << '\n'; return 0; }

	int l = 0, r = bombs[0].first;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		g.check(mid) ? l = mid : r = mid - 1;
	}

	int firstC = bombs[0].second;
	for (int i = 0; i < n; i++)
		res += (g.dist[i][firstC] <= l);

	cout << res << '\n';
	cin.ignore(2); return 0;
}