#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
 
struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
};
 
struct node { int inD = 0, outD = 0; vector<int> edges; };
 
struct graph {
	vector<edge> edges;
	vector<node> nodes;
	int n, m;
	graph(int _n) : n(_n), m(0) { nodes.resize(n); }
 
	void add_edge(int u, int v, int w) {
		nodes[u].edges.push_back(m++);
		nodes[u].outD++; nodes[v].inD++;
		edges.push_back(edge(u, v, w));
	}
};
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
 
	freopen("bugged.in", "r", stdin);
 
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		graph g(n);
		vector<int> x(n); for (auto& xx : x) { cin >> xx; }
 
		ll ans = 0;
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v; u--; v--;
			int w = abs(x[v] - x[u]);
			g.add_edge(u, v, w);
			ans += w;
		}
 
		bool OK = true;
		for (int i = 0; i < n; i++) {
			if (g.nodes[i].inD != g.nodes[i].outD) { OK = false; break; }
		}
		if (!OK) { cout << -1 << '\n'; continue; }
		else { cout << ans << '\n'; }
	}
}