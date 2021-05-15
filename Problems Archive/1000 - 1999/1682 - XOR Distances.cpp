#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<ll> v; ll res = 0;

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, ll w) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
	}

	void dfs1(int cur, int prev, ll W) {
		v[cur] = W; for (edge& e : nodes[cur].edges)
			if (e.v != prev) { dfs1(e.v, cur, W ^ e.w); }
	}

	void dfs2(int cur, int prev, int cnt, ll W, bool inv = false) {
		ll cont = ((inv ? n - cnt : cnt) * (W % mod)) % mod;
		res = (res + cont) % mod; for (edge& e : nodes[cur].edges) {
			if (e.v == prev) { continue; }
			bool b = (e.w & W) != 0;
			dfs2(e.v, cur, cnt, W, inv ^ b);
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n); v.resize(n);
	for (int i = 1; i < n; i++) {
		int u, v; ll w; cin >> u >> v >> w;
		g.add_edge(--u, --v, w);
	}

	g.dfs1(0, -1, 0);

	for (int i = 0; i <= 60; i++) {
		int cnt = 0; ll W = 1ll << i;
		for (int j = 0; j < n; j++)
			if (v[j] & W) { cnt++; }
		g.dfs2(0, -1, cnt, W);
	}

	cout << (res * 500000004) % mod << '\n';
	cin.ignore(2); return 0;
}