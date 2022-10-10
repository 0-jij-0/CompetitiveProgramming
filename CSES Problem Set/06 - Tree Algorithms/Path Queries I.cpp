#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
typedef long long ll;

struct FT {
	int n; vector<ll> vals;
	FT(int n) : n(n), vals(n + 1, 0ll) {}

	void update(int i, ll x) {
		for (++i; i <= n; i += i & -i) { vals[i] += x; }
	}

	ll query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < n); ll sum = 0;
		for (++i; i; i -= i & -i) { sum += vals[i]; }
		return sum;
	}
	ll query(int i, int j) const { return query(j) - query(i - 1); }
};

vector<int> start, finish, a, v;

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
	void dfs(int cur, int p, int &t) {
		start[cur] = t; t++;
		for (edge &e : nodes[cur].edges)
			if (e.v != p) dfs(e.v, cur, t);
		finish[cur] = t; t++;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q; graph g(n);
	start.resize(n); finish.resize(n); 
	a.resize(n); v.resize(n << 1);
	for (auto &x : a) { cin >> x; }
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	int t = 0; g.dfs(0, -1, t); FT ft(n << 1);
	for (int i = 0; i < n; i++) {
		v[start[i]] = a[i]; ft.update(start[i], a[i]);
		v[finish[i]] = a[i]; ft.update(finish[i], -a[i]);
	}
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int s, x; cin >> s >> x; s--;
			ft.update(start[s], x - v[start[s]]);
			ft.update(finish[s], - x + v[start[s]]);
			v[start[s]] = x; v[finish[s]] = -x;
		}
		else {
			int s; cin >> s; s--;
			cout << ft.query(0, start[s]) << '\n';
		}
	}
	cin.ignore(2); return 0;
}