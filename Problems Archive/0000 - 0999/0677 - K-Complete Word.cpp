#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
using namespace std;

string s;

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

	int bfs(int u, vector<bool> &visited, vector<int> &count) {
		queue<int> q; q.push(u); visited[u] = true;
		count[s[u] - 'a']++; int res = 1;
		while (!q.empty()) {
			int f = q.front(); q.pop();
			node& n = nodes[f];
			for (auto &x : n.edges) {
				int dest = x.v;
				if (visited[dest] == false) {
					res++; count[s[dest] - 'a']++;
					q.push(dest); visited[dest] = true;
				}
			}
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k >> s; graph g(n);
		int i = 0, j = n - 1;
		while (i < j) { g.add_edge(i, j); i++; j--; }
		for (int i = 0; i < k; i++) {
			int j = i, h = i + k;
			while (h < n) { g.add_edge(j, h); j = h; h += k; }
		}
		vector<bool> visited(n, false);
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (visited[i]) { continue; }
			vector<int> count(26, 0);
			int x = g.bfs(i, visited, count);
			res += x - *max_element(count.begin(), count.end());
		}
		cout << res << endl;
	}

	cin.ignore(2); return 0;
}