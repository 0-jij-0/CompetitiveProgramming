#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, h;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };
vector<vector<int>> notSafe;

struct graph {
	vector<node> nodes;	int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v); edge e2(v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	void dfs(int u) {
		vector<bool> visited(n, 0);
		stack<int> S; S.push(u);
		visited[u] = visited[h] = 1;

		while (!S.empty()) {
			int cur = S.top(); S.pop();
			if (nodes[cur].edges.size() == 1) { notSafe[u].push_back(cur); }
			for (auto &e : nodes[cur].edges)
				if (!visited[e.v]) { visited[e.v] = 1; S.push(e.v); }
		}
	}
};

bool compare(const vector<int> &v1, const vector<int> &v2) {
	return ((int)v1.size()) < ((int)v2.size());
}

int main() {
	cin >> n >> h; graph g(n); notSafe.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; g.add_edge(u, v);
	}
	for (auto &e : g.nodes[h].edges) { g.dfs(e.v); }
	sort(notSafe.begin(), notSafe.end(), compare);

	vector<int> leaves; int leafSum = 0;
	for (auto &x : notSafe) {
		leafSum += x.size();
		for (auto &y : x) { leaves.push_back(y); }
	}
	int maxL = notSafe.back().size();

	vector<pair<int, int>> res;
	if (leafSum % 2 || maxL == leafSum) {
		res.push_back({ h, leaves.back() });
		leaves.pop_back(); leafSum--;
	}
	if (leafSum % 2) {
		res.push_back({ h, leaves.back() });
		leaves.pop_back(); leafSum--;
	}

	for (int i = 0; i + (leafSum / 2) < (int)leaves.size(); i++) {
		res.push_back({ leaves[i], leaves[i + leafSum / 2] });
	}

	cout << res.size() << endl;
	for (auto &x : res) { cout << x.first << ' ' << x.second << endl; }
}