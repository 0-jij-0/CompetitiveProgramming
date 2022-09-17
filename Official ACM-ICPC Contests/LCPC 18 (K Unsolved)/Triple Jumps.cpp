#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Graph {
	vector<vector<int>> nodes; int n;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	int bfs(int S) {
		queue<tuple<int, int, int>> q; q.push({ S, 0 , -1});
		unordered_map<int, int> vis[3]; vis[0][S] = -1;

		while (!q.empty()) {
			int cur, curD, par; tie(cur, curD, par) = q.front(); q.pop();

			int nextD = (curD + 1) % 3;
			for (auto& e : nodes[cur]) if (!curD || e != par) {
				if (!vis[nextD].count(e)) { vis[nextD][e] = cur; }
				else if (vis[nextD][e] == cur || vis[nextD][e] == -1) { continue; }
				else { vis[nextD][e] = -1; }

				q.push({ e, nextD, cur });
			}
		}

		return (int)vis[0].size();
	}
};

int main() {
	freopen("triple.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T; while (T--) {
		int N, M, S; cin >> N >> M >> S; Graph G(N);
		for (int i = 0; i < M; i++) {
			int u, v; cin >> u >> v;
			G.addEdge(--u, --v);
		}
		cout << G.bfs(--S) << '\n';
	}
}