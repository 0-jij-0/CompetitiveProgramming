#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
using namespace std;

struct DSU {
	vector<int> rank, parent;
	DSU(int n) {
		rank.resize(n, 1); parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}
	int find(const int u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(const int u) { return rank[find(u)]; }
	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

vector<edge> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	DSU dsu(n + 1); v.resize(m);
	for (auto &x : v) {
		cin >> x.u >> x.v;
		x.u--; x.v--;
	}
	for (auto &x : v) { dsu.merge(x.u, x.v); }
	int cur = dsu.find(0), cur_rank = dsu.size(0), res = 0;
	for (int i = 0; i < n; i++) {
		if (dsu.find(i) == cur) {
			cur_rank--;
			if (!cur_rank) {
				cur = dsu.find(i + 1);
				cur_rank = dsu.size(i + 1);
			}
		}
		else {
			cur_rank += dsu.size(i) - 1;
			res++; dsu.merge(cur, i);
			cur = dsu.find(i);
		}
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}