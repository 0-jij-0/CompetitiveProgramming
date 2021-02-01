#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct edge {
	int u, v, w; bool match = 0; edge() {}
	edge(int _u, int _v, int _w = 0) : u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; node() {} };

struct bipartiteGraph {
	vector<node> nodes; int n, m;
	vector<bool> Z, vis;
	vector<int> unMatched, match;

	bipartiteGraph(int _n, int _m) : n(_n), m(_m) {
		nodes.resize(n + m); Z.resize(n + m, 0);
		match.resize(n + m, -1); vis.resize(n + m, 0);
	}

	void add_edge(int u, int v) {
		nodes[u].edges.push_back(edge(u, v));
		nodes[v].edges.push_back(edge(v, u));
	}

	bool augment(int v) {
		if (v == -1) { return 1; }
		if (vis[v]) { return 0; }
		vis[v] = 1;
		for (auto &e : nodes[v].edges)
			if (augment(match[e.v])) {
				match[e.v] = v; match[v] = e.v;
				return 1;
			}
		return 0;
	}

	int maxMatching() {
		int w = 0;
		for (int x = 0; x < n; x++) {
			if (match[x] != -1) { continue; }
			for (auto &e : nodes[x].edges)
				if (match[e.v] == -1) {
					match[e.v] = x; match[x] = e.v;
					w++; break;
				}
		}
		for (int i = 0; i < n; i++) {
			if (match[i] != -1) { continue; }
			for (int j = 0; j < n; j++) { vis[j] = 0; }
			w += augment(i);
		}
		return w;
	}
};

struct graph {
	vector<node> nodes; int n;
	vector<vector<int>> D;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, int w = 0) {
		edge e1(u, v, w), e2(v, u, w);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	void allPairsShortestPath() {
		D.resize(n, vector<int>(n, (1 << 30) - 5));
		for (int i = 0; i < n; i++) { D[i][i] = 0; }

		for (auto &x : nodes)
			for (auto &y : x.edges)
				D[y.u][y.v] = y.w;

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (D[i][k] + D[k][j] < D[i][j])
						D[i][j] = D[i][k] + D[k][j];
	}
};

struct Spaceship { int x, a, f; Spaceship() {} };
struct Base { int x, d; Base() {} };
vector<Spaceship> S; vector<Base> B;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph G(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; G.add_edge(u, v, 1);
	}
	G.allPairsShortestPath();
	int s, b; ll k, h; cin >> s >> b >> k >> h;
	S.resize(s); B.resize(b);
	for (auto &x : S) { cin >> x.x >> x.a >> x.f; x.x--; }
	for (auto &x : B) { cin >> x.x >> x.d; x.x--; }

	bipartiteGraph g(s, b);
	for (int i = 0; i < s; i++)
		for (int j = 0; j < b; j++)
			if (S[i].f >= G.D[S[i].x][B[j].x] && S[i].a >= B[j].d)
				g.add_edge(i, s + j);

	ll match = g.maxMatching();
	ll res1 = k * match, res2 = h * s;
	cout << min(res1, res2) << '\n';	
	cin.ignore(2); return 0;
}