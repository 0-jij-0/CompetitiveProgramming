#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 1 << 30;

struct BipartiteGraph {
	vector<vector<int>> nodes; int n, m;
	vector<int> level, match;

	BipartiteGraph(int _n, int _m) : n(_n), m(_m),
		nodes(_n + _m + 1), level(_n + _m + 1), match(_n + _m + 1, 0) {}

	void addEdge(int u, int v) {
		nodes[u + 1].emplace_back(v + 1);
		nodes[v + 1].emplace_back(u + 1);
	}

	bool matchingBFS() {
		fill(level.begin(), level.end(), -1);
		queue<int> q; for (int i = 1; i <= n; i++)
			if (!match[i]) { level[i] = 0; q.push(i); }

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			if (!cur) { continue; }
			for (auto &e : nodes[cur]) {
				if (level[match[e]] == -1) {
					level[match[e]] = level[cur] + 1;
					q.push(match[e]);
				}
			}
		}
		return (level[0] != -1);
	}

	bool matchingDFS(int cur) {
		if (!cur) { return true; }
		if (cur) {
			for (auto &e : nodes[cur]) {
				if (level[match[e]] != level[cur] + 1) { continue; }
				if (!matchingDFS(match[e])) { continue; }
				match[e] = cur;	match[cur] = e;	return true;
			}
			level[cur] = INF; return false;
		}
		return true;
	}

	int hopcroftKarp() {
		int res = 0; while (matchingBFS())
			for (int i = 1; i <= n; i++)
				res += (match[i] == 0 && matchingDFS(i));
		return res;
	}

	void printMaxMatching() {
		cout << hopcroftKarp() << '\n';
		for (int i = 1; i <= n; i++) if (match[i])
			cout << i << " " << match[i] - n << '\n';
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}