#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct graph {
	vector<vector<int>> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}
};

struct RMQ {
	vector<vector<int>> rmq;
	vector<int> v, logb2; RMQ() {}
	RMQ(vector<int>& _v) : v(_v) { //O(nlogn) time and space
		int n = (int)v.size(); logb2.resize(n + 1, 0);
		rmq.resize(1, vector<int>(n));
		iota(rmq[0].begin(), rmq[0].end(), 0);

		for (int i = 0; (1 << i) <= n; i++) { logb2[1 << i] = i; } //Precomputing Logs
		for (int i = 1; i <= n; i++) { logb2[i] = max(logb2[i], logb2[i - 1]); }
		rmq.resize(logb2.back() + 1);

		for (int t = 1; t < (int)rmq.size(); t++) {
			rmq[t].resize(n - (1 << t) + 1);
			for (int i = 0; i <= n - (1 << t); i++) {
				int x = v[rmq[t - 1][i]], y = v[rmq[t - 1][i + (1 << (t - 1))]];
				rmq[t][i] = x < y ? rmq[t - 1][i] : rmq[t - 1][i + (1 << (t - 1))];
			}
		}
	}

	int query(int i, int j) { //O(1)
		if (i > j) { swap(i, j); }
		int k = logb2[j - i + 1];
		int x = v[rmq[k][i]], y = v[rmq[k][j - (1 << k) + 1]];
		return x < y ? rmq[k][i] : rmq[k][j - (1 << k) + 1];
	}
};

struct ETT { //Euler Tour Technique
	vector<int> tree, start, finish, d, v; ETT() {}
	ETT(graph& g, int root) : d(g.n, 0), start(g.n), finish(g.n) {
		int t = 0; init(g, root, -1, t);
	}
	void init(graph& g, int cur, int p, int& t) {
		tree.push_back(cur); start[cur] = t++;
		v.push_back(d[cur]);
		for (auto& e : g.nodes[cur]) {
			if (e == p) { continue; }
			d[e] = 1 + d[cur];
			init(g, e, cur, t);
			tree.push_back(cur); t++;
			v.push_back(d[cur]);
		}
		finish[cur] = t - 1;
	}
};

struct LCA {
	ETT ett; RMQ rmq; LCA() {}
	LCA(graph& g, int root) : ett(g, root), rmq(ett.v) {}
	int find(int i, int j) { return ett.tree[rmq.query(ett.start[i], ett.start[j])]; }
	int dist(int i, int j) { return ett.d[i] + ett.d[j] - 2 * ett.d[find(i, j)]; }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g.add_edge(--u, --v);
	}

	LCA lca(g, 0);

	auto comp = [&](const int& i, const int& j) {
		return lca.rmq.v[lca.ett.start[i]] < lca.rmq.v[lca.ett.start[j]];
	};

	auto isAncestor = [&](int par, int cur) {
		return lca.find(cur, par) == par;
	};

	int q; cin >> q; while (q--) {
		int k; cin >> k; vector<int> p(k);
		for (auto& x : p) { cin >> x; --x; }
		sort(p.rbegin(), p.rend(), comp);

		bool ok = true; int a = p[0], i = 1;
		while (i != k && isAncestor(p[i], a)) { i++; }
		if (i == k) { cout << "YES\n"; continue; }

		int b = p[i]; for (; i < k; i++) {
			if (isAncestor(p[i], a) && isAncestor(p[i], b)) {
				ok = lca.find(a, b) == p[i++]; break;
			}
			if (isAncestor(p[i], a)) { continue; }
			if (b == -1) { b = p[i]; continue; }
			if (isAncestor(p[i], b)) { continue; }
			ok = false; break;
		}

		cout << (ok && i == k ? "YES" : "NO") << '\n';
	}
}