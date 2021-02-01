#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct edge {
	int u, v; ll w; edge() {}
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

	Tree buildCDT() {
		Tree CDT(n);
		vector<bool> dead(n, false);
		CDUtil(0, -1, dead, CDT);
		return move(CDT);
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
		//ADD REQUIRED CODE
		//...
		dead[c] = false;
	}

	//BUILD THE CENTROID TREE
	void CDUtil(int start, int parent, vector<bool>& dead, Tree &CDT) {
		int c = getCentroid(start, dead);
		if (parent != -1) { CDT.add_edge(c, parent); }
		else { CDT.root = c; }

		dead[c] = true;
		for (auto& e : nodes[c].edges) {
			if (dead[e.v]) { continue; }
			CDUtil(e.v, c, dead, CDT);
		}
		dead[c] = false;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin.ignore(2); return 0;
}