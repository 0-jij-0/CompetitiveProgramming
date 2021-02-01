#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct edge {
	int id, u, v; edge() {}
	edge(int _id, int _u, int _v) :
		id(_id), u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int id, int u, int v) {
		edge e1(id, u, v), e2(id, v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n; cin >> n; graph g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(i, u, v);
	}
	int m = 0; vector<int> res(n - 1, -1);
	for (auto &x : g.nodes) {
		if (x.edges.size() > 2) {
			for (auto &y : x.edges) { res[y.id] = m++; }
			break;
		}
	}

	if (m == 0) { for (int i = 0; i < n - 1; i++) cout << i << endl; }
	else {
		for (int i = 0; i < n - 1; i++)
			cout << (res[i] == -1 ? m++ : res[i]) << endl;
	}

	cin.ignore(2); return 0;
}