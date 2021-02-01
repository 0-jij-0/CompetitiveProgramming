#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> height, par, subSize;

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

	int dfs(int u, int p) {
		int res = 1;
		for (auto &x : nodes[u].edges) {
			if (x.v == p) { continue; }
			height[x.v] = 1 + height[u];
			res += dfs(x.v, u);
		}
		return subSize[u] = res;
	}
};

vector<int> nodes;

bool compare(int i, int j) {
	return height[i] - subSize[i] < height[j] - subSize[j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k; cin >> n >> k; graph g(n);
	subSize.resize(n); height.resize(n); nodes.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}

	height[0] = 0; g.dfs(0, -1); ll res = 0;
	iota(nodes.begin(), nodes.end(), 0);
	sort(nodes.rbegin(), nodes.rend(), compare);
	for (int i = 0; i < k; i++)
		res += height[nodes[i]] - subSize[nodes[i]] + 1;

	cout << res << endl;
	cin.ignore(2); return 0;
}