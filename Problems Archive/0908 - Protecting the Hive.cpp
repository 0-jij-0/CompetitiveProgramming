#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;
typedef pair<int, int> point;

struct edge {
	point u, v; edge() {}
	edge(point _u, point _v) :
		u(_u), v(_v) {}
	bool operator < (const edge &rhs) const {
		return pair<point, point>(u, v) < pair<point, point>(rhs.u, rhs.v);
	}
};

struct DSU {
	vector<int> parent; int n, m;
	vector<vector<set<edge>>> perim;

	void connect(int i, int j) {
		set<edge> &st = perim[i][j];
		st.insert(edge({ i - 1, j }, { i, j }));
		st.insert(edge({ i, j }, { i + 1, j }));
		st.insert(edge({ i, j - 1 }, { i ,j }));
		st.insert(edge({ i, j }, { i, j + 1 }));
		int x = (i % 2) ? 1 : -1;
		st.insert(edge({ i - 1, j + x }, { i, j }));
		st.insert(edge({ i, j }, { i + 1, j + x }));
	}

	DSU(int _n, int _m) : n(_n), m(_m) {
		parent.resize(_n * _m);
		iota(parent.begin(), parent.end(), 0);
		perim.resize(n, vector<set<edge>>(m));

		for(int i = 0; i < _n; i++)
			for (int j = 0; j < _m - (i % 2); j++)
				connect(i, j);
	}

	int find(const int u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(const int &u) { int x = find(u); return perim[x / m][x % m].size(); }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (size(u) < size(v)) { swap(u, v); }
		parent[v] = u;
		set<edge> &a = perim[u / m][u % m];
		set<edge> &b = perim[v / m][v % m];
		for (auto &x : b) {
			if (a.count(x)) { a.erase(x); }
			else { a.insert(x); }
		}
		b.clear(); return true;
	}
};

vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; DSU dsu(n, m);
	v.resize(n, vector<int>(m, 0));
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m - (i % 2); j++) {
			cin >> v[i][j]; if (!v[i][j]) { continue; }
			if (j != 0 && v[i][j - 1]) { dsu.merge(i * m + j, i * m + j - 1); }
			if (i != 0 && v[i - 1][j]) { dsu.merge(i * m + j, (i - 1) * m + j); }
			if (i % 2 && j != m - 1 && v[i - 1][j + 1]) { dsu.merge(i * m + j, (i - 1) * m + j + 1); }
			if (!(i % 2) && i != 0 && j != 0 && v[i - 1][j - 1]) { dsu.merge(i * m + j, (i - 1) * m + j - 1); }
		}

	int q; cin >> q;
	while (q--) {
		char c; int i, j; cin >> c >> i >> j; i--; j--;
		if (c == 'k') { cout << v[i][j] * dsu.size(i * m + j) << endl; continue; }
		if (v[i][j] == 1) { continue; } v[i][j] = 1;
		if (i != 0 && v[i - 1][j]) { dsu.merge(i * m + j, (i - 1) * m + j); }
		if (j != 0 && v[i][j - 1]) { dsu.merge(i * m + j, i * m + j - 1); }
		if (i != n - 1 && v[i + 1][j]) { dsu.merge(i * m + j, (i + 1) * m + j); }
		if (j != m - 1 && v[i][j + 1]) { dsu.merge(i * m + j, i * m + j + 1); }
		if (i % 2) {
			if (j != m - 1 && v[i - 1][j + 1]) { dsu.merge(i * m + j, (i - 1) * m + j + 1); }
			if (j != m - 1 && i != n - 1 && v[i + 1][j + 1]) { dsu.merge(i * m + j, (i + 1) * m + j + 1); }
		}
		else {
			if (j != 0 && i != 0 && v[i - 1][j - 1]) { dsu.merge(i * m + j, (i - 1) * m + j - 1); }
			if (j != 0 && i != n - 1 && v[i + 1][j - 1]) { dsu.merge(i * m + j, (i + 1) * m + j - 1); }
		}
	}
	cin.ignore(2); return 0;
}