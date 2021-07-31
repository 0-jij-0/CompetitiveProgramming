#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<edge> edges; int m;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u); //Undirected
		edges.emplace_back(u, v);
		edges.emplace_back(v, u); //Undirected
	}

	//Check if Cycle is reachable if given some destination (switch to vector)
	ll bellman_ford(int k) { //returns negative weight cycle
		vector<ll> d[2]; d[0].resize(n, 0); 
		d[1].resize(n, 0); d[0][0] = 1;
		for (int i = 1; i <= k; i++) {
			ll sum = 0; for (auto& x : d[(i & 1) ^ 1]) { sum = (sum + x) % mod; }
			for (int j = 0; j < n; j++) d[i & 1][j] = (sum - d[(i & 1) ^ 1][j] + mod) % mod;
			for (edge& e : edges) d[i & 1][e.v] = (d[i & 1][e.v] - d[(i & 1) ^ 1][e.u] + mod) % mod;
		}
		return d[k & 1][0];
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k; cin >> n >> m >> k; graph g(n);
	set<pair<int, int>> edges;

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; 
		u--; v--; g.add_edge(u, v);
	}

	cout << g.bellman_ford(k) << '\n';
	cin.ignore(2); return 0;
}