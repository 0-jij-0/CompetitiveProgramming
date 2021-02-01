#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

	int findMex(int cur, vector<int> &mex) {
		if (mex[cur] != -1) { return mex[cur]; }
		vector<bool> cand(nodes[cur].edges.size(), 0);
		for (edge &e : nodes[cur].edges) {
			int m = findMex(e.v, mex); 
			if (m >= cand.size()) { continue; }
			cand[m] = true;
		}
		return mex[cur] = find(cand.begin(), cand.end(), false) - cand.begin();
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while (true) {
		int n, m; cin >> n >> m;
		graph g(n); vector<int> mex(n, -1);
		if (n + m == 0) { break; }
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			g.add_edge(u, v);
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x; if (x & 1)
				res ^= g.findMex(i, mex);
		}
		cout << (res ? "First" : "Second") << '\n';
	}
	cin.ignore(2); return 0;
}