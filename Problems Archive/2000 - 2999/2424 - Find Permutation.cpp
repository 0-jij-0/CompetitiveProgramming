#include <bits/stdc++.h>
using namespace std;

struct Graph {
	vector<vector<int>> nodes; int N;
	vector<int> in;
	Graph(int _n) : N(_n), nodes(_n), in(_n) {}

	void addEdge(int u, int v) {
		in[v]++;
		nodes[u].emplace_back(v);
	}

	vector<int> uniqueTopologicalOrder() {
		queue<int> Q; vector<int> res;
		for (int i = 0; i < N; i++)
			if (!in[i]) Q.push(i);

		while (!Q.empty()) {
			if (Q.size() > 1) return {};
			int cur = Q.front(); Q.pop();
			res.push_back(cur);
			for (int& e : nodes[cur])
				if (!(--in[e])) Q.push(e);
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; Graph G(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		G.addEdge(--u, --v);
	}

	vector<int> res = G.uniqueTopologicalOrder();
	if (res.empty()) { cout << "No\n"; return 0; }
	cout << "Yes\n"; vector<int> P(n);
	for (int i = 0; i < n; i++) P[res[i]] = i + 1;
	for (auto& x : P) cout << x << ' '; cout << '\n';

}