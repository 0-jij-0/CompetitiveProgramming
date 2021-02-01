#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

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

	pair<int, int> bfs(int s, int d = -1) {
		queue<int> q; q.push(s); int res = -1;
		vector<int> dist(n, -1); dist[s] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop(); res = cur;
			for (edge &e : nodes[cur].edges) {
				if (dist[e.v] != -1) { continue; }
				dist[e.v] = 1 + dist[cur]; q.push(e.v);
			}
		}
		return d == -1 ? pair<int, int>(res, dist[res]) : pair<int, int>(d, dist[d]);
	}
	
	int diameter() { return bfs(bfs(0).first).second; }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, a, b, da, db; cin >> n >> a >> b >> da >> db;
		a--; b--; graph g(n); for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			u--; v--; g.add_edge(u, v);
		}
		if (da >= db || g.bfs(a, b).second <= da) { cout << "Alice" << '\n'; continue; }
		int d = g.diameter(); db = min(db, d); da = min(da, d);
		cout << (db > 2 * da ? "Bob" : "Alice") << '\n';
	}

	cin.ignore(2); return 0;
}