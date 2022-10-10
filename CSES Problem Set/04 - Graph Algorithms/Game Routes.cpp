#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

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
	}
	
	ll count(int cur, vector<ll> &res) {
		if (res[cur] != -1) { return res[cur]; }
		ll ans = 0; for (edge &e : nodes[cur].edges) {
			ans = (ans + count(e.v, res)) % mod;
		}
		return res[cur] = ans;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	vector<ll> res(n, -1); res.back() = 1;
	cout << g.count(0, res) << '\n';
}