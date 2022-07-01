#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

ll res = 0; int k;

struct node { int cnt = 0; vector<int> edges; };

struct Tree {
	int n; vector<node> nodes;
	vector<int> subSize, vis;
	vector<int> depthCount;

	Tree(int _n) : n(_n), nodes(_n), subSize(_n, 1), vis(_n, 0), depthCount(_n, 0) {}

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(v);
		nodes[v].edges.emplace_back(u);
	}

	int subSizeDFS(int cur, int par = -1) {
		subSize[cur] = 1;
		for (auto& e : nodes[cur].edges)
			if (!vis[e] && e != par)
				subSize[cur] += subSizeDFS(e, cur);
		return subSize[cur];
	}

	int getCentroid(int threshold, int cur, int par = -1) {
		for (auto& e : nodes[cur].edges)
			if (!vis[e] && e != par && subSize[e] >= threshold)
				return getCentroid(threshold, e, cur);
		return cur;
	}

	void centroidDecompositionRec(int root) {
		int centroid = getCentroid((subSizeDFS(root) + 1) >> 1, root);
		vis[centroid] = true;

		for (auto& e : nodes[centroid].edges) if (!vis[e]) {
			CDQuery(e, centroid); CDUpdate(e, centroid);
		}

		CDReset();
		for (auto& e : nodes[centroid].edges)
			if (!vis[e]) centroidDecompositionRec(e);
	}

	void CDQuery(int cur, int par, int depth = 1) {
		if (depth > k) return;
		res += (ll)nodes[cur].cnt * (ll)depthCount[k - depth];
		for (auto& e : nodes[cur].edges)
			if (!vis[e] && e != par)
				CDQuery(e, cur, depth + 1);
	}

	void CDUpdate(int cur, int par, int depth = 1) {
		if (depth > k) return;
		depthCount[depth] += nodes[cur].cnt;
		for (auto& e : nodes[cur].edges)
			if (!vis[e] && e != par)
				CDUpdate(e, cur, depth + 1);
	}

	void CDReset() {
		for (int i = 1; i < n && depthCount[i]; i++) depthCount[i] = 0;
	}

	ll centroidDecomposition() {
		depthCount[0] = nodes[0].cnt;
		for(int i = 0; i < n; i++) if(!vis[i])
			centroidDecompositionRec(i);
		return res;
	}
};

struct graphEdge {
	int u, v; bool bridge = false;
	graphEdge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct graphNode { vector<int> edges; };

struct graph {
	vector<graphNode> nodes; int n;
	vector<graphEdge> edges;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(edges.size());
		edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(edges.size());
		edges.emplace_back(v, u);
	}

	//tin[u] = discovery time of u
	//low[u] = lowest discovery time of a reachable node
	void bridgeDFS(int cur, int p, vector<bool>& vis, vector<int>& low, vector<int>& tin, int& timer, set<pair<int, int>> &bridges) {
		vis[cur] = true; tin[cur] = low[cur] = timer++;
		for (auto& x : nodes[cur].edges) {
			graphEdge& e = edges[x];	if (e.v == p) { continue; }
			if (vis[e.v]) { low[cur] = min(low[cur], tin[e.v]); continue; }

			bridgeDFS(e.v, cur, vis, low, tin, timer, bridges);
			low[cur] = min(low[cur], low[e.v]);
			if (low[e.v] > tin[cur]) { e.bridge = true; bridges.insert({ e.u, e.v }); bridges.insert({ e.v, e.u }); }
		}
	}

	set<pair<int, int>> findBridges() {
		int timer = 0; vector<bool> vis(n, false);
		set<pair<int, int>> bridges;
		vector<int> low(n, -1), tin(n, -1);
		for (int i = 0; i < n; i++)	if (!vis[i])
			bridgeDFS(i, -1, vis, low, tin, timer, bridges);
		return move(bridges);
	}
};

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

int main() {
	freopen("troad.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m >> k; graph g(n);
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			g.add_edge(--u, --v);
		}
		set<pair<int, int>> bridges = g.findBridges(); 
		DSU dsu(n); for (auto& e : g.edges) 
			if (!bridges.count({e.u, e.v})) dsu.merge(e.u, e.v);

		Tree T(n); for (auto& e : g.edges)
			if (e.bridge) T.add_edge(dsu.find(e.u), dsu.find(e.v));

		for (int i = 0; i < n; i++) T.nodes[dsu.find(i)].cnt++;

		res = 0; T.centroidDecomposition();
		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}