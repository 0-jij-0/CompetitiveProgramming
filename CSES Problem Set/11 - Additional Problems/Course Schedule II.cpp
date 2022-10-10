#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<int> in; int OUT = 0; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[v].in.emplace_back(u);
		nodes[u].OUT++;
	}

	vector<int> sortedTopologicalSort() {
		priority_queue<int> pq; 
		for (int i = 0; i < n; i++)
			if (nodes[i].OUT == 0) pq.push(i);

		vector<int> res; while (!pq.empty()) {
			int cur = pq.top(); pq.pop();

			res.push_back(cur); 
			for (auto& e : nodes[cur].in)
				if (!--nodes[e].OUT) pq.push(e);
		}
		reverse(res.begin(), res.end()); return move(res);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g.add_edge(--u, --v);
	}

	vector<int> res = g.sortedTopologicalSort();
	for (auto& x : res) cout << x + 1 << ' '; cout << '\n';
}