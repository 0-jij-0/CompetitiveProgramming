#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
 
typedef long long ll;
int n, l, r;
ll res;
int leftB, rightB;
 
struct FT {
	int n;
	vector<ll> vals;
	FT() {}
	FT(const int n) :
		n(n), vals(vector<ll>(n + 1, 0)) {
	}
 
	//Adds x
	void update(int i, const ll x) {
		for (++i; i <= n; i += i & -i)
			vals[i] += x;
	}
	ll query(int i) const { // sum from 0 ... i
		ll sum = 0;
		for (++i; i; i -= i & -i)
			sum += vals[i];
		return sum;
	}
	ll query(int i, int j) const {		// sum from i ... j
		return query(j) - query(i - 1);
	}
};
 
FT occ;
 
struct edge {
	int u, v; ll w;
	edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};
 
struct node { vector<edge> edges; };
 
struct Tree {
	vector<node> nodes;
	vector<int> sz;
	int root, n;
 
	Tree(int _n, int _r = 0) : n(_n), root(_r) { nodes.resize(n); sz.resize(n, 1); }
 
	void add_edge(int u, int v, ll w = 1ll) {
		edge e1(u, v, w); edge e2(v, u, w);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}
 
	void centroidDecomposition() {
		vector<bool> dead(n, false);
		CDRec(0, dead);
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
		for (auto e : nodes[u].edges) {
			if (e.v == p || dead[e.v]) { continue; }
			if (sz[e.v] > subtreeN / 2) { return findCentroid(e.v, u, dead); }
		}
		return u;
	}
 
	//DOES NOT BUILD A TREE
	void CDRec(int start, vector<bool>& dead) {
		int c = getCentroid(start, dead);
		dead[c] = true;
 
		for (auto& e : nodes[c].edges) {
			if (dead[e.v]) { continue; }
			CDRec(e.v, dead);
		}
 
		dfs(c, -1, 0, dead, 1);
		res += occ.query(leftB, rightB);
		
		for (auto &e : nodes[c].edges) {
			if (dead[e.v]) { continue; }
			dfs(e.v, c, 1, dead, 0);
			addNeeded(e.v, c, 1, dead);
		}
		
		dead[c] = false;
	}
 
	void dfs(int u, int p, int level, vector<bool>& dead, bool dir) {
		if (level) occ.update(level, (dir ? 1 : -1));
		for (auto &e : nodes[u].edges) {
			if (e.v == p || dead[e.v]) { continue; }
			dfs(e.v, u, level + 1, dead, dir);
		}
	}
	void addNeeded(int u, int p, int level, vector<bool>& dead) {
		if (level > rightB) { return; }
 
		int low = 1, high = rightB - level;
		if (level < leftB) { low = leftB - level; }
 
		if (low <= high) { res += occ.query(low, high); }
 
		for (auto &e : nodes[u].edges) {
			if (e.v == p || dead[e.v]) { continue; }
			addNeeded(e.v, u, level + 1, dead);
		}
	}
};
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
 
	ifstream ifs("awesome.in");
	int T; ifs >> T;
 
	while (T--) {
		ifs >> n >> l >> r; res = 0;
		occ = FT(n); Tree t(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v; ifs >> u >> v; u--; v--;
			t.add_edge(u, v);
		}
 
		leftB = n - r - 1; rightB = n - l - 1;
 
		t.centroidDecomposition();
		cout << res << endl;
	}
}