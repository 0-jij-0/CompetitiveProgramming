#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

struct graph {
	vector<vector<int>> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	void bfs(int u, vector<int> coloring[2]) {
		queue<int> q; q.push(u);
		vector<int> d(n); d[u] = 1;

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			coloring[d[cur] & 1].push_back(cur);
			for (auto& e : nodes[cur]) {
				if (d[e]) { continue; }
				q.push(e); d[e] = d[cur] + 1;
			}
		}
	}
};

int lastBit(int x) {
	int res = -1, i = 0, cur = 1;
	while (cur <= x) {
		if (x & cur) { res = i; }
		i++; cur <<= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; graph g(n);
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			u--; v--; g.add_edge(u, v);
		}

		vector<vector<int>> v(20);
		for (int i = 1; i <= n; i++) v[lastBit(i)].push_back(i);
		vector<int> coloring[2]; g.bfs(0, coloring);
		
		if (coloring[0].size() > coloring[1].size())
			swap(coloring[0], coloring[1]);

		int w = coloring[0].size(); vector<int> res(n); int j = 0;
		for (int i = 0; i < 20; i++) if (w & (1 << i)) while (!v[i].empty()) {
			res[coloring[0][j++]] = v[i].back(); v[i].pop_back();
		}

		j = 0; for (int i = 0; i < 20; i++) while (!v[i].empty()) {
			res[coloring[1][j++]] = v[i].back(); v[i].pop_back();
		}

		for (auto& x : res) cout << x << ' '; cout << '\n';
	}

	cin.ignore(2); return 0;
}