#include <fstream>
#include <vector>
#include <numeric>
#include <stack>
#include <array>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

struct DSU {
	vector<int> rank, parent;

	DSU(int n) : rank(n, 1), parent(n) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int& u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
	bool operator < (const edge& rhs) const { return w < rhs.w; }
};

struct node { vector<int> edges; };

vector<edge> treeEdges;
vector<vector<array<ll, 2>>> sizes;

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(v);
		nodes[v].edges.emplace_back(u);
	}

	ll dfs(int c, const int &r, int u, int p = -1) {
		sizes[c][u][0] = 1;	sizes[c][u][1] = r;
		for (auto& e : nodes[u].edges)
			if (e != p) sizes[c][u][0] += dfs(c, r, e, u);
		return sizes[c][u][0];
	}
};

vector<graph> G; vector<ll> S;

void processEdge(int i, int n) {
	edge& e = treeEdges[i];
	ll L = min(sizes[e.w][e.u][0], sizes[e.w][e.v][0]);
	ll R = sizes[e.w][e.u][1] - L;
	ll cur = (L * R) % mod; S[i] = (e.w * cur) % mod;

	for (int c = e.w - 1; c > 0; c--) {
		L = min(sizes[c][e.u][0], sizes[c][e.v][0]);
		R = sizes[c][e.u][1] - L;
		ll newCur = (L * R) % mod;
		ll cont = (newCur - cur + mod) % mod;
		S[i] = (S[i] + c * cont) % mod; cur = newCur;
	}
}

int main() {
	ifstream cin("C.in.txt");
	ofstream cout("C.out.txt");
	
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; DSU dsu(n); S.resize(n - 1);
		treeEdges.clear(); sizes.clear(); G.clear();
		sizes.resize(21, vector<array<ll, 2>>(n, { -1, -1 }));
		G.resize(21, graph(n));
		
		for (int i = 1; i < n; i++) {
			int u, v, w; cin >> u >> v >> w;
			treeEdges.emplace_back(--u, --v, w);
		}

		sort(treeEdges.rbegin(), treeEdges.rend());
		ll ans = 0; for(int i = 0; i < n - 1; i++) {
			edge& e = treeEdges[i];
			ll L = dsu.size(e.u), R = dsu.size(e.v);
			ans = (ans + e.w * L * R) % mod;
			dsu.merge(e.u, e.v);
			for (int j = e.w; j >= 0; j--)			
				G[j].add_edge(e.u, e.v);
		}

		for (int c = 1; c < 21; c++) {
			for (int i = 0; i < n; i++)
				if (sizes[c][i][0] == -1)
					G[c].dfs(c, i, i);

			for (int i = 0; i < n; i++)
				sizes[c][i][1] = sizes[c][sizes[c][i][1]][0];
		}

		ll res = 1;
		for (int i = 0; i < n - 1; i++) {
			processEdge(i, n); 
			S[i] = (ans - S[i] + mod) % mod;
			res = (res * S[i]) % mod;
		}

		cout << "Case #" << t << ": " << res << '\n';
	}

	return 0;
}