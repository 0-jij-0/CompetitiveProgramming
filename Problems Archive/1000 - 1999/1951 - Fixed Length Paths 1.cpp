#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll res = 0; int k;

struct Tree {
	int n; vector<vector<int>> nodes;
	vector<int> subSize, vis, depthCount;

	Tree(int _n) : n(_n), nodes(_n), subSize(_n, 1), vis(_n, 0), depthCount(_n, 0) {}

	void add_edge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	int subSizeDFS(int cur, int par = -1) {
		subSize[cur] = 1;
		for (auto &e : nodes[cur]) if (!vis[e] && e != par)
			subSize[cur] += subSizeDFS(e, cur);
		return subSize[cur];
	}

	int getCentroid(int threshold, int cur, int par = -1) {
		for (auto &e : nodes[cur])
			if (!vis[e] && e != par && subSize[e] >= threshold)
				return getCentroid(threshold, e, cur);
		return cur;
	}

	void CDQuery(int cur, int par, int depth = 1) {
		if (depth > k) return;
		res += depthCount[k - depth];
		for (auto& e : nodes[cur]) if (!vis[e] && e != par)
			CDQuery(e, cur, depth + 1);
	}

	void CDUpdate(int cur, int par, int depth = 1) {
		if (depth > k) return;
		depthCount[depth]++;
		for (auto& e : nodes[cur]) if (!vis[e] && e != par)
			CDUpdate(e, cur, depth + 1);
	}

	void centroidDecompositionRec(int cur) {
		int centroid = getCentroid(subSizeDFS(cur) >> 1, cur);
		vis[centroid] = true;

		for (auto &e : nodes[centroid]) if (!vis[e]) {
			CDQuery(e, centroid); CDUpdate(e, centroid);
		}

		for (int i = 1; i < n && depthCount[i]; i++) depthCount[i] = 0;
		for (auto &e : nodes[centroid]) 
			if (!vis[e]) centroidDecompositionRec(e);
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

	int n; cin >> n >> k; Tree T(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		T.add_edge(--u, --v);
	}

	cout << T.centroidDecomposition() << '\n';
	cin.ignore(2); return 0;
}