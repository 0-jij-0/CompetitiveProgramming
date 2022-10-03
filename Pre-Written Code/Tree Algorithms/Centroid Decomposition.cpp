#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll res = 0; int k;

struct Edge {
	int u, v; ll w; Edge() {}
	Edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct Tree {
	int n; vector<vector<Edge>> nodes;
	vector<int> subSize, vis, depthCount;

	Tree(int _n) : n(_n), nodes(_n), subSize(_n, 1), vis(_n, 0), depthCount(_n, 0) {}

	void addEdge(int u, int v, ll w = 1ll) {
		nodes[u].emplace_back(u, v, w);
		nodes[v].emplace_back(v, u, w);
	}

	int subSizeDFS(int cur, int par = -1) {
		subSize[cur] = 1;
		for (Edge& e : nodes[cur])
			if (!vis[e.v] && e.v != par)
				subSize[cur] += subSizeDFS(e.v, cur);
		return subSize[cur];
	}

	int getCentroid(int threshold, int cur, int par = -1) {
		for (auto& e : nodes[cur])
			if (!vis[e.v] && e.v != par && subSize[e.v] >= threshold)
				return getCentroid(threshold, e.v, cur);
		return cur;
	}

	void centroidDecompositionRec(int root) {
		int centroid = getCentroid(subSizeDFS(root) >> 1, root);
		vis[centroid] = true;

		for (Edge& e : nodes[centroid]) if (!vis[e.v]) {
			CDQuery(e.v, centroid); CDUpdate(e.v, centroid);
		}

		CDReset();
		for (Edge& e : nodes[centroid])
			if (!vis[e.v]) centroidDecompositionRec(e.v);
	}

	void CDQuery(int cur, int par, int depth = 1) {
		if (depth > k) return;
		res += depthCount[k - depth];
		for (Edge& e : nodes[cur])
			if (!vis[e.v] && e.v != par)
				CDQuery(e.v, cur, depth + 1);
	}

	void CDUpdate(int cur, int par, int depth = 1) {
		if (depth > k) return;
		depthCount[depth]++;
		for (Edge& e : nodes[cur])
			if (!vis[e.v] && e.v != par)
				CDUpdate(e.v, cur, depth + 1);
	}

	void CDReset() {
		for (int i = 1; i < n && depthCount[i]; i++) depthCount[i] = 0;
	}

	ll centroidDecomposition() {
		depthCount[0] = 1;
		centroidDecompositionRec(0);
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}