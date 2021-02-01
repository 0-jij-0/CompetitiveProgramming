#include <iostream>
#include <numeric>
#include <set>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct DSU {
	vector<int> rank;
	vector<int> parent;

	DSU() {}
	DSU(int n) {
		rank.resize(n, 1); parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int u) {
		if (parent[u] == u) { return u; }
		parent[u] = find(parent[u]);
		return parent[u];
	}

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v]; parent[v] = u;
		return true;
	}

	int size(int u) { return rank[find(u)]; }
};

vector<map<int, int>> adj;
vector<set<int>> dadj;
DSU dsu;

set<int> merge(set<int> &s1, set<int> &s2) {
	if (s1.size() > s2.size()) { swap(s1, s2); }
	s2.insert(s1.begin(), s1.end());
	s1.clear(); return move(s2);
}

void merge(int u, int v) {
	u = dsu.find(u); v = dsu.find(v);
	if (u == v) { return; }
	set<int> s = merge(dadj[u], dadj[v]);
	dsu.merge(u, v);
	dadj[dsu.find(u)] = move(s);
}

void addEdge(const int x, const int y, const int z) {
	if (dsu.find(x) != dsu.find(y))
		dadj[dsu.find(x)].insert(y);

	if (!adj[x].count(z)) {	adj[x][z] = y; }
	else { merge(adj[x][z], y); }
}
void addEdges() {
	int x, y, z; cin >> x >> y >> z;
	addEdge(x, y, z); addEdge(y, x, z);
}


int main() {
	int n, m, c, q;	cin >> n >> m >> c >> q;
	adj.resize(n + 1); dadj.resize(n + 1); dsu = DSU(n + 1);

	for (int i = 0; i < m; ++i) { addEdges(); }

	for (int i = 0; i < q; i++) {
		char t; cin >> t;
		if (t == '+') { addEdges(); }
		else {
			int x, y; cin >> x >> y;
			x = dsu.find(x);
			bool b = (x == dsu.find(y)) || (dadj[x].count(y));
			string res = (b) ? "Yes" : "No";
			cout << res << endl;
		}
	}
	cin.ignore(2); return 0;
}