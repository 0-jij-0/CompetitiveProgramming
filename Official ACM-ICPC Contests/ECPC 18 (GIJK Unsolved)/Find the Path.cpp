#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>
using namespace std;
 
struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w = 1) :
		u(_u), v(_v), w(_w) {}
};
 
struct node { vector<edge> edges; };
 
struct graph {
	vector<node> nodes;
	vector<edge> edges;
	int n;
 
	graph(int _n) : n(_n) { nodes.resize(n); }
 
	void add_edge(int u, int v, int w) {
		edge e1(u, v, w); nodes[u].edges.push_back(e1);
		edge e2(v, u, w); nodes[v].edges.push_back(e2);
		edges.push_back(e1);
	}
 
	int bfs(int u, int k) {
		queue<int> Q; vector<bool> vis(n, 0);
		vector<int> dist(n, 1e7);
		dist[u] = 0; vis[u] = 1; Q.push(u);
 
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (auto& e : nodes[cur].edges) {
				if (vis[e.v]) { continue; }
				vis[e.v] = true; Q.push(e.v);
				dist[e.v] = dist[cur] + 1;
			}
		}
 
		int ans = 0;
		for (auto& e : edges) {
			if (dist[e.v] < k || dist[e.u] < k) 
				ans = max(ans, e.w);
		}
 
		return ans;
	}
};
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("path.in", "r", stdin);
 
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int s, L, K; cin >> s >> L >> K; s--;
		graph g(n);
		for (int i = 0; i < m; i++) {
			int u, v, w; cin >> u >> v >> w; u--; v--;
			g.add_edge(u, v, w);
		}
 
		cout << g.bfs(s, K) << '\n';
	}
}