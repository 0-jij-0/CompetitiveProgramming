#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 1 << 30;

/*struct edge {
	int u, v; bool match = 0; edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};*/

struct node { vector<int> edges; };

struct bipartiteGraph {
	vector<node> nodes; int n, m;
	vector<int> level, match;

	bipartiteGraph(int _n, int _m) : n(_n), m(_m),
		nodes(_n + _m + 1), level(_n + _m + 1), match(_n + _m + 1, 0) {}

	void add_edge(int u, int v) {
		nodes[u + 1].edges.emplace_back(v + 1);
		nodes[v + 1].edges.emplace_back(u + 1);
	}

	bool matchingBFS() {
		fill(level.begin(), level.end(), -1);
		queue<int> q; for (int i = 1; i <= n; i++)
			if (!match[i]) { level[i] = 0; q.push(i); }

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			if (!cur) { continue; }
			for (auto &v : nodes[cur].edges) {
				if (level[match[v]] == -1) {
					level[match[v]] = level[cur] + 1;
					q.push(match[v]);
				}
			}
		}
		return (level[0] != -1);
	}

	bool matchingDFS(int cur) {
		if (!cur) { return true; }
		if (cur) {
			for (auto &v : nodes[cur].edges) {
				if (level[match[v]] != level[cur] + 1) { continue; }
				if (!matchingDFS(match[v])) { continue; }
				match[v] = cur;	match[cur] = v;	return true;
			}
			level[cur] = INF; return false;
		}
		return true;
	}

	int hopcroft_karp() {
		int res = 0; while (matchingBFS())
			for (int i = 1; i <= n; i++)
				res += (match[i] == 0 && matchingDFS(i));
		return res;
	}

	void printMaxMatching() {
		cout << hopcroft_karp() << '\n';
		for (int i = 1; i <= n; i++) if (match[i])
			cout << i << " " << match[i] - n << '\n';
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k; cin >> n >> m >> k; bipartiteGraph g(n, m);
	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		a--; b--; g.add_edge(a, n + b);
	}
	g.printMaxMatching(); cin.ignore(2); return 0;
}