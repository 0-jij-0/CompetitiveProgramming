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

vector<int> parent, dist;

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v), e2(v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	pair<int, int> bfs(int u) {
		vector<bool> visited(n, false);
		queue<int> q; q.push(u); visited[u] = true;

		while (!q.empty()) {
			int f = q.front(); q.pop();
			node &n = nodes[f];

			for (edge &e : n.edges) {
				if (visited[e.v] && parent[f] == e.v) { continue; }
				if (visited[e.v]) {	return { f, e.v }; }
				q.push(e.v); visited[e.v] = true;
				parent[e.v] = f; dist[e.v] = 1 + dist[f];
			}
		}
		return { -1, -1 };
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k; cin >> n >> m >> k; 
	graph g(n); parent.resize(n, -1); dist.resize(n, 0);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	pair<int, int> p = g.bfs(0);
	if (p.first == -1) {
		int e = 0, o = 0; cout << 1 << '\n';
		for (auto &x : dist) (x % 2 ? o : e)++;
		int rem = (k + 1) / 2;
		for(int i = 0; i < n && rem; i++)
			if (o >= e && dist[i] % 2) { cout << i + 1 << ' '; rem--; }
			else if (e > o && dist[i] % 2 == 0) { cout << i + 1 << ' '; rem--; }
		cout << '\n'; cin.ignore(2); return 0;
	}
	else {
		int u = p.first, v = p.second;
		vector<int> U(1, u), V(1, v);
		while (u != -1) { U.push_back(u = parent[u]); }
		while (v != -1) { V.push_back(v = parent[v]); }
		int a = (int) U.size() - 1, b = (int) V.size() - 1;
		while (a && b && U[--a] == V[--b]) { U.pop_back(); V.pop_back(); }
		for (int i = b; i >= 0; i--) { U.push_back(V[i]); }
		if ((int) U.size() <= k) {
			cout << 2 << '\n' << U.size() << '\n';
			for (auto &x : U) { cout << x + 1 << ' '; }
			cout << '\n'; cin.ignore(2); return 0;
		}
		cout << 1 << '\n';
		for (int i = 0; i < k; i += 2)
			cout << U[i] + 1 << ' ';
		cout << '\n'; cin.ignore(2); return 0;
	}
}