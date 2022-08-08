#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct graph {
	vector<vector<int>> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

    bool bridgeDFS(int cur, int par, vector<int>& depth, vector<int>& dp, vector<pair<int, int>> &res) {
        dp[cur] = 0;
        for (auto &e : nodes[cur]) if(e != par) {
            if (depth[e] == -1) {
                depth[e] = depth[cur] + 1; res.emplace_back(cur, e);
                if (!bridgeDFS(e, cur, depth, dp, res)) return false;
                dp[cur] += dp[e];
            }
            else if (depth[e] > depth[cur]) { dp[cur]--; }
            else { dp[cur]++; res.emplace_back(cur, e); }
        }

        return dp[cur] || !depth[cur];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m; graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g.add_edge(--u, --v);
    }

    vector<pair<int, int>> res;
    vector<int> dp(n, 0), depth(n, -1); depth[0] = 0;
    bool ok = g.bridgeDFS(0, -1, depth, dp, res);
    ok = ok && (find(depth.begin(), depth.end(), -1) == depth.end());

    if (!ok) { cout << "IMPOSSIBLE\n"; return 0; }
    for (auto& x : res) cout << x.first + 1 << ' ' << x.second + 1 << '\n';
}