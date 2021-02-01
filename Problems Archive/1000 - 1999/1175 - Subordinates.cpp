#include <iostream>
#include <vector>
using namespace std;

vector<int> res;

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

	int subordinates(int cur, int p) {
		if (res[cur] != -1) { return res[cur]; }
		int ans = 0; for (edge &e : nodes[cur].edges) {
			if (e.v == p) { continue; }
			ans += 1 + subordinates(e.v, cur);
		}
		return res[cur] = ans;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n); res.resize(n, -1);
	for (int i = 1; i < n; i++) {
		int p; cin >> p; p--; g.add_edge(i, p);
	} g.subordinates(0, -1);

	for (auto &x : res) cout << x << ' ';
	cout << '\n'; cin.ignore(2); return 0;
}