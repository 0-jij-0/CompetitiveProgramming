#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)

// before calling set: N, LOGN, n, parent (vertices numbered 1..n)
// parent - array: parent[i] is the parent of i (parent[root] is irrelevant)
// works for a tree. if you have a forest, make it into a tree by adding a superroot
#define N 100007
#define LOGN 17
int n, parent[N], // input
pos[N], anc[LOGN + 1][N]; // temp

int getPos(int u) {
	if (pos[u] == -1) { pos[u] = getPos(parent[u]) + 1; }
	return pos[u];
} 
void init(int root) {
	FORI(i, n) anc[0][i] = parent[i];
	FORI(i, n) pos[i] = -1;
	pos[root] = 0;
	FORI(i, n) if (pos[i] == -1) getPos(i);
	FORI(i, LOGN) FORI(j, n) anc[i][j] = anc[i - 1][anc[i - 1][j]];
} 

int lca(int u, int v) {
	if (pos[u] < pos[v]) swap(u, v);
	int diff = pos[u] - pos[v];
	REPD(k, LOGN, 0) if ((1 << k) <= diff) {
		diff -= 1 << k;	u = anc[k][u];
	}
	// now they are equidistant from root
	if (u == v) return u;
	REPD(k, LOGN, 0) if (anc[k][u] != anc[k][v]) {
		u = anc[k][u];
		v = anc[k][v];
	}
	return parent[u];
}

vector<bool> r[2];
vector<int> sub_size, bpar;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<bool> visited;
	graph(int _n) : n(_n) { nodes.resize(n); visited.resize(n, false); }

	void add_edge(int u, int v) {
		edge e1(u, v), e2(v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	int dfs(int u, int p) {
		parent[u] = p; visited[u] = true; int res = 0;
		for (auto &x : nodes[u].edges) {
			int dest = x.v;
			if (visited[dest] == false)
				res += dfs(dest, u);
		}
		return sub_size[u] = 1 + res;
	}
	void bdfs(int u, int p) {
		bpar[u] = p; visited[u] = true;
		for (auto &x : nodes[u].edges) {
			int dest = x.v;
			if (visited[dest] == false)
				bdfs(dest, u);
		}
		return;
	}
};

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> n >> a >> b; graph g(n + 1);
		r[0].clear(); r[1].clear(); bpar.resize(n + 1);
		sub_size.clear(); sub_size.resize(n + 1);
		r[0].resize(n + 1, 0); r[1].resize(n + 1, 0);
		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v; g.add_edge(u, v);
		}
		g.dfs(a, -1); init(a); 
		g.visited.assign(n + 1, 0); g.bdfs(b, -1);
		int a1 = a; while (a1 != -1) { r[0][a1] = 1; a1 = parent[a1]; }
		int a2 = b; while (a2 != -1) { r[1][a2] = 1; a2 = parent[a2]; }
		long long res = 0;
		for (int i = 1; i <= n; i++) {
			int l = lca(b, i); if (l == b) { continue; }
			int p = bpar[l];
			res += sub_size[p];
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}