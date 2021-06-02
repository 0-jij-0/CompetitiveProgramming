#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
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

	void add_edge(int u, int v) {
		nodes[0][u].edges.emplace_back(u, v);
		nodes[1][v].edges.emplace_back(v, u);
	}

	void scc_dfs1(int v, vector<bool>& used, vector<int>& order) {
		used[v] = true;
		for (auto& x : nodes[0][v].edges)
			if (!used[x.v]) { scc_dfs1(x.v, used, order); }
		order.push_back(v);
	}

	void scc_dfs2(int v, vector<bool>& used, vector<int>& component) {
		used[v] = true; component.push_back(v);
		for (auto& x : nodes[1][v].edges)
			if (!used[x.v]) { scc_dfs2(x.v, used, component); }
	}

	vector<int> SCC(vector<vector<int>> &scc) {
		vector<bool> used(n, false); int t = 0;
		vector<int> order, component, res(n);
		for (int i = 0; i < n; i++)
			if (!used[i]) { scc_dfs1(i, used, order); }
		used.assign(n, false);
		for (int i = 0; i < n; i++) {
			int v = order[n - 1 - i];
			if (!used[v]) {
				scc_dfs2(v, used, component); scc.emplace_back();
				for (auto& x : component) { res[x] = t; scc[t].push_back(x); }
				component.clear(); t++;
			}
		}
		return move(res);
	}
};

vector<bitset<50000>> dp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, q; cin >> n >> m >> q; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}

	vector<vector<int>> scc;
	vector<int> v = g.SCC(scc);
	int N = (int)scc.size(); dp.resize(N);
	for (int i = N - 1; i >= 0; i--) {
		for(auto &x : scc[i]) for (edge& e : g.nodes[0][x].edges)
			dp[i] |= dp[v[e.v]]; dp[i][i] = 1;
	}

	while (q--) {
		int a, b; cin >> a >> b; a--; b--;
		if (v[a] == v[b]) { cout << "YES\n"; continue; }
		cout << (dp[v[a]][v[b]] ? "YES" : "NO") << '\n';
	}

	cin.ignore(2); return 0;
}