#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> subSize;
vector<ll> pathSum, res;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) { subSize.resize(n); pathSum.resize(n); res.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	void init(int cur, int p) {
		for (edge& e : nodes[cur].edges) {
			if (e.v == p) { continue; }	init(e.v, cur);
			subSize[cur] += 1 + subSize[e.v];
			pathSum[cur] += pathSum[e.v] + 1 + subSize[e.v];
		}
	}

	void dfs(int cur, int p, ll pAns) {
		res[cur] = pathSum[cur] + pAns;
		for (edge& e : nodes[cur].edges) {
			if (e.v == p) { continue; }
			ll cAns = pathSum[cur] - pathSum[e.v] - 1 - subSize[e.v];
			cAns += pAns + n - 1 - subSize[e.v]; dfs(e.v, cur, cAns);
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	} g.init(0, -1); g.dfs(0, -1, 0);

	for (auto& x : res) cout << x << ' '; cout << '\n';

	cin.ignore(2); return 0;
}