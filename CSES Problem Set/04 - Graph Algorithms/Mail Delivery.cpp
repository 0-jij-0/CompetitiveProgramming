#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v, id; edge() {}
	edge(int _u, int _v, int _id) :
		u(_u), v(_v), id(_id) {}
};

struct node { int id; vector<edge> edges; };

struct graph {
	vector<edge> edges;
	vector<node> nodes;
	int n, m;
	graph(int _n) : n(_n), m(0) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v, m), e2(v, u, m);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
		edges.push_back(e1); m++;
	}

	vector<int> euler_undirected() {
		int start = -1, odd_deg = 0;
		for (int i = 0; i < n; ++i) {
			if ((int)nodes[i].edges.size() & 1) { return vector<int>(); }
			if (nodes[i].edges.empty() && start == -1) { start = i; }
		}
		if (odd_deg || start != 0) { return vector<int>(); }
		vector<bool> used(m, 0);
		vector<int> stack, res, which(n + 1, 0);
		stack.push_back(start);
		while (!stack.empty()) {
			int v = stack.back();
			while (which[v] < (int)nodes[v].edges.size() && used[nodes[v].edges[which[v]].id]) { which[v]++; }
			if (which[v] == (int)nodes[v].edges.size()) {
				stack.pop_back(); res.push_back(v);
			}
			else {
				int ed = nodes[v].edges[which[v]].id;
				int w = (edges[ed].u) == v ? edges[ed].v : edges[ed].u;
				used[ed] = 1; stack.push_back(w);
			}
		}
		if (count(used.begin(), used.end(), false)) { return vector<int>(); }
		return res;
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
	vector<int> res = g.euler_undirected();
	if (res.empty()) { cout << "IMPOSSIBLE\n"; return 0; }
	for (auto &x : res) cout << x + 1 << ' '; cout << '\n';
}