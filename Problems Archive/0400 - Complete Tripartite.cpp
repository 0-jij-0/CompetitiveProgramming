#include <iostream>
#include <vector>
#include <set>
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
		edge e1(u, v), e2(v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--; g.add_edge(a, b);
	}
	for (int i = 0; i < n; i++)
		if ((int)g.nodes[i].edges.size() == 0) {
			cout << -1 << endl; cin.ignore(2); return 0;
		}

	set<int> a[3], d;
	for (auto &x : g.nodes[0].edges) { d.insert(x.v); }
	for (int i = 0; i < n; i++)
		if (!d.count(i)) { a[0].insert(i); }
	int idx = g.nodes[0].edges[0].v; d.clear();
	for (auto &x : g.nodes[idx].edges) { d.insert(x.v); }
	for (int i = 0; i < n; i++)
		if (!d.count(i)) { a[1].insert(i); }
	d.clear();
	for (int i = 0; i < n; i++)
		if (!a[0].count(i) && !a[1].count(i)) { a[2].insert(i); }
	if (a[0].empty() || a[1].empty() || a[2].empty()) { cout << -1 << endl; }
	else {
		bool bo = true;
		for (int i = 0; i < 3; i++) {
			int p = (i + 1) % 3, q = (i + 2) % 3;
			for (auto &x : a[i]) {
				node &no = g.nodes[x];
				if (no.edges.size() != a[p].size() + a[q].size()) { bo = false; goto RES; }
				for (auto &y : no.edges) {
					if (!a[p].count(y.v) && !a[q].count(y.v)) { bo = false; goto RES; }
				}
			}
		}

	RES: if (!bo) { cout << -1 << endl; }
		else {
			for (int i = 0; i < n; i++) {
				if (a[0].count(i)) { cout << 1; }
				else if (a[1].count(i)) { cout << 2; }
				else { cout << 3; }
				if (i + 1 != n) { cout << ' '; }
				else { cout << endl; }
			}
		}
	}
	cin.ignore(2); return 0;
}