#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;

const ll INF = 1e17;
int k; ll res;
vector<ll> occ;
struct edge {
	int u, v; ll w;
	edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct tree {
	vector<node> nodes;
	vector<int> sz;
	int root, n;

	tree(int _n, int _r = 0) : n(_n), root(_r) { nodes.resize(n); sz.resize(n, 1); }

	void add_edge(int u, int v, ll w = 1ll) {
		edge e1(u, v, w); edge e2(v, u, w);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	void centroidDecomposition() {
		vector<bool> dead(n, false);
		CDRec(0, dead);
	}
	void CDRec(int start, vector<bool>& dead) {
		int c = getCentroid(start, dead);
		dead[c] = true;
		for (auto& e : nodes[c].edges) {
			if (dead[e.v]) { continue; }
			CDRec(e.v, dead);
		}

		dfs(c, -1, 0, dead, 1);
		res += occ[k]; occ[0]--;

		ll bef = res;
		for (auto &e : nodes[c].edges) {
			if (dead[e.v]) { continue; }
			dfs(e.v, c, 1, dead, 0);
			add(e.v, c, 1, dead);
		}
		occ[0]++;
		dead[c] = false;
	}

	void dfs(int u, int p, int dist, vector<bool>& dead, bool dir) {
		if (dist > k) { return; }
		occ[dist] += (dir ? 1 : -1);

		for (auto &e : nodes[u].edges) {
			if (e.v == p || dead[e.v]) { continue; }
			dfs(e.v, u, dist + 1, dead, dir);
		}
	}

	void add(int u, int p, int dist, vector<bool>&dead) {
		if (dist >= k) { return; }
		res += occ[k - dist];

		for (auto &e : nodes[u].edges) {
			if (e.v == p || dead[e.v]) { continue; }
			add(e.v, u, dist + 1, dead);
		}
	}

private:
	int subtreeN;
	int getCentroid(int root, vector<bool>& dead) {
		getSize(root, -1, dead);
		subtreeN = sz[root];
		return findCentroid(root, -1, dead);
	}
	void getSize(int u, int p, vector<bool>& dead) {
		sz[u] = 1;
		for (auto& e : nodes[u].edges) {
			if (e.v == p || dead[e.v]) { continue; }
			getSize(e.v, u, dead);
			sz[u] += sz[e.v];
		}
	}
	int findCentroid(int u, int p, vector<bool>& dead) {
		for (auto& e : nodes[u].edges) {
			if (e.v == p || dead[e.v]) { continue; }
			if (sz[e.v] > subtreeN / 2) { return findCentroid(e.v, u, dead); }
		}
		return u;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n >> k; res = 0;
	tree t(n); occ.resize(k + 1, 0);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; u--; v--;
		t.add_edge(u, v);
	}

	t.centroidDecomposition();
	cout << res << endl;
}