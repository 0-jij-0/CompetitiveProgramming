#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll res = 0; int L, R;

struct FT {
	int n; vector<ll> vals;
	FT(int n) : n(n), vals(n + 1, 0ll) {}

	void update(int i, ll x) {
		for (++i; i <= n; i += i & -i) { vals[i] += x; }
	}

	ll query(int i) const { // sum from 0 ... i
		ll sum = 0;
		for (++i; i; i -= i & -i) { sum += vals[i]; }
		return sum;
	}
	ll query(int i, int j) const { return query(j) - query(i - 1); }
};

struct Tree {
	int n; vector<vector<int>> nodes;
	vector<int> subSize, vis;
	FT depthCount;

	Tree(int _n) : n(_n), nodes(_n), subSize(_n, 1), vis(_n, 0), depthCount(_n) {}

	void add_edge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	int subSizeDFS(int cur, int par = -1) {
		subSize[cur] = 1;
		for (auto& e : nodes[cur]) if (!vis[e] && e != par)
			subSize[cur] += subSizeDFS(e, cur);
		return subSize[cur];
	}

	int getCentroid(int threshold, int cur, int par = -1) {
		for (auto& e : nodes[cur])
			if (!vis[e] && e != par && subSize[e] >= threshold)
				return getCentroid(threshold, e, cur);
		return cur;
	}

	void CDQuery(int cur, int par, int depth = 1) {
		if (depth > R) return;
		res += depthCount.query(max(0, L - depth), R - depth);
		for (auto& e : nodes[cur]) if (!vis[e] && e != par)
			CDQuery(e, cur, depth + 1);
	}

	void CDUpdate(int cur, int par, int depth = 1) {
		if (depth > R) return;
		depthCount.update(depth, 1);
		for (auto& e : nodes[cur]) if (!vis[e] && e != par)
			CDUpdate(e, cur, depth + 1);
	}

	void centroidDecompositionRec(int cur) {
		int centroid = getCentroid(subSizeDFS(cur) >> 1, cur);
		vis[centroid] = true;

		for (auto& e : nodes[centroid]) if (!vis[e]) {
			CDQuery(e, centroid); CDUpdate(e, centroid);
		}

		for (int i = 1; i < n; i++) {
			ll x = depthCount.query(i, i);
			if (x == 0) { break; }
			depthCount.update(i, -x);
		}
		for (auto& e : nodes[centroid])
			if (!vis[e]) centroidDecompositionRec(e);
	}

	ll centroidDecomposition() {
		depthCount.update(0, 1);
		centroidDecompositionRec(0);
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n >> L >> R; Tree T(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		T.add_edge(--u, --v);
	}

	cout << T.centroidDecomposition() << '\n';
}