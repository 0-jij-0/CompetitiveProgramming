#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <set>
using namespace std;

struct DSU {
	vector<int> rank, parent;

	DSU(int n) : rank(n, 1), parent(n) {
		iota(parent.begin(), parent.end(), 0);
	}

	bool same(int u, int v) { return find(u) == find(v); }
	int find(const int& u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return false;
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

struct Graph {
	vector<vector<int>> nodes; int n;
	vector<pair<int, int>> edges;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
		edges.emplace_back(u, v);
	}

	set<pair<int, int>> bfs(int s, int t) {
		queue<int> q; q.push(s);
		vector<int> par(n, -1); par[s] = s;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto& e : nodes[cur]) {
				if (par[e] != -1) { continue; }
				q.push(e); par[e] = cur;
			}
		}

		vector<int> path(1, t); set<pair<int, int>> res;
		while (path.back() != s) path.push_back(t = par[t]);
		for (int i = 1; i < (int)path.size(); i++) {
			res.insert({ path[i], path[i - 1] });
			res.insert({ path[i - 1], path[i] });
		}

		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; vector<int> cycleEdge;
	DSU dsu(n); Graph G(n);
	for (int i = 0; i < n; i++) {
		int u, v; cin >> u >> v;
		if (dsu.merge(--u, --v)) G.addEdge(u, v);
		else { cycleEdge = { u, v }; }
	}

	set<pair<int, int>> cycleEdges = G.bfs(cycleEdge[0], cycleEdge[1]);
	cycleEdges.insert({ cycleEdge[0], cycleEdge[1] });
	cycleEdges.insert({ cycleEdge[1], cycleEdge[0] });

	dsu = DSU(n); for (auto& e : G.edges)
		if (!cycleEdges.count(e)) dsu.merge(e.first, e.second);

	int q; cin >> q; while (q--) {
		int x, y; cin >> x >> y;
		cout << (dsu.same(--x, --y) ? "Yes" : "No") << '\n';
	}
}