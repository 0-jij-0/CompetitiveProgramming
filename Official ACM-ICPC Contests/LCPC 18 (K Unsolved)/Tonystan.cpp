#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <string>
using namespace std;

struct Graph {
	vector<vector<int>> nodes; int n;
	vector<set<int>> bannedDays;
	Graph(int _n) : n(_n), nodes(_n), bannedDays(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	void banDays(int u, vector<int> &day) {
		bannedDays[u].insert(day.begin(), day.end());
		for(int &e : nodes[u]) bannedDays[e].insert(day.begin(), day.end());
	}

	int bfs(int S, int D, int K) {
		queue<pair<int, int>> q; q.push({ S, 0 });
		vector<vector<int>> vis(n, vector<int>(K, 0));

		vis[S][0] = true; while (!q.empty()) {
			int cur, curDay; tie(cur, curDay) = q.front(); q.pop();
			if (cur == D) { return curDay; }

			int nextDay = (curDay + 1) % K;
			for (auto& e : nodes[cur]) if(!vis[e][nextDay]) {
				if (bannedDays[e].count(nextDay)) { continue; }
				vis[e][nextDay] = true; q.push({ e, curDay + 1 });
			}
		}

		return 0;
	}
};

int main() {
	freopen("tony.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T; while (T--) {
		int N, M, K; cin >> N >> M >> K; Graph G(N);
		for (int i = 0; i < M; i++) {
			int u, v; cin >> u >> v;
			G.addEdge(--u, --v);
		}

		vector<vector<int>> daysToBan(N);
		for (int i = 0; i < K; i++) {
			int p; cin >> p; daysToBan[--p].push_back(i);
		}

		for (int i = 0; i < N; i++) G.banDays(i, daysToBan[i]);

		int S, D; cin >> S >> D;
		int res = G.bfs(--S, --D, K);
		cout << (res ? to_string(res) : "WASTED") << '\n';
	}
}