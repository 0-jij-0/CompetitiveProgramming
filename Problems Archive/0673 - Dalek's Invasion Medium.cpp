#include <iostream>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge &rhs)const { return w < rhs.w; }
};

vector<edge> edges;

struct DSU {
	vector<int> parent;
	vector<vector<int>> children;
	vector<vector<pair<int, int>>> history;

	DSU(int n) {
		parent.resize(n); children.resize(n); history.resize(n);
		iota(parent.begin(), parent.end(), 0);
		for (int i = 0; i < n; i++) { children[i].push_back(i); }
	}

	int size(const int &u) { return (int)children[parent[u]].size(); }

	bool merge(int u, int v, const int &t, const int &w) {
		u = parent[u]; v = parent[v]; if (u == v) { return false; }
		if (size(u) > size(v)) { swap(u, v); }
		for (auto &x : children[u]) {
			history[x].push_back({ t, w });
			parent[x] = v; children[v].push_back(x);
		}
		children[u].clear(); return true;
	}

	int query(int u, int v) {
		if (history[u].size() > history[v].size()) { swap(u, v); }
		if (history[u].empty()) { return history[v].back().second; }

		int l = 0, r = history[u].size();
		while (l != r) {
			int mid = (l + r) >> 1;
			(history[u].rbegin() + mid)->first == (history[v].rbegin() + mid)->first ? l = mid + 1 : r = mid;
		}
		if (l == history[u].size()) { return (history[v].rbegin() + l)->second; }
		return max((history[v].rbegin() + l)->second, (history[u].rbegin() + l)->second);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; DSU dsu(n);
	for (int i = 0; i < m; i++) {
		int a, b, e; cin >> a >> b >> e;
		a--; b--; edges.push_back(edge(a, b, e));
	}
	vector<edge> v = edges;	sort(v.begin(), v.end());
	for (int k = 0; k < m; k++) { dsu.merge(v[k].u, v[k].v, k, v[k].w); }

	for(auto &e : edges){ 
		int x = dsu.query(e.u, e.v);
		if (x == e.w) { continue; }
		cout << x << endl;
	}
	cin.ignore(2); return 0;
}