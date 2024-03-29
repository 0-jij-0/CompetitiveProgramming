#include <bits/stdc++.h>
using namespace std;

struct graph {
	int n;
	vector<vector<int>> dfsEdgesIN, edgesOUT, sdomBucket;
	vector<int> labelToDfs, dfsToLabel, dfsParent;
	vector<int> sdom, idom, dsu, dsuMinSdom;

private:

	int dsuFind(int u, int d = 0) {
		if (u == dsu[u]) return d ? -1 : u;
		int v = dsuFind(dsu[u], d + 1);
		if (v < 0) return u;

		if (sdom[dsuMinSdom[dsu[u]]] < sdom[dsuMinSdom[u]])
			dsuMinSdom[u] = dsuMinSdom[dsu[u]];

		dsu[u] = v; return d ? v : dsuMinSdom[u];
	}

	void dsuMerge(int u, int v) {
		dsu[v] = u;
	}

	void initializationDFS(int cur, int& T) {
		dsu[T] = dsuMinSdom[T] = sdom[T] = T;
		labelToDfs[cur] = T; dfsToLabel[T++] = cur;

		for (auto& e : edgesOUT[cur]) {
			if (labelToDfs[e] == -1) {
				initializationDFS(e, T);
				dfsParent[labelToDfs[e]] = labelToDfs[cur];
			}
			dfsEdgesIN[labelToDfs[e]].emplace_back(labelToDfs[cur]);
		}
	}

	void computeDominatorTree() {
		for (int i = n - 1; i >= 0; i--) {
			for (auto& e : dfsEdgesIN[i])
				sdom[i] = min(sdom[i], sdom[dsuFind(e)]);

			if (i) sdomBucket[sdom[i]].push_back(i);

			for (auto& w : sdomBucket[i]) {
				int v = dsuFind(w);
				idom[w] = (sdom[v] == sdom[w]) ? sdom[w] : v;
			}

			if (i) dsuMerge(dfsParent[i], i);
		}

		for (int i = 1; i < n; i++)
			if (idom[i] != sdom[i]) 
				idom[i] = idom[idom[i]];
	}

public:

	graph(int _n) : n(_n),
		edgesOUT(_n), dfsParent(_n), dfsToLabel(_n),
		sdom(_n), idom(_n), dsu(_n), dsuMinSdom(_n) {}

	void addEdge(int u, int v) {
		edgesOUT[u].emplace_back(v);
	}

	void computeDominatorTree(int src) {
		dfsEdgesIN.clear(); dfsEdgesIN.resize(n);
		sdomBucket.clear(); sdomBucket.resize(n);
		labelToDfs.clear(); labelToDfs.resize(n, -1);

		int t = 0;
		initializationDFS(src, t);
		computeDominatorTree();
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g.addEdge(--u, --v);
	}

	g.computeDominatorTree(0);
	vector<int> res(1, n - 1); int cur = n - 1;
	while (cur) {
		cur = g.dfsToLabel[g.idom[g.labelToDfs[cur]]];
		res.push_back(cur);
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (auto& x : res) cout << x + 1 << ' '; cout << '\n';
}