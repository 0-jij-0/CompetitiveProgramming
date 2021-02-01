#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<ll> v;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<edge> edges;
	vector<ll> subSize; vector<int> depth;
	graph(int _n) : n(_n), nodes(_n), subSize(_n), depth(_n, 0) {}

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
		edges.emplace_back(u, v);
	}

	ll dfs(int cur, int p = -1) {
		ll res = 0; for (edge &e : nodes[cur].edges) {
			if (e.v == p) { continue; }
			depth[e.v] = 1 + depth[cur];
			res += dfs(e.v, cur);
		}
		return subSize[cur] = 1 + res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; graph g(n);
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			u--; v--; g.add_edge(u, v);
		}
		g.dfs(0); vector<ll> cont(n - 1);

		for (int i = 0; i < n - 1; i++) {
			edge &e = g.edges[i];
			if (g.depth[e.u] > g.depth[e.v]) { swap(e.u, e.v); }
			cont[i] = g.subSize[e.v] * (n - g.subSize[e.v]);
		}

		int m; cin >> m; v.resize(m);
		for (auto &x : v) { cin >> x; }
		while (m < n - 1) { v.push_back(1); m++; }
		sort(cont.begin(), cont.end()); sort(v.begin(), v.end());

		while (m > n - 1) {
			v[m - 2] = (v[m - 2] * v[m - 1]) % mod;
			v.pop_back(); m--;
		}
		ll res = 0; for (int i = 0; i < n - 1; i++)
			res = (res + (v[i] % mod) * (cont[i] % mod)) % mod;
		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}