#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> robots;

struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge &rhs) const { return w < rhs.w; }
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, int w) {
		edge e1(u, v, w), e2(v, u, w);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	long long find(int par, int cur, int i, int j) {
		if (i > j) { return 0ll; }
		long long res = 0ll;
		for (edge &e : nodes[cur].edges) {
			if (e.v == par) { continue; }
			auto tt = upper_bound(robots.begin() + i, robots.begin() + j + 1, e.w);
			if (tt == robots.begin() + j + 1) { continue; }
			int temp = tt - robots.begin();	res += find(cur, e.v, temp, j);
			j = temp - 1; if (i > j) { break; }
		}
		res += (long long)(cur + 1)*(j - i + 1);
		return res;
	}
};

int main() {
	int T; cin >> T;
	while (T--) {
		int n, q; cin >> n >> q; graph g(n);
		robots.clear(); robots.resize(q);
		for (int i = 0; i < n - 1; i++) {
			int u, v, w; cin >> u >> v >> w;
			u--; v--; g.add_edge(u, v, w);
		}
		for (auto &x : robots) { cin >> x; }
		sort(robots.begin(), robots.end());
		for (int i = 0; i < g.n; i++)
			sort(g.nodes[i].edges.rbegin(), g.nodes[i].edges.rend());
		cout << g.find(-1, 0, 0, q - 1) << endl;
	}
	cin.ignore(2); return 0;
}