#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

vector<string> v;

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
		edge e1(u, v);
		nodes[u].edges.push_back(e1);
	}

	int bfs(int m) {
		queue<int> q; vector<bool> visited(n*n, false);
		for (int i = 0; i < m - 1; i++)
			if (v[i][m - 1] == '1') {
				int idx = i * m + m - 1;
				q.push(idx); visited[idx] = true;
			}
		for (int j = 0; j < m; j++)
			if (v[m - 1][j] == '1') {
				int idx = (m - 1) * m + j;
				q.push(idx); visited[idx] = true;
			}

		while (!q.empty()) {
			int f = q.front(); q.pop();
			for (auto &e : nodes[f].edges) {
				if (visited[e.v] == false && v[e.v/m][e.v%m] == '1') {
					q.push(e.v); visited[e.v] = true;
				}
			}
		}
		return count(visited.begin(), visited.end(), true);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n); int res = 0;
		for (auto &x : v) { cin >> x; res += count(x.begin(), x.end(), '1'); }
		graph g(n*n);
		for(int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (i != 0) { g.add_edge(i*n + j, (i - 1)*n + j); }
				if (j != 0) { g.add_edge(i*n + j, i*n + j - 1); }
			}
		cout << (g.bfs(n) == res ? "YES" : "NO") << endl;
	}

	cin.ignore(2); return 0;
}