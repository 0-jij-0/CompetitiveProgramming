#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll dp[100000][2];

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(v);
		nodes[v].edges.emplace_back(u);
	}
	
	ll indepSet(int cur, bool b, int p = -1) {
		if (dp[cur][b] != -1) { return dp[cur][b]; }
		ll res = 1; for (auto &e : nodes[cur].edges) if(e != p)
			res = (res * (indepSet(e, 0, cur) + (b ? 0 : indepSet(e, 1, cur)))) % mod;
		return dp[cur][b] = res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	fill(dp[0], dp[0] + 200000, -1);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	cout << (g.indepSet(0, 0) + g.indepSet(0, 1)) % mod << '\n';
	cin.ignore(2); return 0;
}