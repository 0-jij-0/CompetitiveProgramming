#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes[2]; int n;
	graph(int _n) : n(_n) { nodes[0].resize(n); nodes[1].resize(n); }

	void add_edge(int u, int v, bool bu, bool bv) {
		int pu = u << 1 | !bu, pv = v << 1 | !bv;
		int nu = u << 1 | bu, nv = v << 1 | bv;
		add_edge(nu, pv); add_edge(nv, pu);
	}
	void add_edge(int u, int v) {
		nodes[0][u].edges.emplace_back(u, v);
		nodes[1][v].edges.emplace_back(v, u);
	}

	void scc_dfs1(int v, vector<bool> &used, vector<int> &order) {
		used[v] = true;
		for (auto &x : nodes[0][v].edges)
			if (!used[x.v]) { scc_dfs1(x.v, used, order); }
		order.push_back(v);
	}

	void scc_dfs2(int v, vector<bool> &used, vector<int> &component) {
		used[v] = true;
		component.push_back(v);
		for (auto &x : nodes[1][v].edges)
			if (!used[x.v]) { scc_dfs2(x.v, used, component); }
	}

	vector<int> SCC(int &t) {
		vector<bool> used(n, false);
		vector<int> order, component, scc(n);
		for (int i = 0; i < n; i++)
			if (!used[i]) { scc_dfs1(i, used, order); }
		used.assign(n, false);
		for (int i = 0; i < n; i++) {
			int v = order[n - 1 - i];
			if (!used[v]) {
				scc_dfs2(v, used, component);
				for (auto &x : component) { scc[x] = t; }
				component.clear(); t++;
			}
		}
		return scc;
	}

	vector<int> TWOSAT() {
		int t = 0; vector<int> scc = SCC(t);
		vector<int> res(n >> 1);
		for (int i = 0; i < n; i += 2) {
			if (scc[i] == scc[i + 1]) { return vector<int>(); }
			res[i >> 1] = scc[i] > scc[i + 1];
		}
		return move(res);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(2 * m);
	for (int i = 0; i < n; i++) {
		char c1, c2; int u, v; cin >> c1 >> u >> c2 >> v;
		u--; v--; g.add_edge(u, v, c1 == '+', c2 == '+');
	}
	vector<int> res = g.TWOSAT();
	if (res.empty()) { cout << "IMPOSSIBLE\n"; return 0; }
	for (auto &x : res) cout << (x ? '+' : '-') << ' '; cout << '\n';
}