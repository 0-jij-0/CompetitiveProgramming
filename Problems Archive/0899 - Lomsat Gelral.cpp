#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> ans;
vector<int> c;

struct DSU {
	vector<int> parent;
	vector<map<int, int>> colCount;

	DSU(int n) {
		parent.resize(n); colCount.resize(n);
		iota(parent.begin(), parent.end(), 0);
		for (int i = 0; i < n; i++) { colCount[i][c[i]]++; }
	}

	int find(const int u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }

	pair<ll, ll> merge(int u, int v) {
		int oldU = u, oldV = v;
		u = find(u); v = find(v);
		if (u == v) { return { -1, -1 }; }
		if (colCount[u].size() < colCount[v].size()) { swap(u, v); swap(oldU, oldV); }
		parent[v] = u; pair<ll, ll> res = ans[oldU];
		for(auto &x : colCount[v]) {
			colCount[u][x.first] += x.second;
			if (colCount[u][x.first] == res.first) { res.second += x.first; continue; }
			if (colCount[u][x.first] > res.first) { res = { colCount[u][x.first], x.first }; }
		}
		return res;
	}
};

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

	void dfs(int u, int p, DSU &dsu) {
		ans[u] = { 1, c[u] };
		for (edge &e : nodes[u].edges) {
			if (e.v == p) { continue; }
			dfs(e.v, u, dsu); 
			ans[u] = dsu.merge(u, e.v);
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	ans.resize(n); c.resize(n);
	for (auto &x : c) { cin >> x; }
	graph g(n); DSU dsu(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	g.dfs(0, -1, dsu);
	for (auto &x : ans) { cout << x.second << ' '; }
	cout << endl; cin.ignore(2); return 0;
}