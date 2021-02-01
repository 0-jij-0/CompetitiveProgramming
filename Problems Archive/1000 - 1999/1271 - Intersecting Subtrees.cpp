#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
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

	int bfs(int u, vector<int> &v) {
		vector<int> vis(n, 0);
		for (auto &x : v) { vis[x] = 2; }
		if (vis[u] == 2) { return u; }
		queue<int> q; q.push(u);

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (edge &e : nodes[cur].edges) {
				if (vis[e.v] == 2) { return e.v; }
				if (vis[e.v]) { continue; }
				q.push(e.v); vis[e.v] = 1;
			}
		}
	}
};

vector<int> v1, v2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; graph g(n);
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			u--; v--; g.add_edge(u, v);
		}
		int k1; cin >> k1; v1.resize(k1);
		for (auto &x : v1) { cin >> x; x--; }
		int k2; cin >> k2; v2.resize(k2);
		for (auto &x : v2) { cin >> x; x--; }

		cout << "B " << v2[0] + 1 << endl;
		int R; cin >> R; R = g.bfs(R - 1, v1);
		cout << "A " << R + 1 << endl;
		int Q; cin >> Q; bool b = find(v2.begin(), v2.end(), Q - 1) != v2.end();
		cout << "C " << (b ? R + 1 : -1) << endl;
	}

	cin.ignore(2); return 0;
}