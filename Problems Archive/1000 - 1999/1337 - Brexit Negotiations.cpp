#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(v);
	}
};

vector<int> v, in, f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	v.resize(n); in.resize(n), f.resize(n, 0);
	for (int i = 0; i < n; i++) {
		int m; cin >> v[i] >> m;
		while (m--) { int x; cin >> x; in[--x]++; g.add_edge(i, x); }
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < n; i++) if (!in[i]) { pq.push({ v[i], i }); }
	int res = 0, add = n - 1; while (!pq.empty()) {
		int t = pq.top().first, cur = pq.top().second; pq.pop();
		res = max(res, t + add); add--;
		for (int &e : g.nodes[cur].edges)
			if (++f[e] == in[e]) { pq.push({ v[e], e }); }
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}