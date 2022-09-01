#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

struct Tree {
	vector<vector<int>> nodes; int n;
	vector<ll> subSize;
	Tree(int _n) : n(_n), nodes(_n), subSize(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	ll DFS(int cur, vector<int>& par, vector<int>& depth) {
		subSize[cur] = 1;
		for(auto &e : nodes[cur]) if (par[e] == -1) {
			par[e] = cur; depth[e] = 1 + depth[cur];
			subSize[cur] += DFS(e, par, depth);
		}
		return subSize[cur];
	}
};

struct LCA {
	vector<int> depth; int n, m;
	vector<vector<int>> anc;

	LCA(Tree& T, int root) : n(T.n), depth(T.n) {
		m = (int)ceil(log2(T.n + 0.0)) + 1;
		anc.resize(m + 1, vector<int>(n, -1));

		depth[root] = 0; anc[0][root] = root;
		T.DFS(root, anc[0], depth);
		for (int i = 1; i <= m; i++)
			for (int j = 0; j < n; j++)
				anc[i][j] = anc[i - 1][anc[i - 1][j]];
	}

	pair<int, int> find(int u, int v) {
		if (depth[u] < depth[v]) { swap(u, v); }
		int diff = depth[u] - depth[v];

		if (diff) {
			--diff; for (int i = m; i >= 0; i--)
				if ((1 << i) <= diff) {
					u = anc[i][u]; diff -= 1 << i;
				}
			if (anc[0][u] == v) { return { anc[0][u], u }; }
			else { u = anc[0][u]; }
		}

		for (int i = m; i >= 0; i--)
			if (anc[i][u] != anc[i][v]) {
				u = anc[i][u]; v = anc[i][v];
			}
		return { anc[0][u], u };
	}
};

ll choose2(ll N) { return (N * (N - 1)) >> 1; }

int main() {
	freopen("campnou.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T; while (T--) {
		int N, Q; cin >> N >> Q; Tree T(N);
		for (int i = 1; i < N; i++) {
			int p; cin >> p; T.addEdge(--p, i);
		}
		
		LCA lca(T, 0); while (Q--) {
			int X, Y; cin >> X >> Y; if (--X == --Y) {
				ll res = choose2(N) - choose2(N - T.subSize[X]);
				for (auto& e : T.nodes[X]) 
					if(T.subSize[e] < T.subSize[X])
						res -= choose2(T.subSize[e]);
				cout << res << '\n'; continue;
			}
			if (lca.depth[X] > lca.depth[Y]) { swap(X, Y); }
			pair<int, int> L = lca.find(X, Y);
			if (L.first != X) { cout << T.subSize[X] * T.subSize[Y] << '\n'; continue; }
			cout << T.subSize[Y] * (N - T.subSize[L.second]) << '\n';
		}
	}

}