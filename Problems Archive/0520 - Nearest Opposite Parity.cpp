#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v, res, even, odd;

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
		edge e(u, v); nodes[u].edges.push_back(e);
	}

	void bfs(vector<int> &src, vector<int> &dst) {
		vector<int> d(n, -1); queue<int> q;
		for (auto &x : src) { d[x] = 0; q.push(x); }
		while (!q.empty()) {
			int f = q.front(); q.pop();
			node& cur = nodes[f];
			for (auto &x : cur.edges) {
				int dest = x.v;
				if (d[dest] == -1) {
					q.push(dest); d[dest] = d[f] + 1;
				}
			}
		}
		for (auto &x : dst)
			res[x] = d[x];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n; cin >> n; graph g(n); 
	v.resize(n); res.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i - v[i] >= 0) { g.add_edge(i - v[i], i); }
		if (i + v[i] < n) { g.add_edge(i + v[i], i); }
		(v[i] % 2 ? odd : even).push_back(i);
	}
	g.bfs(even, odd); g.bfs(odd, even);
	for (auto &x : res) { cout << x << ' '; }

	cout << endl; cin.ignore(2); return 0;
}