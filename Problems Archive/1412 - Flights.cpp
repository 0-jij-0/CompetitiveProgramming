#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w = 0) :
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge& rhs) const { return w < rhs.w; }
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
		used[v] = true;
		component.push_back(v);
		for (auto& x : nodes[1][v].edges)
			if (!used[x.v]) { scc_dfs2(x.v, used, component); }
	}

	bool SCC(int& t) {
		vector<bool> used(n, false);
		vector<int> order, component, scc(n);
		for (int i = 0; i < n; i++)
			if (!used[i]) { scc_dfs1(i, used, order); }
		used.assign(n, false);
		for (int i = 0; i < n; i++) {
			int v = order[n - 1 - i];
			if (!used[v]) {
				scc_dfs2(v, used, component);
				for (auto& x : component) { scc[x] = t; }
				component.clear(); t++;
			}
		}
		return t == 1;
	}
};

vector<edge> edges; int n, m;

bool check(int w) {
	graph g(n);
	for (int i = 0; i < m; i++) {
		if (edges[i].w > w) { break; }
		g.add_edge(edges[i].u, edges[i].v);
	}
	int t = 0; return g.SCC(t);
}

int findMinSize() {
	int l = 0, r = 1 << 30;
	while (l != r) {
		int mid = (l + r) >> 1;
		check(mid) ? r = mid : l = mid + 1;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n; m = n * (n - 1);
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int x; cin >> x; if (i == j) { continue; }
			edges.emplace_back(i, j, x);
		}
	sort(edges.begin(), edges.end());
	cout << findMinSize() << '\n';

	cin.ignore(2); return 0;
}