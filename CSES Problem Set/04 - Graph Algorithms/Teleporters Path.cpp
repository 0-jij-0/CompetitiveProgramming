#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { int inD = 0, outD = 0; vector<int> edges; };

struct graph {
	vector<edge> edges;
	vector<node> nodes;
	int n, m;
	graph(int _n) : n(_n), m(0) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.push_back(m++);
		nodes[u].outD++; nodes[v].inD++;
		edges.push_back(edge(u, v));
	}

	vector<int> euler_directed() {
		int start = -1, finish = -1, oddIn = 0, oddOut = 0;
		for (int i = 0; i < n; ++i) {
			int diff = nodes[i].inD - nodes[i].outD;
			if (abs(diff) > 1) { return vector<int>(); }
			if (diff == -1) { oddOut++; start = i; }
			else if (diff == 1) { oddIn++; finish = i; }
			else if (diff == 0 && start == -1) { start = i; }
		}

		if (oddOut != 1 || oddIn != 1 || start != 0 || finish != n - 1) { return vector<int>(); }
		vector<bool> used(m, 0);
		vector<int> stack, res, which(n + 1, 0);
		stack.push_back(start);
		while (!stack.empty()) {
			int v = stack.back();
			while (which[v] < (int)nodes[v].edges.size() && used[nodes[v].edges[which[v]]]) { which[v]++; }
			if (which[v] == (int)nodes[v].edges.size()) {
				stack.pop_back(); res.push_back(v);
			}
			else {
				int ed = nodes[v].edges[which[v]];
				int w = (edges[ed].u) == v ? edges[ed].v : edges[ed].u;
				used[ed] = 1; stack.push_back(w);
			}
		}
		if (count(used.begin(), used.end(), false)) { return vector<int>(); }
		reverse(res.begin(), res.end());
		return res;
	}
};

int main() {
	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		g.add_edge(--a, --b);
	}
	vector<int> res = g.euler_directed();
	if (res.empty()) { cout << "IMPOSSIBLE\n"; return 0; }
	for (auto& x : res) cout << x + 1 << ' '; cout << '\n';
}